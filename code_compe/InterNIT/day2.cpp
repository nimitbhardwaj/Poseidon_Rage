#include <iostream>
#include <vector>
#include <string>

int main()
{
    
    int n, q;
    std::string S;
    std::vector<int> alpha(26, 0);
    std::cin >> n >> q;
    //std::cin.get();
    std::cin >> S;
    for(int i = 0; i < n; i++)
    {
        char c;
        c = S[i];
        alpha[c - 'A'] += 1;
    }
    for(int i = 0; i < q; i++)
    {
        int type;
        std::cin >> type;
        if(type == 1)
        {
            int index;
            char c;
            std::cin >> index >> c;
            alpha[S[index - 1] - 'A'] -= 1;
            alpha[c - 'A'] += 1;
            S[index - 1] = c;
            //std::cout << S << std::endl;
            //for(int i = 0; i < 26; i++)
                //if(alpha[i] != 0)
                    //std::cout << char('A' + i) << alpha[i] << std::endl;
        }
        else
        {
            int index, i, sum = 0, tmp = 0;
            std::cin >> index;
            index--;
            for(i = 0; i < 26; i++)
            {
                if(alpha[i] == 0)
                    continue;
                else
                    sum += alpha[i], tmp = i;
                if(sum > index)
                    break;
            }
            //std::cout << tmp << std::endl;
            std::cout << char('A' + tmp) << std::endl;
        }
    }
    return 0;
}
