#include<iostream>
#include<string>
#include<list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int N;
    cin >> s;
    cin >> N;

    int k = s.length();
    list<char> modi;
    for (char c : s) {
        modi.push_back(c);
    }
    modi.push_back(' ');
    auto cursor = modi.end();
    cursor--; // ' '을 가리킴

    char cmd;
    char alph;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        switch (cmd){
        case 'L':
            if (cursor != modi.begin())
             cursor--;
            break;
        case 'D':
            if (*cursor != ' ')
             cursor++;
            break;
        case 'B':
            if (cursor != modi.begin()) {
             cursor--;
             cursor = modi.erase(cursor);
            }
            break;
        case 'P':
            cin >> alph;
            modi.insert(cursor, alph);
        }
    }

    for (auto iter = modi.begin(); iter != modi.end(); ++iter) {
        cout << *iter;
    }
    return 0;
}