#include <iostream>
#include <queue>

using namespace std;

int dist[1000002];
int F, S, G, U, D;
// F총층수, S처음위치, G목적지, U위로U층, D아래로D층

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    for (int i = 0; i <= F; i++)
        dist[i] = -1;

    dist[S] = 0;
    queue<int> Q;
    Q.push(S);

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        if (cur == G) break;

        for (int nxt : {cur-D, cur+U}) {
            if (nxt < 1 || nxt > F) continue;
            if (dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    if (dist[G] == -1) cout << "use the stairs";
    else cout << dist[G];
    
    return 0;
}