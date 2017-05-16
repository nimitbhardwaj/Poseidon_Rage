#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
  //  scanf("%d", &t);
    while(t--)
    {
        int n, m; 
        scanf("%d %d", &n, &m);
        
        vector<int> V(n + 1);
        vector<int> A(n + 1);
        vector<int> dummy(n + 1);
        
        A[0] = 0;//initilise all 0
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &V[i]);
            A[i + 1] = A[i] + V[i];//summed all 
        }
        
        stack<int> S;//filled stack with m
        int a;
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &a);
            S.push(a);
        }
        
        int napa = 0, kapa = 0;
        kapa = S.top();
        for(int i = 0; i + kapa < n + 1; i++)
        {
            dummy[i] = A[i + kapa] - A[i];
        }
        napa = kapa;
            S.pop();
                
        while(!S.empty())
        {
            kapa = S.top();
            for(int i = 0; i + kapa < n + 1; i++)
            {
                dummy[i] = A[i + kapa] - A[i] - dummy[max_element(dummy.begin() + i + 1, dummy.begin() + i + kapa - napa) - dummy.begin()];
            }
            napa = kapa;
            S.pop();
        }
        printf("%d\n", dummy[max_element(dummy.begin(), dummy.begin() + n - kapa + 1) - dummy.begin()]);
    }
    return 0;
}
