#include<iostream>
#include <algorithm>

using namespace std;

bool checkPrdr(int i)
{
    string s = to_string(i);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

bool checkPrime(int i)
{
    if (i == 1) {
        return false;
    } else if ((i == 2) || (i == 3)) {
        return true;
    } else if ((i % 2 == 0) || (i % 3 == 0)) {
        return false;
    } else {
        for (int j = 5; j*j <= i; j+=6) {
            if ((i % j == 0) || (i % (j+2) == 0))
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = N; ; ++i) {
        if (checkPrdr(i) && checkPrime(i)) {
            cout << i;
            break;
        }
    }


    return 0;
}