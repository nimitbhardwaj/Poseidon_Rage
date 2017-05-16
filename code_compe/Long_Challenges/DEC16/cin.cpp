#include<iostream>
int main()
{
    char c[199];
    std::cin.get(c, 11);
    //std::cin.getline(c, 11);
    std::cin >> c[111];
    std::cout << c << std::endl;
}
