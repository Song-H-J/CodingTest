#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

#define X first
#define Y second

string board[102]; // 탐색 대상 행렬
int dist[102][102]; // 각 노드의 탐색 시작점으로부터의 거리를 저장할 행렬
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 탐색 대상 행렬 입력받기
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> board[i];
  
  // fill을 활용한 행렬 초기화
  for(int i = 0; i < n; i++)
    fill(dist[i],dist[i]+m,-1);
  
  // 탐색 준비
  queue<pair<int,int> > Q;
  Q.push({0,0});
  dist[0][0] = 0;

  // 탐색 시작. 미로 1회 탐색이므로 for 이중 루프 필요없음
  while(!Q.empty()){
    auto cur = Q.front();
    Q.pop();

    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // 1이면 진행가능한 칸, 0 = 불가능, -1 = 범위 밖

      /* 미로 시작점에서부터의 거리를 측정해 추가한다.
       * 시작점이 0이라면 다음 탐색 대상은 0 + 1의 거리를 갖는다.
       * 다음 탐색점의 상하좌우는 당연히 1 + 1, 즉 시작점에서 2의 거리를 갖는다.
       * 이를 반복하면 미로 끝점에서 한 칸 앞의 노드까지 탐색을 진행하고,
       * 그 노드에서 미로 끝점을 탐색해 큐에 추가한 후 최단 거리를 계산한다.
       * 그 후 미로 끝점에서 탐색을 진행하면 탐색이 불가능해 큐가 비게 되고 while 루프 종료
       */
      dist[nx][ny] = dist[cur.X][cur.Y]+1;

      Q.push({nx,ny});
    }
  }
  // 문제 조건 상 끝점은 n, m으로 고정
  // 칸을 셀 때 시작점까지 거리 1로 쳐야 함
  cout << dist[n-1][m-1]+1; // 문제의 특성상 거리+1이 정답, 시작점 포함 지나간 칸의 수
}