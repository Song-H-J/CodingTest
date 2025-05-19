#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int n = N;
    int add = 0;
    int cnt = 0;

    do {
        add = n/10 + n%10;
        n = n%10*10 + add%10;
        //cout << "tmp : " << n << '\n';
        cnt++;
    } while (N != n);

    
    cout << cnt;

    return 0;
}