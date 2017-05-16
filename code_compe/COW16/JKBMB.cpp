#include<iostream>
using namespace std;
int main()
{
    int n, m, **A;
    cin >> n >> m;
    A = new int*[n];
    for(int i = 0; i < n; i++)
    {
        A[i] = new int[m];
        for(int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << A[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
