#include<iostream>
#include<string>
#include<list>

using namespace std;

void josephus(int N, int K)
{
    list<int> jsp;
    for (int i = 1; i <= N; i++)
        jsp.push_back(i);
    auto cursor = jsp.begin();

    cout << '<';
    while (1) {
        for (int i = 0; i < K-1; i++) {
            cursor++;
            if (cursor == jsp.end())
                cursor = jsp.begin();
        }
        cout << *cursor;
        cursor = jsp.erase(cursor);
        if (cursor == jsp.end())
            cursor = jsp.begin();
        
        if (jsp.empty()) {
            cout << '>';
            break;
        } else {
            cout << ',';
            cout << ' ';
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int K;
    cin >> N;
    cin >> K;

    josephus(N, K);
    return 0;
}