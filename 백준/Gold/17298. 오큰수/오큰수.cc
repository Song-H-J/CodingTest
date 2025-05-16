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

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> NGE;
    vector<int> ans;
    for (int i = N - 1; i >= 0; i--) {
        while (!NGE.empty() && NGE.top() <= arr[i])
            NGE.pop();
        if (NGE.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(NGE.top());
        }
        NGE.push(arr[i]);
    }

    for (int i = N - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0;
}