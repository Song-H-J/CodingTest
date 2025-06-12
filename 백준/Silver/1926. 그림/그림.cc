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

    int map[502][502];  // 탐색 대상
    int mx = 0; // 그림 최대 넓이
    int num = 0; // 그림의 갯수
    int n, m; // 행, 열
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    /* -----------------BFS----------------- */
    bool vis[502][502]; // 탐색 여부
    int dx[4] = {1, 0 , -1 ,0};
    int dy[4] = {0, 1 , 0, -1}; // 네 방향

    for (int i = 0; i < n; i++) { // map 순회하며 시작점이 될 수 있는 노드 탐색
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 || vis[i][j]) continue; // 색 없거나, 방문했으면 pass
            num++; // 새 노드 탐색 시작

            queue<pair<int, int>> Q;
            vis[i][j] = 1; // 시작 노드 방문 true
            Q.push({i,j}); // 시작 노드 Q에 push하면 탐색 준비 끝

            int area = 0; // 시작 면적은 0
            
            while(!Q.empty()) {
                // Q에 원소가 push & pop되면 시작점과 이어진 노드들이 조건을 만족하여
                // 그 노드의 상하좌우를 검사했다는 의미이므로 area++
                area++;

                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >=m) continue; // 경계 넘어가거나
                    if (vis[nx][ny] || map[nx][ny] != 1) continue; // 방문했거나, 유효 노드가 아니라면 pass
                    // 맞다면
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
                mx = (area > mx) ? area : mx;
            }
        }
    }
    cout << num << '\n' << mx;
    return 0;
}