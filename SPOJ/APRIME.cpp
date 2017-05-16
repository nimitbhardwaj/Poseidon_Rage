#include <cstdio>
#include <vector>

using namespace std;

bool calcSeq(vector<int> &V, int d, int a, int b, int n, vector<bool> &);
bool isValid(int, int, vector<int> &);
bool isPrime(int);

char prima[1000000] = {0};

int main()
{
    int a, b, d;
    scanf("%d %d %d", &a, &b, &d);
    while(a != 0 && b != 0 && d != 0)
    {
        vector<int> outputSeq;
        vector<bool> visited(b - a + 1, false);
        bool res = calcSeq(outputSeq, d, a, b, b - a + 1, visited);
        if(res == true)
        {
            for(int i = 0; i < outputSeq.size(); i++)
            {
                printf("%d", outputSeq[i]);
                if(i == outputSeq.size() - 1)
                    putchar('\n');
                else
                    putchar(',');
            }
        }
        else
            printf("No anti-prime sequence exists.\n");;
        scanf("%d %d %d", &a, &b, &d);
    }
    return 0;
}

bool calcSeq(vector<int> &V, int d, int a, int b, int n, vector<bool> &visited)
{
    if(n == 0)
    {
        return true;
    }
    for(int i = a; i <= b; i++)
    {
        bool kapa = true;
        for(int j = 2; j <= d; j++)
        {
            kapa = kapa && isValid(i, j, V);
            if(kapa == false)
                break;
        }
        if(kapa && visited[i - a] == false)
        {
            visited[i - a] = true;
            V.push_back(i);
            if(calcSeq(V, d, a, b, n - 1, visited))
                return true;
            V.pop_back();
            visited[i - a] = false;
        }
    }
    return false;
}

bool isValid(int a, int d, vector<int> &V)
{
    if(V.size() == d - 1)
    {
        int sum = 0;
        for(int i = 0; i < V.size(); i++)
            sum += V[i];
        sum += a;
        if(prima[sum] == 0)
        {
            if(isPrime(sum))
                prima[sum] = 1;
            else
                prima[sum] = -1;
        }
        if(prima[sum] == 1)
            return false;
        else if(prima[sum] == -1)
            return true;
    }
    else if(V.size() >= d)
    {
        int sum = 0;
        for(int i = V.size() - 1; i >= V.size() - d + 1; i--)
            sum += V[i];
        sum += a;
        if(isPrime(sum) == true)
            return false;
        else
            return true;
    }
    return true;
}

bool isPrime(int a)
{
    if(a == 1)
        return false;
    if(a == 2 || a == 3)
        return true;
    for(int i = 2; i * i <= a + 5; i++)
    {
        if(a % i == 0)
            return false;
    }
    return true;
}
