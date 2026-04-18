#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int map[102][102];
bool vis[102][102];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int max_height = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            max_height = max(max_height, map[i][j]);
        }
    }

    int max_num = 0;
    // 시작점이 여러 개인 BFS + sink 1루프
    for (int sink = 0; sink <= max_height; sink++) { // 비 높이
        int num = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                vis[i][j] = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] || map[i][j] <= sink) continue;
                num++;

                queue<pair<int, int>> Q;
                vis[i][j] = true;
                Q.push({i, j});

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
                        if (vis[nx][ny] || map[nx][ny] <= sink) continue;

                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        max_num = max(num, max_num);
    }
    cout << max_num;
    return 0;
}