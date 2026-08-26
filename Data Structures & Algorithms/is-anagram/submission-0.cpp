class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> check;
        unordered_map<char,int> click;
        int r=s.size();
        int l=t.size();
        if(l>r || r>l){
            return false;
        }
        for(int i=0;i<r;i++){
            check[s[i]]++;
            click[t[i]]++;
        }
        if(check==click){
            return true;
        }
        return false;
    }
};
