#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[3] = {0,0,0};
    
    vector<int> test1 = {1,2,3,4,5};
    vector<int> test2 = {2,1,2,3,2,4,2,5};
    vector<int> test3 = {3,3,1,1,2,2,4,4,5,5};
    
    int pars1 = 0;
    int pars2 = 0;
    int pars3 = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        int iter = answers[i];
        
        if (iter == test1[pars1])
            cnt[0]++;
        pars1++;
        if(pars1 == 5)
            pars1 = 0;
        
        if (iter == test2[pars2])
            cnt[1]++;
        pars2++;
        if(pars2 == 8)
            pars2 = 0;
        
        if (iter == test3[pars3])
            cnt[2]++;
        pars3++;
        if(pars3 == 10)
            pars3 = 0;
    }
    
    int max = *max_element(cnt, cnt+3);
    for(int j = 0; j < 3; j++) {
        if (cnt[j] == max) {
            answer.push_back(j+1);
        }
    }
    
    return answer;
}