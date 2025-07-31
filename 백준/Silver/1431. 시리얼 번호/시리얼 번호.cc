#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(const string& a, const string& b)
{
    int acnt = 0;
    int bcnt = 0;
    
    if (a.length() < b.length()) return true;
    else if (a.length() > b.length()) return false;
    else {
        for (int i = 0; i < a.length(); i++) {
            if ('0' <= a[i] && a[i] <= '9') acnt = acnt + (a[i] - '0');
            if ('0' <= b[i] && b[i] <= '9') bcnt = bcnt + (b[i] - '0');
        }
        if (acnt < bcnt) return true;
        else if (acnt > bcnt) return false;
        else {
            for (int j = 0; j < a.length(); j++) {
                if (a[j] < b[j]) return true;
                else if (a[j] > b[j]) return false;
            }
            return false;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<string> dic;
    string tmp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        dic.push_back(tmp);
    }

    sort(dic.begin(), dic.end(), cmp);

    for (string s : dic) {
        cout << s << '\n';
    }
    return 0;
}