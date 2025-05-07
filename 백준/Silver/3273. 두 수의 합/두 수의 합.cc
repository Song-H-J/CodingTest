#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void calcMatch(int X, vector<int>& num)
{
    vector<int> zToX(X,0); // 0 ~ X
    int ans = 0;
    for (auto iter = num.begin(); iter != num.end(); ++iter) {
        if(X >= *iter) {
            //zToX[*iter]++; 여기에 쓰면 중복 카운트 문제 발생
            /*예를 들어 X가 100이고 *iter가 50이면
              50이 등장했을때 순서쌍 ans가 ++
              하지만 서로 다른 수만 존재하기에 이 순서쌍은 불가능
              그렇지만 이미 zToX의 50번째 원소값이 ++ 되었기에
              가능한 순서쌍이란 결론이 나버림
            */
            if (zToX[X - *iter] != 0)
                ans++;
            zToX[*iter]++;
        }
    }
    cout << ans;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> num(n,0);

    for (int i = 0; i < n; i++)
        cin >> num[i];
    
    int X;
    cin >> X;

    calcMatch(X, num);
    return 0;
}