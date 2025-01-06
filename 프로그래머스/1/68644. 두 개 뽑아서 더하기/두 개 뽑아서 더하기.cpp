#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> calc;
    
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i+1; j < numbers.size(); j++) {
            calc.insert(numbers[i] + numbers[j]);
        }
    }
    
    answer.assign(calc.begin(), calc.end());
    return answer;
}