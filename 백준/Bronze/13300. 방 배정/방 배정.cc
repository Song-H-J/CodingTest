#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 총 학생 수
    int K; // 한 방 max
    cin >> N;
    cin >> K;

    vector<vector<int>> student(2,vector<int>(6,0));

    int S;
    int Y;
    for (int i = 0; i < N; i++) {
        cin >> S;
        cin >> Y;
        student[S][Y-1]++;
    }

    int ans = 0;
    for (auto riter = student.begin(); riter != student.end(); ++riter) {
        for (auto citer = riter->begin(); citer != riter->end(); ++citer) {
            ans = ans + (*citer/K);
            if(*citer%K)
                ans++; 
        }
    }

    cout << ans;
    return 0;
}