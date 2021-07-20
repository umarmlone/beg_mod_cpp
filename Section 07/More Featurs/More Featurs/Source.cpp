#include <cstdlib>
#include <iostream>
#include <memory>
#pragma region Deleters
struct Free {
	void operator()(int *p) {
		free(p) ;
		std::cout << "pointer freed\n" ;
	}
};
void MallocFree(int* p) {
	free(p);
	std::cout << "pointer freed\n";
}
void UniquePtrDeleters() {
	//std::unique_ptr<int, Free> p {(int*) malloc(4), Free{}} ;
	std::unique_ptr<int, void (*)(int *)> p {(int*) malloc(4), MallocFree} ;
	*p = 100 ;
	std::cout << *p << '\n' ;
	//free(p) ;
}

void SharedPtrDeleters() {
	std::shared_ptr<int> p {(int*) malloc(4), Free{}} ;
	//std::shared_ptr<int> p {(int*) malloc(4), MallocFree} ;
	*p = 100 ;
	std::cout << *p << '\n' ;
	//free(p) ;
}
#pragma endregion

void DynArray() {
	//std::unique_ptr<int[]> p{new int[5]{1,2,3,4,5}} ;

	//Support added in C++17 for shared_ptr
	std::shared_ptr<int[]> p{new int[5]{1,2,3,4,5}} ;
	p[0] = 10 ;
}

class Point {
public:
	Point(int x,int y) {
		
	}
};
int main() {
	//std::unique_ptr<int> p{new int{5}} ;
	{
		auto p = std::make_unique<int>(5) ;
		auto pt = std::make_unique<Point>(3,5) ;

		auto pArr = std::make_unique<int[]>(5) ;
		pArr[0] = 0 ;
	}

	{
		auto p = std::make_shared<int>(5) ;
		auto pt = std::make_shared<Point>(3,5) ;

		auto pArr = std::make_shared<int[]>(5) ;
		pArr[0] = 0 ;
	}
	
}