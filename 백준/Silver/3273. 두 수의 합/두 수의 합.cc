#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void calcMatch(int X, vector<int>& num)
{
    vector<int> zToX(X,0); // 0 ~ X
    int ans = 0;
    for (auto iter = num.begin(); iter != num.end(); ++iter) {
        if(X >= *iter) {
            if (zToX[X - *iter] != 0)
                ans++;
            zToX[*iter]++;
        }
    }
    cout << ans;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> num(n,0);

    for (int i = 0; i < n; i++)
        cin >> num[i];
    
    int X;
    cin >> X;

    calcMatch(X, num);
    return 0;
}