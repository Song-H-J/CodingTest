// 백트래킹 템플릿
#include <iostream>

using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k){ // k개의 수를 선택한 상태에서 k+1번째 수를 선택하는 함수
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
    cout << '\n';
    return;
  }

  for(int i = 1; i <= n; i++){ // 1부터 n까지의 수 i에 대해 선택 가능한지 탐색
    if(!isused[i]){ // 아직 i가 사용되지 않았으면
      arr[k] = i; // k+1번째 수를 i로 정함 (인덱스는 0부터)
      isused[i] = 1; // i를 사용되었다고 표시
      func(k+1); // 다음 수를 선택하러 한 단계 더 들어감
      isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
      // ex) 1 2 3 중 3이 이번 차례에 선택한 수라면 1234 1235 1236 등을 전부 체크 후 복귀했으므로
      // 다른 조합 탐색이 가능하게 선택 여부를 초기화
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}