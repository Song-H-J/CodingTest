#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> checker;
    
    for (char c : s) {
        if (checker.empty()) {
            if (c == '(') checker.push(c);
            else return false;
        } else {
            if (c == '(') checker.push(c);
            else { // case ')'
                if (checker.top() == '(') checker.pop();
                else return false;
            }
        }
    }
    answer = (checker.empty()) ? true : false;
    

    return answer;
}