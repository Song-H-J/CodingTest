#include<iostream>
#include<string>
#include<list>

using namespace std;

void decodePw()
{
    string s;
    cin >> s;

    list<char> decode;
    auto cursor = decode.end();
    cursor--;

    for (char c : s) {
        switch (c) {
        case '<':
            if (cursor != decode.begin())
                cursor--;
            break;
        case '>':
            if (cursor != decode.end())
                cursor++;
            break;
        case '-':
            if (cursor != decode.begin()) {
                cursor--;
                cursor = decode.erase(cursor);
            }
            break;
        default :
            decode.insert(cursor, c);
            break;
        }
    }
    
    for (auto iter = decode.begin(); iter != decode.end(); ++iter)
        cout << *iter;
    cout << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        decodePw();
    return 0;
}