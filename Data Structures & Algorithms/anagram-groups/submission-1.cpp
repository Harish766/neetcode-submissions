class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const string& str : strs) {
            // Fixed-size string of length 26 representing counts of 'a' through 'z'
            string key(26, 0); 
            for (char c : str) {
                key[c - 'a']++; // O(1) frequency count
            }
            mp[key].push_back(str); // O(1) average map lookup
        }

        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for (auto& pair : mp) {
            ans.push_back(move(pair.second));
        }

        return ans;
    }
};