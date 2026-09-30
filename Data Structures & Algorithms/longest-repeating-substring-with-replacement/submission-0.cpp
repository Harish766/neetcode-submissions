class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> map;
        int ans=0;
        int left=0;
        int maxFreq=0;
        for(int right=0;right<s.size();right++){
            map[s[right]]++;
            maxFreq = max(maxFreq,map[s[right]]);
            int window=right-left +1;
            int r=window-maxFreq;
            while(r>k){
                map[s[left]]--;
                left++;
                window= right - left +1;
                r=window-maxFreq;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
