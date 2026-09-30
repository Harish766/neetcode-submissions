class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int size=s.size();
        int i=0;
        int left=0;
        int count=0;
        int maxn=0;
        while(i<size){
            if(!map[s[i]]){
                map[s[i]]++;
                count++;
                i++;
                maxn = max(count,maxn);
            }else{
                map[s[left]]=0;
                left++;
                count--;
            }
        }
        return maxn;
    }
};
