#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flake
{
    vector<int> A;
    Flake()
        :A(vector<int>(6, 0)){}
    void makeSymFlake();
    friend bool operator<(const Flake &, const Flake &);
    friend bool operator==(const Flake &, const Flake &);
    friend bool operator!=(const Flake &, const Flake &);
};


int main()
{
    int n;
    cin >> n;
    vector<Flake> V;
    for(int i = 0; i < n; i++)
    {
        Flake tmp;
        cin >> tmp.A[0] >> tmp.A[1] >> tmp.A[2] >> tmp.A[3] >> tmp.A[4] >> tmp.A[5];
        tmp.makeSymFlake();
        V.push_back(tmp);
    }
    sort(V.begin(), V.end());
    bool status = true;
    for(int i = 0; i < V.size() - 1; i++)
    {
        if(V[i] == V[i + 1])
        {
            status = false;
            break;
        }
    }
    if(status == true)
        cout << "No two snowflakes are alike." << endl;
    else
        cout << "Twin snowflakes found." << endl;
    return 0;
}

void Flake::makeSymFlake()
{
    Flake &f = *this;
    int mini_index = min_element(f.A.begin(), f.A.end()) - f.A.begin();
    Flake ret;
    int dir = 1;
    if(f.A[(mini_index + 1) % 6] >= f.A[(mini_index - 1 + 6) % 6])
        dir = -1;
    if(dir == 1)
        for(int i = 0, j = mini_index; i < 6; i++, j = (j + 1) % 6)
            ret.A[i] = f.A[j];
    else
        for(int i = 0, j = mini_index; i < 6; i++, j = (j - 1 + 6) % 6)
            ret.A[i] = f.A[j];
    f = ret;
}

bool operator<(const Flake &a, const Flake &b)
{
    for(int i = 0; i < 6; i++)
    {
        if(a.A[i] < b.A[i])
            return true;
        else if(a.A[i] == b.A[i])
            continue;
        else
            return false;
    }
    return false;
}

bool operator==(const Flake &a, const Flake &b)
{
    for(int i = 0; i < 6; i++)
    {
        if(a.A[i] != b.A[i])
            return false;
    }
    return true;
}

bool operator!=(const Flake &a, const Flake &b)
{
    return !operator==(a, b);
}
