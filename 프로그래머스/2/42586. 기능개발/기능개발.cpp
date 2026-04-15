#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = speeds.size();
    int finDay[101] = {0}; // 100퍼 되는 날 배열
    stack<int> chk; // 배포일 체크용 스택
    
    for (int i = 0; i < n; i++)
        finDay[i] = ((100 - progresses[i] + speeds[i] - 1) / speeds[i]);    
    
    int nums = 0;
    for (int i = 0; i < n; i++) {
        if (chk.empty()) {
            chk.push(finDay[i]);
            nums++;
        } else if (chk.top() >= finDay[i]) { // 배포 기능 수 ++
            nums++;
        } else if (chk.top() < finDay[i]) { // 이전 기능들 배포일 확정 후 다음 배포 설정
            answer.push_back(nums);
            nums = 0;
            chk.pop();
            chk.push(finDay[i]);
            nums++;
        }
    }
    answer.push_back(nums);
    
    return answer;
}