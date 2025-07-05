#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
int cnt;
vector<pair<int, int>> NQueen;

void queen(int k)
{ // k번째 퀸을 놓을 수 있는 공간을 탐색하는 함수
    if (k > n) { // n개의 퀸이 배치됐다면 경우의 수 1 증가
        cnt++;
        return;
    }

    int row = k-1;
    for (int i = 0; i < n; i++) { // 퀸 특성 상 1행에 1개만 배치 가능, 입력 k를 -1해 행으로 사용.
        bool isOk = true;
        for (auto& q : NQueen) {
            if (q.first == row || q.second == i) {
                isOk = false;
                break;
            } else if (q.first + q.second == row + i) {
                isOk = false;
                break;
            } else if (q.first - q.second == row - i) {
                isOk = false;
                break;
            }
        }

        if (isOk) {
            NQueen.push_back({row,i});
            queen(k+1);
            NQueen.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    queen(1);
    cout << cnt;
    return 0;
}