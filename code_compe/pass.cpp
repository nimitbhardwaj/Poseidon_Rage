#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::string str;
        std::cin >> str;
        int mark;
        std::cin >> mark;
        size_t pos = -1;
        int ck = 0;
        while((pos = str.find('e', pos + 1)) != std::string::npos)
            ck++;
        std::cout << ck % (mark + 1) << std::endl;
    }
    return 0;
}
