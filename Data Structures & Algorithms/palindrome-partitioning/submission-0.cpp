class Solution {
public:
    bool isPalindrome(string& str, int start, int end) {
        while (start <= end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string& s, vector<string>& curr,
               vector<vector<string>>& ans, int index) {

        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));

                solve(s, curr, ans, i + 1);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;

        solve(s, curr, ans, 0);

        return ans;
    }
};