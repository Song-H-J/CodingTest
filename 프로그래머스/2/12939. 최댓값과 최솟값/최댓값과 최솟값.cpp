#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector<int> nums;
    
    for (char c : s) {
        if (c == ' ') {
            nums.push_back(stoi(tmp));
            tmp.clear();
        } else {
            tmp.push_back(c);
        }
    }
    nums.push_back(stoi(tmp));
    
    auto max_it = max_element(nums.begin(), nums.end());
    auto min_it = min_element(nums.begin(), nums.end());
    
    answer += to_string(*min_it);
    answer += ' ';
    answer += to_string(*max_it);
    
    return answer;
}