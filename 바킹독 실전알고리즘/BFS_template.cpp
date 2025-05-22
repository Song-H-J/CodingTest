#include<iostream>
#include<queue>
#include<pair>

#define X fisrt
#define Y second // pair의 first, second를 축약

using namespace std;

void BFS(int n, int m, int target[])
{
    bool visit[n][m]; // 탐색 여부를 저장
    int dx = {1,0,-1,0};
    int dy = {0,1,0,-1}; // 하우상좌 순

    queue<pair<int, int>> Q; // 탐색 수행할 타겟들
    visit[0][0] = true; // 시작 지점은 탐색 완료로 설정
    Q.push({0,0}); // 큐에 시작 지점 (0,0) 삽입

    while(!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
        
        // 탐색 중 취해야 하는 행동을 아랫줄에 작성
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        //

        for(int dir = 0; dir < 4; dir++){ // 타겟의 하우상좌 칸을 체크
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(visit[nx][ny] || target[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            visit[nx][ny] = true; // (nx, ny)를 방문했다고 명시
            Q.push({nx,ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[502][502] =
        {{1,1,1,0,1,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,0,0},
        {1,1,1,0,1,0,0,0,0,0},
        {1,1,0,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

    BFS(7, 10, board);
 
    return 0;
}