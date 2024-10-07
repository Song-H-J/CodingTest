#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
    // auto iter = find(seoul.begin(), seoul.end(), "Kim");
    // int index = distance(seoul.begin(), iter);
    int index = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    string answer = "김서방은 " + to_string(index) + "에 있다";
    return answer;
}