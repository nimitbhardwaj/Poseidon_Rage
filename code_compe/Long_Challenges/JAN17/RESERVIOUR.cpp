#include <iostream>
#include <vector>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<char> > V(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                char tmp;
                std::cin >> tmp;
                V[i].push_back(tmp);
            }
        }
        int kapa = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                switch(V[i][j])
                {
                    case 'B':
                        if(i != n - 1 && (V[i + 1][j] == 'W' || V[i + 1][j] == 'A'))
                            kapa = 1;
                        break;
                    case 'W':
                        if(j == 0 || j == m - 1)
                            kapa = 1;
                        break;
                    case 'A':
                        if(j == 0)
                        {
                            if(i == 0)
                            {
                                if(V[i][j + 1] == 'W')
                                    kapa = 1;
                            }
                            else
                                if(V[i][j + 1] == 'W' || V[i - 1][j] == 'W')
                                    kapa = 1;
                        }
                        else if(j == m - 1)
                        {
                            if(i == 0)
                            {
                                if(V[i][j - 1] == 'W')
                                    kapa = 1;
                            }
                            else
                                if(V[i][j - 1] == 'W' || V[i - 1][j] == 'W')
                                    kapa = 1;
                        }
                        else if(i == n - 1 || i == 0)
                        {
                            if(V[i][j + 1] == 'W' || V[i][j - 1] == 'W')
                                kapa = 1;
                        }
                        else
                        {
                            if(V[i - 1][j] == 'W' || V[i][j + 1] == 'W' || V[i][j - 1] == 'W')
                                kapa = 1;
                        }
                        break;
                }
                if(kapa == 1)
                    break;
            }
            if(kapa == 1)
                break;
        }
        if(kapa == 0)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
    return 0;
}
