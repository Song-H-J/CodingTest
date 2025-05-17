#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> card(N);
    for (int i = 0; i < N; ++i)
        card[i] = i + 1; // 1 to N

    int head = 0;
    int tail = N-1;

    
    while (true) {
        if (head == N-1) { // queue pop
            head = 0;
        } else {
            head++;
        }

        if (head == tail)
            break;

        if (tail == N-1) { // queue push(queue front)
            card[0] = card[head];
        } else {
            card[tail + 1] = card[head];
        }

        if (head == N-1) { // queue pop
            head = 0;
        } else {
            head++;
        }

        if (tail == N-1) {
            tail = 0;
        } else {
            tail++;
        }
    }   

    cout << card[head] <<'\n';
    //cout << card[tail] <<'\n';
    return 0;
}