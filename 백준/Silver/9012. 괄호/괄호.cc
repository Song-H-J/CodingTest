#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        stack<char> VPS;
        string S;
        cin >> S;

        for (char c : S) {
            if (c == '(') {
                VPS.push(c);
            } else if (c == ')') {
                if (!VPS.empty() && (VPS.top() == '(')) {
                    VPS.pop();
                } else {
                    VPS.push(c);
                    break;
                }
            }
        }

        if (VPS.empty()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}