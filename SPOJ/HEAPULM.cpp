#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

using Node = pair<string, int>;

void buildHeap(vector<Node> &);
void heapify(vector<Node> &, int);
inline int left(int n) { return 2 * n + 1; }
inline int right(int n) { return 2 * n + 2; }
inline bool comp(const pair<Node, int> &a, const pair<Node, int> &b)
{ return a.first.second < b.first.second; }
string printHeap(vector<Node> &, int);

int main()
{
    int n;
    cin >> n;
    if(n == 0)
        exit(EXIT_SUCCESS);
    vector<Node> V;
    for(int i = 0; i < n; i++)
    {
        string S;
        cin >> S;
        int a = S.find('/');
        string label = string(S, 0, a);
        int num = stoi(string(S, a + 1));
        V.push_back(make_pair(label, num));
    }
    buildHeap(V);
    cout << printHeap(V, 0) << endl;
    return 0;
}

void buildHeap(vector<Node> &V)
{
    int n = (V.size()) / 2 - 1;
    for(int i = n; i >= 0; i--)
        heapify(V, i);
}

void heapify(vector<Node> & V, int n)
{
    pair<Node, int> kapa = make_pair(V[n], n);
    if(left(n) >= V.size() && right(n) >= V.size())
        return;
    if(left(n) < V.size())
        kapa = max(kapa, make_pair(V[left(n)], left(n)), comp);
    if(right(n) < V.size())
        kapa = max(kapa, make_pair(V[right(n)], right(n)), comp);
    if(kapa.second == n)
        return;
    else
    {
        swap(V[n], V[kapa.second]);
        heapify(V, kapa.second);
    }
}


string printHeap(vector<Node> &V, int i)
{
    string S1, S2;
    if(left(i) >= V.size())
        S1 = "";
    else
        S1 = printHeap(V, left(i));
    if(right(i) >= V.size())
        S2 = "";
    else
        S2 = printHeap(V, right(i));
    return string('(' + S1 + to_string(V[i].second) + '/' + V[i].first + S2 + ')');
}
