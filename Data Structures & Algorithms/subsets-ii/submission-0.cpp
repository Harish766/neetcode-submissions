class Solution {
public:
    void solve(vector<int>& nums,vector<int> &curr,set<vector<int>> &s,int i){
        if(i==nums.size()){

            s.insert(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(nums,curr,s,i+1);
        curr.pop_back();
        solve(nums,curr,s,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        set<vector<int>> s;
        solve(nums,curr,s,0);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
