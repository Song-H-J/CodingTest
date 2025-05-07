#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string origin;
    string anagram;

    vector<int> alph(27,0);

    cin >> origin;
    for (char c : origin) {
        alph[abs('a' - c)]++;
    }

    cin >> anagram;
    for (char c : anagram) {
        alph[abs('a' - c)]--;        
    }

    int ans = 0;
    for (auto iter = alph.begin(); iter != alph.end(); ++iter) {
        if(*iter != 0)
            ans = ans + abs(*iter);
    }

    cout << ans;
    return 0;
}