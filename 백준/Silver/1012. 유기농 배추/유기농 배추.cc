#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int repeat;
    cin >> repeat;

    int dx[4] = {1, 0 , -1 ,0};
    int dy[4] = {0, 1 , 0, -1}; // 네 방향
    
    for (int rp = 0; rp < repeat; rp++)
    {
        int n, m;
        cin >> m >> n;
        int pos;
        cin >> pos;

        int map[52][52];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                map[i][j] = 0;

        bool vis[52][52];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j] = false;

        int x, y;
        for (int i = 0; i < pos; i++) {
            cin >> x >> y;
            map[y][x] = 1;
        }

        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] || map[i][j] != 1) continue;
                num++;
                queue<pair<int, int>> Q;
                vis[i][j] = true;
                Q.push({i,j});

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;

                        if (nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
                        if (vis[nx][ny] || map[nx][ny] != 1) continue;
                        vis[nx][ny] = true;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout << num << '\n'; 
    }
    return 0;
}