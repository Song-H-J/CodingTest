#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_set<int> pokemon;
    for (int x : nums) {
        pokemon.insert(x);
    }
    answer = (pokemon.size() > nums.size()/2) ? (nums.size()/2) : pokemon.size();
    return answer;
}