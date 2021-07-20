#include <iostream>
#include <variant>
#include <string>
struct Number {
	int m_Num{} ;
	Number(int num): m_Num{num} {
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number() {
		std::cout << __FUNCSIG__ << std::endl;
	}
	~Number() {
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number(const Number& other) {
		m_Num = other.m_Num ;
		
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number(Number&& other) noexcept {
		m_Num = other.m_Num ;
		other.m_Num = 0 ;
		std::cout << __FUNCSIG__ << std::endl;
	}

	Number& operator=(const Number& other) {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other){
			return *this;
		}
		m_Num = other.m_Num ;
		
		return *this;
	}

	Number& operator=(Number&& other) noexcept {
		std::cout << __FUNCSIG__ << std::endl;
		if (this == &other)
			return *this;
		m_Num = other.m_Num ;
		other.m_Num = 0 ;
		
		return *this;
	}
		friend std::ostream& operator <<(std::ostream &out, const Number &n) {
		return out << n.m_Num ;
	}
};

struct Visitor {
	void operator()(const std::string &s)const {
		std::cout << "string:" <<  s << std::endl; 
		
	}
	void operator()(int x)const {
		std::cout << "int:" << x << std::endl ;
	}
	void operator()(const Number &n)const {
		std::cout << "Number:" << n << std::endl; 
		
	}
};
struct Modifier {
	void operator()( std::string &s)const {
		s += " modified string" ;
	}
	void operator()(int& x)const {
		x += 1000 ;
	}
	void operator()( Number &n)const {
		n = 999 ;
	}
};
int main() {
	using namespace std::string_literals ;
	try {
		std::variant<std::string, int, Number> v{ 7 };
	/*	std::visit(Modifier{}, v) ;
		std::visit(Visitor{}, v) ;
		
		v = "C++" ;
		std::visit(Modifier{}, v) ;
		std::visit(Visitor{}, v) ;

		v.emplace<Number>(100) ;
		std::visit(Modifier{}, v) ;
		std::visit(Visitor{}, v) ;*/

		v = "using lambda" ;

		auto visitor = [](auto &x) {
			using T = std::decay_t<decltype(x)> ;
			if constexpr (std::is_same_v<T, int>){
				std::cout << "int : " << x << std::endl; 
			}else if constexpr (std::is_same_v<T, std::string>){
				std::cout << "string:" << x << std::endl; 
			}else if constexpr(std::is_same_v<T, Number>){
				std::cout << "Number:" << x << std::endl ;
			}
		} ;
		std::visit(visitor,v) ;

		v = 555 ;
		std::visit(visitor,v) ;

		v = Number{3} ;
		std::visit(visitor,v) ;
		
		
		//v = Number{1} ;
		//v.emplace<Number>(100) ;
		//std::get<Number>(v) = 100 ;
		/*auto val = std::get<int>(v);
		val = std::get<1>(v);

		auto activeIndex = v.index();

		auto p = std::get_if<std::string>(&v);
		if (p == nullptr) {
			std::cout << "Not active\n";
		}
		else {
			std::cout << *p << std::endl;
		}*/

	}
	catch (std::exception& ex) {
		std::cout << "Exception:" << ex.what() << std::endl;
	}
}
