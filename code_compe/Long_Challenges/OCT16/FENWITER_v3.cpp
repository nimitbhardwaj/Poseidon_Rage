#include<iostream>
#include<string>
using namespace std;
int noOnes(const string &);
int iniOnes(const string &);
bool finalCheck(const string &);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2, s3;
        int n;
        cin >> s1 >> s2 >> s3 >> n;
        string dummy3(s3.size(), '1'), dummy2(s2.size(), '1');
        int n1 = noOnes(s1);
        int n2 = n * noOnes(s2);
        int n3 = noOnes(s3);
        int in1 = iniOnes(s1);
        int in2 = iniOnes(s2);
        int in3 = iniOnes(s3);
        n3 -= in3;
        if(s3 == dummy3 && s2 == dummy2 && finalCheck(s1))
            n1 = n2 = n3 = 0;
        if(s3 == dummy3 && s2 == dummy2 && !finalCheck(s1))
        {
            n3 = n2 = 0;
            n1 -= in1;
        }
        if(s3 == dummy3 && s2 != dummy2)
        {
            n3 = 0;
            n2 = n2 - in2;
        }
        //cout << in3 << endl;
        cout << n1 + n2 + n3 + 1 << endl;
    }
    return 0;
}

int noOnes(const string &S)
{
    int s = S.size(), res = 0;
    for(auto i = 0; i < s; i++)
        if(S[i] == '1')
            res++;
    return res;
}

int iniOnes(const string &S)
{
    int s = S.size(), res = 0;
    for(auto i = s - 1; i >= 0; i--)
        if(S[i] == '1')
            res++;
        else
            return res;
    return res;
}
bool finalCheck(const string &S)
{
    int s = S.size();
    bool ck = false;
    for(auto i = s - 1; i >= 0; i--)
    {
        if(ck == false && S[i] == '0')
        {
            ck = true;
        }
        if(S[i] == '1' && ck == true)
            return false;
    }
    return true;
}
