class Solution {
public:
    void solve(vector<int>& nums, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == sum) {
            ans.push_back(curr); 
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(nums, target, sum + nums[i], i, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, target, 0, 0, curr, ans);
        return ans;
    }
};