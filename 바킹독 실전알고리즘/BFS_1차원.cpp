#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;
#define X first
#define Y second
int dist[100002]; // 시작점으로부터 거리를 저장. 1차원
int n,k;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  fill(dist, dist+100001,-1); // -1로 초기화

  // 탐색 준비
  dist[n] = 0;
  queue<int> Q;
  Q.push(n);

  while(dist[k] == -1){
    int cur = Q.front();
    Q.pop();

    for(int nxt : {cur-1, cur+1, 2*cur}){ // -1, +1 이동, x2의 텔포
      if(nxt < 0 || nxt > 100000) continue; // 이동이나 텔포를 해 음수로 가거나, 10만을 넘어 비효율적 탐색을 하게 되면 패스
      if(dist[nxt] != -1) continue; // 이미 이동한 곳이라면 패스

      dist[nxt] = dist[cur]+1; // 이동 혹은 텔포 1회로 이동한 곳이므로 어느쪽이든 이동 횟수 1회 증가
      Q.push(nxt);
    }        
  }
  cout << dist[k];
}