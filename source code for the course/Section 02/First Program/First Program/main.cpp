//This is a single line comment

/*
This is a 
multi line comment
*/


#include <type_traits>
#include <iostream>
enum e1{} ;
enum class e2{};
 
int main() {
    bool e1_type = std::is_same<
	    int
	    ,typename std::underlying_type<e1>::type
    >::value; 
 
    bool e2_type = std::is_same<
        int
       ,typename std::underlying_type<e2>::type
    >::value;
 
    std::cout
    << "underlying type for 'e1' is " << (e1_type?"int":"non-int") << '\n'
    << "underlying type for 'e2' is " << (e2_type?"int":"non-int") << '\n';
}
 
