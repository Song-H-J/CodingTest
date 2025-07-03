#include <iostream>

using namespace std;

int num = 0;

void calc(int N, int r, int c)
{
    if (N == 0) return;
    
    int div = (1 << (N - 1));
    int x = r / div;
    int y = c / div;
    num = num + (x * 2 + y) * div * div;
    
    calc(N-1, r-(div*x), c-(div*y));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    num = 0;
    int N, r, c;
    cin >> N >> r >> c;
    calc(N, r, c);
    cout << num;
    return 0;
}