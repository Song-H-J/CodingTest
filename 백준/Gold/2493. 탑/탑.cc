#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> example(N);
    for (int i = 0; i < N; i++) {
        cin >> example[i];
    }

    stack<vector<int>> tower;
    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        while (!tower.empty() && tower.top()[1] < example[i])
            tower.pop();
        if (tower.empty()) {
            ans[i] = 0;
        } else {
            ans[i] = tower.top()[0];
        }
        tower.push({i + 1, example[i]});
    }

    for (int i : ans)
        cout << i << ' ';

    return 0;
}