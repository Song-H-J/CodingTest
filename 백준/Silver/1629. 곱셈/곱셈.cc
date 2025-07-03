#include <iostream>

using namespace std;

long long calc(long long a, long long b, long long c)
{
    if (b == 1) return a % c;
    long long ans = calc(a, b/2, c);
    ans = ans * ans % c;
    return (b % 2 == 0) ? ans : ans * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c; // a^b % c
    cout << calc(a,b,c);

    return 0;
}