#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int sign = 1;
    
    if (s[0]=='-') {sign = -1; s.erase(s.begin());}
    else if (s[0]=='+') {sign = 1; s.erase(s.begin());}
    
    for(int i = 0; i<s.length(); i++){
        answer = answer*10 + (s[i]-'0');
    }
    answer = answer*sign;
    return answer;
}