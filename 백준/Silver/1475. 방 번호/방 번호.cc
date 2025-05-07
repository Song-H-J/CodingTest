#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void calcSet(int N, vector<int>& numberCnt)
{
    for (; N > 0; N = N/10) {
        numberCnt[N % 10]++;
    }

    numberCnt[6] = (numberCnt[6] + numberCnt[9])/2 + (numberCnt[6] + numberCnt[9])%2;
    numberCnt[9] = 0;
    auto max_iter = max_element(numberCnt.begin(), numberCnt.end());
    cout << *max_iter;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<int> numberCnt(10,0);

    cin >> N;
    calcSet(N, numberCnt);
    return 0;
}