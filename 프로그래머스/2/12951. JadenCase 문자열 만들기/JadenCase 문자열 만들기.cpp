#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool isFirst = true;
    for (char c : s) {
        if (c == ' ') {
            answer += c;
            isFirst = true;
        } else if ('0' <= c && c <= '9') {
            answer += c;
            isFirst = (isFirst) ? false : isFirst;
        } else if ('A' <= c && c <= 'Z') {
            if (isFirst) {
                answer += c;
                isFirst = false;
            } else {
                answer += (c - 'A' + 'a');
            }
        } else {
            if (isFirst) {
                answer += (c - 'a' + 'A');
                isFirst = false;
            } else {
                answer += c;
            }
        }
    }
    return answer;
}