#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int s, g;
    
    if(a==b) {answer = a; return answer;}
    
    else if (a>b) {s=b; g=a;}
    else if (a<b) {s=a; g=b;}
    answer = 0;
    for(s; s<=g; s++){
        answer += s;   
    }
    return answer;
}