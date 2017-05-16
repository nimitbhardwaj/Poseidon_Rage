#include<iostream>
#include<string>
using namespace std;
int sigOne(string &);
int sigOne_2(string &);
void DCR(string &);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2, s3, s1_, s2_, s3_;
        int flag = 0;
        int n, n1, n2, n3;
        cin >> s1 >> s2 >> s3 >> n;
        s2_ = s2, s3_ = s3, s1_ = s1;
        string dummy1(s1.size(), '1'), dummy2(s2.size(), '1'), dummy3(s3.size(), '1');
        string kapa1(s1.size(), '0'), kapa2(s2.size(), '0'), kapa3(s3.size(), '0');
        n3 = sigOne(s3) + 1;
        DCR(s2);
        n2 = n * (sigOne(s2) + 1);
        DCR(s1);
        n1 = sigOne(s1) + 1;
        s2 = s2_, s1 = s1_;
        if((s1 == dummy1 && s2 == dummy2 && s3 == dummy3) || (s1 == kapa1 && s2 == kapa2 && s3 == kapa3)) //07
        {
            n1 = 1, n2 = 0, n3 = 0;
        }
        else if(s1 == kapa1 && s2 == kapa2 && s3 != kapa3) //1
        {
            n1 = 0, n2 = 0, n3 = sigOne(s3) + 1;
        }
        else if(s1 == kapa1 && s2 != kapa2 && s3 == kapa3) //2
        {
            n3 = sigOne_2(s2) + 1;
            DCR(s2_);
            n2 = (n - 1) * (sigOne(s2_) + 1);
            n1 = 0;
        }
        else if(s1 != kapa1 && s2 == kapa2 && s3 == kapa3) //4
        {
            n1 = sigOne_2(s1) + 1;
            n2 = n3 = 0;
        }
        else if(s1 == kapa1 && s2 != kapa2 && s3 != kapa3) //3
        {
            n3 = sigOne(s3) + 1;
            DCR(s2_);
            n2 = (n) * (sigOne(s2_) + 1);
            n1 = 0;
            if(s2 == dummy2 && s3 == dummy3)
                n2 = n3 = 0, n1 = 1;
            if(s3 == dummy3 && s2 != dummy2)
            {
                n1 = 0;
                n3 = sigOne(s2) + 1;
                DCR(s2_);
                n2 = (n - 1) * (sigOne(s2_) + 1);

            }
        }
        else if(s1 != kapa1 && s2 == kapa2 && s3 != kapa3) //5
        {
            n3 = sigOne(s3) + 1;
            DCR(s1_);
            n1 = sigOne(s1_) + 1;
            n2 = 0;
        }
        else if(s1 != kapa1 && s2 != kapa2 && s3 == kapa3)//6
        {
            if(n == 1)
            {
                n3 = sigOne_2(s2) + 1;
                n2 = 0;
                DCR(s1);
                n1 = sigOne(s1) + 1;
            }
            else
            {
                n3 = sigOne_2(s2) + 1;
                n2 = (n - 1) * (sigOne(s2) + 1);
                DCR(s1_);
                n1 = sigOne(s1_) + 1;
            }
        }
        cout << n1 + n2 + n3 << endl;

    }
    return 0;
}

int sigOne(string &S)
{
    int res = 0, size = S.size(), i;
    i = size;
    while(S[--i] == '1')
        ;
    while(i >= 0)
    {
        if(S[i--] == '1')
            res++;
    }
    return res;
}

int sigOne_2(string &S)
{
    int res = 0;
    for(int i = 0; i < S.size(); i++)
        if(S[i] == '1')
            res++;
    return res;
}

void DCR(string &S)
{
    int size = S.size();
    for(int i = size - 1; i >= 0; i--)
    {
        if(S[i] == '1')
        {
            S[i] = '0';
            break;
        }
        else if(S[i] == '0')
        {
            S[i] = '1';
        }
    }
}
