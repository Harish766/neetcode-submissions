class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        int maxFreq=0;
        for(char task:tasks){
            map[task-'A']++;
            maxFreq=max(maxFreq,map[task-'A']);
        }
        int maxFreqCount=0;
        for(int count:map){
            if(count==maxFreq){
                maxFreqCount++;
            }
        }
        int ans=(maxFreq-1)*(n+1) + maxFreqCount;
        return max((int)tasks.size(),ans);

    }
};
