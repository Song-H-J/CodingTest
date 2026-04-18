#include <vector>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    int dist[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = -1;
    
    queue<pair<int, int>> Q;
    dist[0][0] = 1; // 1,1 보정. 첫 시작칸도 cnt 포함.
    Q.push({0,0}); // 상대 위치는 n-1, m-1
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1 || maps[nx][ny] == 0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }  
    }
    
    answer = dist[n-1][m-1];
    return answer;
}