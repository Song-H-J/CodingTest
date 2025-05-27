#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002]; // 시작점에서 그 노드까지의 거리
// 퍼져나가는 노드 탐색 거리를 토마토가 익는 날짜로 취급한다.

int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  // 탐색 대상을 입력받으며, 그 중 시작점이 될 노드들을 전부 큐에 집어넣는다.
  // 이로서 여러 공통 시작점에서 각 노드까지의 길이를 파악 가능하다.
  queue<pair<int,int> > Q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1) // 시작점이라면 Q에 푸시
        Q.push({i,j});
      if(board[i][j] == 0)
        dist[i][j] = -1;
    }
  }

  while(!Q.empty()){
    auto cur = Q.front();
    Q.pop();

    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny] >= 0) continue; // 위쪽에서 0이면 dist를 이미 -1로 바꿔놔서 여기 조건문에서 빠짐
      // 처음에 익은 토마토를 제외하곤 안 익은 토마토 뿐이니 조건에서 빠진 것이기도 함

      dist[nx][ny] = dist[cur.X][cur.Y]+1; // dist 갱신
      Q.push({nx,ny});
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(dist[i][j] == -1){ // 익지 않은 토마토가 있다면 error 리턴
        cout << -1;
        return 0;
      }
      ans = max(ans, dist[i][j]); // 모든 시작점에서 가장 거리가 먼, 즉 익는데 가장 오래걸리는 날을 체크해 cout
    }
  }
  cout << ans;
}