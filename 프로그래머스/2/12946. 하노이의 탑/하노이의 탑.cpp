#include <string>
#include <vector>

using namespace std;

void move(int before, int after, vector<vector<int>>& ans){
    ans.push_back({before, after});
}

void hanoi(int n, int start, int via, int goal, vector<vector<int>>& ans){
    if(n==0) return;
    hanoi(n-1, start, goal, via, ans);
    move(start, goal, ans);
    hanoi(n-1, via, start, goal, ans);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1,2,3,answer);
    return answer;
}