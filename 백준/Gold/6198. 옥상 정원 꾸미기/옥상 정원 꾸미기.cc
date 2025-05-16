#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    stack<int> visible;
    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;

        while (!visible.empty() && visible.top() <= h)
            visible.pop();
        ans += visible.size();
        visible.push(h);
    }

    cout << ans << '\n';
    return 0;
}
