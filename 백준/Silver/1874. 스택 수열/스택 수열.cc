#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<int> arr;
    int tmp;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }

    stack<int> chk;
    vector<char> ans;
    bool isOk = true;
    int cur = 1;

    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        while (cur <= *iter) {
            chk.push(cur++);
            ans.push_back('+');
        }
        if (!chk.empty() && (chk.top() == *iter)) {
            chk.pop();
            ans.push_back('-');
        } else {
            isOk = false;
            break;
        }
    }

    if (isOk) {
        for (auto iter = ans.begin(); iter != ans.end(); ++iter) {
            cout << *iter << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}