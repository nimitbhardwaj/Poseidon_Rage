#include<iostream>
#include<cstring>
#include<string>
const int mod = 1e9 + 7;
void KMP(const std::string &S, const std::string &T, int *);
int *__lookUpTable(const std::string &T);
int dynamic(const std::string &, const std::string &, int *, int);
int next(int, int, int*, int);
int D_Array[400000];
int *nex;
int len;
int main()
{
    int t;
    int A[400000];
    std::cin >> t;
    while(t--)
    {
        std::string S, T;
        std::cin >> S >> T;
        nex = new int[S.size()]();
        KMP(S, T, A);
        //std::cout << A[0] << std::endl;
        len = T.size();
        std::cout << dynamic(S, T, A, 1) - 1<< std::endl;
        //std::cout << prev(A[0], A, T.size()) << std::endl;
        memset(D_Array, 0, sizeof(D_Array));
        delete[] nex;
    }
    return 0;
}
 
void KMP(const std::string &S, const std::string &T, int *A)
{
    int sz = S.size(), szt = T.size();
    int *B = __lookUpTable(T);
    A[0] = 0;
    int i = 0, j = 0;
    while(i < sz)
    {
        if(T[j] == S[i])
            i++, j++;
        if(j == szt)
        {
            A[0]++;
            A[A[0]] = i - j;
            j = B[j - 1];
        }
        else if(i < sz && T[j] != S[i])
        {
            if(j != 0)
                j = B[j - 1];
            else
                i++;
        }
    }
    delete[] B;
    return ;
}
 
int *__lookUpTable(const std::string &T)
{
    int sz = T.size();
    int *B = new int[sz]();
    int j = 0;
    B[0] = 0;
    for(int i = 1; i < sz; i++)
    {
        while(1)
        {
            if(T[j] == T[i])
            {
                B[i] = j + 1;
                j++;
                break;
            }
            else if(T[j] != T[i] && j != 0)
            {
                j = B[j - 1];
            }
            else if(T[j] != T[i] && j == 0)
            {
                break;
            }
        }
    }
    return B;
}
 
int dynamic(const std::string &S, const std::string &T, int *A, int n)
{
    if(n == A[0] + 1)
        return 1;
    int a = next(1, A[0], A, A[n] + len); //jump
    //std::cout << "next of " << n << " is " << a << std::endl;
    if(D_Array[n + 1] == 0)
        D_Array[n + 1] = dynamic(S, T, A, n + 1);
    if(D_Array[a] == 0)
        D_Array[a] = dynamic(S, T, A, a);
    return (D_Array[n + 1] + D_Array[a]) % mod;
}
int next(int n, int l, int *A, int val)
{
    //for(int i = n + 1; i <= A[0]; i++)
    //{
        //if(A[n] + len <= A[i])
            //return i;
    //}
    //return A[0] + 1;
    //std::cout << n << ' ' << l << std::endl;
    int a = A[0];
    if(val > A[a])
        return A[0] + 1;
    if(n > l)
        return A[0] + 1;
    if(l - n == 1)
        return l;
    int mid =  (n + l) / 2;
    if(A[mid] > val)
        next(n, mid, A, val);
    else if(A[mid] < val)
        next(mid, l, A, val);
    else if(A[mid] == val)
        return mid;
}
