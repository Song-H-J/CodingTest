// Counting Sort
#include <iostream>

using namespace std;

int num[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, tmp;

    cin >> N;

    // 숫자 카운팅 및 오름차순 출력
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        num[tmp + 1000000]++;
    }

    for (int i = 0; i < 2000001; i++) {
        if (num[i] != 0) {
            for (int j = 0; j < num[i]; j++)
                cout << i-1000000 << '\n';
        }
    }
    
    return 0;
}