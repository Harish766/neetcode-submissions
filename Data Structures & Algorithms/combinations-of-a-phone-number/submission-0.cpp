class Solution {
public:
    void solve(int index,string &digits,string &current,vector<string> &ans,vector<pair<int, vector<char>>> &mp){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        int digit=digits[index]-'0';
        for(auto &p: mp){
            if(p.first==digit){
                for(char ch:p.second){
                    current.push_back(ch);
                    solve(index+1,digits,current,ans,mp);
                    current.pop_back();
                }
                break;
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<pair<int,vector<char>>> mp= {
            {2, {'a', 'b', 'c'}},
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        };
        vector<string> ans;
        string current="";
        solve(0,digits,current,ans,mp);
        return ans;
    }
};
