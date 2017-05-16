#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string S;
    cin >> S;
    S[0] = toupper(S[0]);
    cout << S << endl;
    return 0;
}
