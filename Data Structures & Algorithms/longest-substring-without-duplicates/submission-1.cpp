class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int n=s.size()-1;
       
        unordered_map<char,int> map;
        int j=0;
        int count=0;
        int max=0;
        while(j<s.size()){
            if(map[s[j]]==0){
                    map[s[j]]=1;
                    count++;
                    j++;
                    if(max<count){
                        max=count;
                    }
            }else{
                map[s[i]]--;
                count--;
                i++;
            }
            
            }
            return max;
        }
};
