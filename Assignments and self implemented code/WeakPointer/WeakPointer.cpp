
#include <iostream>
class printer {
    std::weak_ptr<int> m_pvalue{};
public:
    void setvalue(std::weak_ptr<int> p)
    {
        m_pvalue = p;
    }
    void print()
    {
        if (m_pvalue.expired())
        {
            std::cout << "resource is no longer available to use" << '\n';
            return;
        }
        auto sp = m_pvalue.lock();
        std::cout << "the value is : " << *sp << std::endl;
        std::cout << "ref count : " << sp.use_count() << std::endl;
    }
};
int main()
{
    printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p{new int{ num }};
    prn.setvalue(p);
    if (*p > 10)
    {
        p = nullptr;
    }
    prn.print();
}

