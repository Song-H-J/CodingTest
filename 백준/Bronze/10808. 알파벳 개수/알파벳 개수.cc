#include<iostream>
#include<vector>
#include<string>

using namespace std;

void countAlphabet(string& S, vector<int>& alpha)
{
    for (int i = 0; i < S.length(); i++) {
        alpha[abs('a'-S[i])]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> alph(26, 0);
    string S;
    cin >> S;
    countAlphabet(S, alph);
    for (auto iter = alph.begin(); iter != alph.end(); ++iter) {
        cout << *iter << ' ';
    }
    return 0;
}