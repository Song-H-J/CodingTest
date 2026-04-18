#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define X first
#define Y second

int map[27][27];
bool vis[27][27];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 정보 입력받기. 0 == 집없음 1 == 집있음
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
            map[i][j] = tmp[j] - '0';
    }

    int num = 0; // 단지 수
    vector<int> result; // 단지 넓이 벡터
    
    // 1인 지점 + 방문 안 한 지점마다 BFS 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || map[i][j] == 0) continue;
            num++;

            queue<pair<int, int>> Q;
            vis[i][j] = true;
            Q.push({i,j});

            int area = 0;

            while (!Q.empty()) {
                area++;
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || map[nx][ny] == 0) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
            result.push_back(area);
        }
    }
    sort(result.begin(), result.end());
    cout << num << '\n';
    for (int x : result)
        cout << x << '\n';
}