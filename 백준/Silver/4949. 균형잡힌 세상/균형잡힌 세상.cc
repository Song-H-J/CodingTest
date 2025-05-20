#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    
    
    while (true) {
        stack<char> chk;
        bool isOk = true;
        
        getline(cin, s);
        if (s == ".")
            break;
        for (char c : s) {
            if (c == '(' || c == '[') {
                chk.push(c);
            } else if (!chk.empty() && c == ')') {
                if (chk.top() == '(') {
                    chk.pop();
                } else {
                    isOk = false;
                    break;
                }
            } else if (!chk.empty() && c == ']') {
                if (chk.top() == '[') {
                    chk.pop();
                } else {
                    isOk = false;
                    break;
                }
            } else if (chk.empty() && (c == ')' || c == ']')) {
                isOk = false;
                break;
            }
        }
        if (isOk && chk.empty()) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    } 
 
    return 0;
}