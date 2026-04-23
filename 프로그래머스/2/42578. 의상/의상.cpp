#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> info;
    for (int i = 0; i < clothes.size(); i++)
        info[clothes[i][1]]++;
  
    for (auto s : info) 
        answer *= (s.second + 1);

    return answer - 1;
}