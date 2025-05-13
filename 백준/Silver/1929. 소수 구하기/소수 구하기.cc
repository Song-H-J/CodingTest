#include<iostream>

using namespace std;

void checkPrime(int M, int N)
{
    for (int i = M; i <= N; i++) {
        bool isPrime = true;
        if (i == 1) {
            continue;
        } else if ((i == 2) || (i == 3)) {
            cout << i << '\n';;
            continue;
        } else if ((i % 2 == 0) || (i % 3 == 0)) {
            continue;
        } else {
            for (int j = 5; j*j <= i; j+=6) {
                if ((i % j == 0) || (i % (j+2) == 0)) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime)
            cout << i << '\n';;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;
    int N;
    cin >> M;
    cin >> N;

    checkPrime(M, N);
    return 0;
}