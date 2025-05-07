#include<iostream>
#include<vector>

using namespace std;

void cntNumber(int A, int B, int C, vector<int>& numberCnt)
{
    int ABC = A * B * C;
    for (; ABC > 0; ABC = ABC/10) {
        numberCnt[ABC % 10]++;
    }
    for (auto iter = numberCnt.begin(); iter != numberCnt.end(); ++iter) {
        cout << *iter << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A;
    int B;
    int C;
    vector<int> numberCnt(10,0);

    cin >> A;
    cin >> B;
    cin >> C;
    cntNumber(A, B, C, numberCnt);
    return 0;
}