#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_multiset<string> name;
    for (auto s : participant)
        name.insert(s);
    
    for (auto s : completion) {
        name.erase(name.find(s));
    }
    for (auto s : name)
        answer = s;
    
    return answer;
}