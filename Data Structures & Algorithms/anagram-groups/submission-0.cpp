class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<map<char, int>, vector<string>> mp;
        for(string str:strs){
            map<char, int> check;
            for(char c:str){
                check[c]++;
            }
            mp[check].push_back(str);
        }
        for(auto &pair:mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
