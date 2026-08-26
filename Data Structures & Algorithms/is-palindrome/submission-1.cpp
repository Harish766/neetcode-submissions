class Solution {
public:
    bool isPalindrome(string s) {
        string p="";
        for(int i=0;i<s.size();i++){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') ||(s[i]>='0' && s[i]<='9')){
            p+=toupper(s[i]);
            }
        }
        int r=p.size()-1;
        for(int i=0;i<p.size()/2;i++){
            if(p[i]!=p[r]){
                return false;
            }
            r--;
        }
        return true;
    }
};
