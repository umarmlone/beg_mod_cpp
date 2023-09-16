

#include <iostream>
#include "Integer.h"
#include <memory>


Integer* GetPointer(int value)
{
    Integer* ptr = new Integer{ value };
    return ptr;

}

void DisplayPtr(Integer *obj)
{
    if (!obj)
    {
        std::cout << "a7a l dnya bazet" << std::endl;
        return;
    }
    std::cout << obj->GetValue() << std::endl;
}

void store(std::unique_ptr<Integer>& ptr)
{
    std::cout << "wrote successfully : " << ptr->GetValue()  << std::endl;
}
void operate(int value)
{
    //Integer* ptr = GetPointer(value);
    std::unique_ptr<Integer> ptr{GetPointer(value)};
    //DisplayPtr(ptr);
    DisplayPtr(ptr.get());

    if (ptr == nullptr)
    {
       // ptr = new Integer{ value };            we cant use = operator with the unique pointer so we need to use a function called reset to assign a new value to the raw pointer of the unique pointer
        ptr.reset(new Integer{ value });
    }
    ptr->SetValue(100);
    DisplayPtr(ptr.get());
    //delete ptr;          we do not need delete when we use smart pointers.
    ptr = nullptr;
    ptr.reset(new Integer{});
    *ptr = __LINE__;
    DisplayPtr(ptr.get());  //or we can use the move function to move the ptr not copying it or we can pass it by reference as we did .
    // delete ptr;
    store(ptr);
    
}
int main()
{
    std::cout << "Hello World!\n";
    operate(145);
}
