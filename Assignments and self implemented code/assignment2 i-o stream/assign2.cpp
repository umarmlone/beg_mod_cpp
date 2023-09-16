\
#include <iostream>

int main()
{
    std::cout << "Hello World!\n" << 45 << " " << 8.2f << std::endl;
    int x=9;
    //std::cin >> x;
    std::cout << "u entered " << x << std::endl;
    
    char buff[512];
    std::cin.getline(buff, 500, '\n');
    std::cout << " YOUR NAME IS : " << buff << std::endl;
    return 0;
}

