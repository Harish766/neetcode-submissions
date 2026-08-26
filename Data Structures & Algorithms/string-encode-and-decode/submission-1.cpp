class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
         for(string &s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int num = stoi(s.substr(i, j - i));
            string p = s.substr(j + 1, num);
            ans.push_back(p);
            i=j+1+num;
        }
        return ans;
    }
};
