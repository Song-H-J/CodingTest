#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    stack<int> cash;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        
        if ((tmp == 0) && !cash.empty()) {
            cash.pop();
        } else {
            cash.push(tmp);
        }
    }

    unsigned long ans = 0;
    while(!cash.empty()) {
        ans = ans + cash.top();
        cash.pop();
    }
    cout << ans;
    return 0;
}