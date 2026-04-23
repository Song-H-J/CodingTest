#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_set<string> num;
    for (auto s : phone_book)
        num.insert(s);
    
    for (auto s : phone_book) {
        string head = "";
        for (int i = 0; i < s.size() - 1; i++) {
            head += s[i];
            if (num.find(head) != num.end()) return false;
        }
    }
    return answer;
}