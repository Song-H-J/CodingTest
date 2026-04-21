#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<int> Q;
    Q.push(0);
    
    for (int x : numbers) {
        int n = Q.size();
        
        for (int i = 0; i < n; i++) {
            auto cur = Q.front();
            Q.pop();
        
            for (int x : {cur+x, cur-x})
                Q.push(x);
        }
    }
    
    while (!Q.empty()) {
        if (Q.front() == target) answer++;
        Q.pop();
    }
    
    return answer;
}