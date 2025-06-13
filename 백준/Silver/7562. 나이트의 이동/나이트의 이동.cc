#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int map[302][302]; // 0 = 평범, 1 = knight
    int dist[302][302];
    int dx[8] = {-1, 1,-2, 2,-2,2,-1,1};
    int dy[8] = {-2,-2,-1,-1, 1,1, 2,2}; // knight 이동 구현
    
    int test_case;
    int n; // map n x n
    int knight_x, knight_y;
    int goal_x, goal_y;

    cin >> test_case;
    for (int i = 0; i < test_case; i++) {
        for (int i = 0; i < 302; i++) {
            for (int j = 0; j < 302; j++) {
                map[i][j] = 0;
                dist[i][j] = -1;
            }
        }
        cin >> n;
        cin >> knight_x >> knight_y;
        cin >> goal_x >> goal_y;
        if (knight_x == goal_x && knight_y == goal_y) {
            cout << 0 << '\n';
            continue;
        }

        map[goal_x][goal_y] = 1;

        queue<pair<int, int>> Q;
        dist[knight_x][knight_y] = 0;
        Q.push({knight_x,knight_y});

        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++) {
                int nx = dx[dir] + cur.X;
                int ny = dy[dir] + cur.Y;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (dist[nx][ny] >= 0) continue;
                if (map[nx][ny] == 1) {
                    while(!Q.empty()) {Q.pop();}
                    cout << dist[cur.X][cur.Y] + 1 << '\n';
                    break;
                } else {
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q.push({nx,ny});
                }
            }
        }

        
    }
    return 0;
}