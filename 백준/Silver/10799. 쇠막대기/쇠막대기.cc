#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> beam;
    char prv;
    int ans = 0;
    
    for (char c : s) {
        if (beam.empty()) {
            beam.push(c);
            prv = c;
            continue;
        } else if (c == '(') {
            beam.push(c);
            prv = c;
            continue;
        } else if (c == ')') {
            if (prv == '(') {
                beam.pop();
                ans = ans + beam.size();
                prv = c;
                continue;
            } else if (prv == ')') {
                beam.pop();
                ans++;
                prv = c;
                continue;
            }
        } 
    }

    cout << ans;    
    return 0;
}