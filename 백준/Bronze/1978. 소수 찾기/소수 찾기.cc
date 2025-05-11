#include<iostream>

using namespace std;

void checkPrime(int& ans, int num)
{
    if (num == 1) {
        return;
    } else if ((num == 2) || (num == 3)) {
        ans++;
        return;
    } else if ((num % 2 == 0) || (num % 3 == 0)) {
        return;
    } else {
        for (int i = 5; i*i <= num; i+=6) {
            if ((num % i == 0) || (num % (i+2) == 0))
                return;
        }
        ans++;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int num;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> num;
        checkPrime(ans, num);
    }
    cout << ans;
    return 0;
}