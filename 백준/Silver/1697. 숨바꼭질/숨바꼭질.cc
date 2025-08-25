#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int map[100002];
int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fill(map, map + 100001, -1);

    queue<int> Q;
    map[n] = 0;
    Q.push(n);

    while (map[k] == -1) {
        auto cur = Q.front();
        Q.pop();

        for (int nxt : {cur-1, cur+1, cur*2}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (map[nxt] != -1) continue;

            map[nxt] = map[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << map[k];
    return 0;
}