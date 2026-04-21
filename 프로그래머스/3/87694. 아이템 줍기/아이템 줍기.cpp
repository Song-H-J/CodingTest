#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    int map[104][104]; // 2x 스케일링
    for (int i = 0; i < 104; i++)
        for (int j = 0; j < 104; j++)
            map[i][j] = 0;
    
    int dist[104][104];
    for (int i = 0; i < 104; i++)
        for (int j = 0; j < 104; j++)
            dist[i][j] = -1;
    
    // map에 사각형 테두리 경로 넣기 (테두리 == 1)
    // 2x 스케일링 잊지 말 것.
    // 테두리 포함 1로
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                map[i][j] = 1;
    }
    
    // 테두리 빼고 0으로
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int i = x1+1; i < x2; i++)
            for (int j = y1+1; j < y2; j++)
                map[i][j] = 0;
    }
    
    queue<pair<int, int>> Q;
    Q.push({characterX * 2, characterY * 2});
    dist[characterX * 2][characterY * 2] = 0;
    
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        if (cur.X == itemX * 2 && cur.Y == itemY * 2) {
            answer = dist[cur.X][cur.Y] / 2;
            break;
        }      
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= 104 || ny < 0 || ny >= 104) continue;
            if (dist[nx][ny] != -1 || map[nx][ny] == 0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    return answer;
}