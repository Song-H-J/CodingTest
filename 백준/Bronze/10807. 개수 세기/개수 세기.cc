#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> num(201,0);
    int tmp;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        num[tmp + 100]++;
    }
    
    int v;
    cin >> v;

    int ans = num[v+100];
    cout << ans;
    return 0;
}