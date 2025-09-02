#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    int cnt = 0;

    stack<char> ab;
    for (int i = 0; i < n; i++) {
        while (!ab.empty()) ab.pop();
        cin >> s;
        for (char c : s) {
            if (ab.empty()) {
                ab.push(c);
            } else if (c == 'A') {
                if (ab.top() == 'A') { ab.pop(); continue; }
                else { ab.push(c); continue; }
            } else if (c == 'B') {
                if (ab.top() == 'B') { ab.pop(); continue; }
                else { ab.push(c); continue; }
            }
        }
        if (ab.empty()) cnt++;
    }

    cout << cnt;
    return 0;
}