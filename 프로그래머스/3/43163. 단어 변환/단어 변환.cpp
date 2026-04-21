#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define S first
#define N second

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    
    int n = words.size();
    bool vis[52] = {false};
    
    queue<pair<string,int>> Q;
    Q.push({begin, 0});
    
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        if (cur.S == target) {
            answer = cur.N;
            break;
        }
        
        for (int i = 0; i < cur.S.size(); i++) {
            string tmp = cur.S;
            for (char c = 'a'; c <= 'z'; c++) {
                tmp[i] = c;
                for (int j = 0; j < n; j++) {
                    if (vis[j] || tmp != words[j]) continue;
                    vis[j] = true;
                    Q.push({words[j], cur.N+1});
                }
            }
        }
    }
    return answer;
}