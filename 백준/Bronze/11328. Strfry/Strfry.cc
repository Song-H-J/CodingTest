#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string origin;
    string anagram;

    for (int i = 0; i < N; i++) {
        vector<int> alph(26,0);
        
        cin >> origin;
        for (char c : origin) {
            alph[abs('a' - c)]++;
        }

        cin >> anagram;
        for (char c : anagram) {
            alph[abs('a' - c)]--;        
        }

        //auto chk_iter =  max_element(alph.begin(), alph.end()); -일수도 있음
        bool chk = all_of(alph.begin(), alph.end(), [](int x){return x==0;});
        if (!chk) {
            cout << "Impossible" << '\n';
        } else {
            cout << "Possible" << '\n';
        }
    }

    return 0;
}