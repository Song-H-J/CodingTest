#include <iostream>

using namespace std;

int dp[15];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 4; i <= 11; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    int n;
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cout << dp[tmp] << '\n';
    }
    
    return 0;
}