#include <iostream>
#ifdef __has_include
#	if __has_include(<windows.h>)
#		include <filesystem>
		namespace fs = std::filesystem ;
#	else
#		include <experimental/filesystem>
#		namespace fs = std::experimental::filesystem ;
#	endif
#endif

int main() {
	fs::path p{"C:"} ;
	
	std::cout << __cpp_inline_variables << std::endl; 
	std::cout << __cpp_capture_star_this << std::endl; 
}