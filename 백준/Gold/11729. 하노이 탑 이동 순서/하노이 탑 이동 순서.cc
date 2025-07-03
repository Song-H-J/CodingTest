#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int cnt = 0;
queue<pair<int, int>> moving;

void hanoi(int num, int from, int to)
{
    if (num == 1) {
        moving.push({from, to});
        // cout << from << ' ' << to << '\n';
        cnt++;
        return;
    }
    int tmp = (from + to == 3 && abs(from - to) == 1) ? 3 : abs(from - to);
    hanoi(num-1, from, tmp);
    hanoi(1, from, to);
    hanoi(num-1, tmp, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cnt = 0;
    while(!moving.empty()) moving.pop();
    
    int num;
    cin >> num;
    hanoi(num, 1, 3);
    
    cout << cnt << '\n';
    while(!moving.empty()) {
        auto tmp = moving.front();
        moving.pop();
        cout << tmp.first << ' ' << tmp.second << '\n';
    }
    return 0;
}