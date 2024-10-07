#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sort;
    for(int i = 0; i<commands.size(); i++)
    {
       int start = commands[i][0];
       int end = commands[i][1];
       int idx = commands[i][2];
        
        for(int k = start-1; k<end; k++)
        {
            sort.push_back(array[k]);
        }
        
        int a,b,max,temp;
         for(a = sort.size(); a > 1; a--){
            max = 0;
             for(b=1; b<a; b++){
                if(sort[max]<sort[b]) max = b;
            }
            temp = sort[max];
             sort[max]=sort[a-1];
             sort[a-1]=temp;
          }
        answer.push_back(sort[idx-1]);
        sort.clear();
    }
    return answer;
}