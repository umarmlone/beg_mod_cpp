#include <iostream>

void print_dynamicMemory_allocation_integer1()
{
    int* ptr = new int(67);
    std::cout << *(ptr) << std::endl;
    *(ptr) = 31;
    std::cout << *(ptr) << std::endl;
    delete ptr;
}

void print_dynamicMemory_allocation_array()
{
    int* ptr1 = new int[20];
    for (int i = 1; i <= 20; i++)
    {
        ptr1[i-1] = i;
    }
    for (int i = 0; i < 20; i++)
    {
        std::cout<< ptr1[i] <<std::endl;
    }
    delete[] ptr1;
}
void print_dynamicMemory_allocation_2array()
{
    int* ptr1 = new int[3];
    for (int i = 1; i <= 3; i++)
    {
        ptr1[i - 1] = i;
    }
    int* ptr2 = new int[3];
    for (int i = 1; i <= 3; i++)
    {
        ptr2[i - 1] = i+3;
    }
    int** Pdata = new int* [2];
    Pdata[0] = ptr1;
    Pdata[1] = ptr2;
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << Pdata[i][j] << " ";

        }
        std::cout << "\n";
    }

    delete[] ptr1;
    delete[] ptr2;
    delete[] Pdata;

}

int main()
{
    std::cout << "Hello World!\n";
    print_dynamicMemory_allocation_2array();
}

