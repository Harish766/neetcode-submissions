class Solution {
public:
    void solve(vector<int>& nums, int target, int sum,int start,
           vector<int>& curr, vector<vector<int>> &ans,
           vector<bool>& vis) {

    if(sum == target) {
        ans.push_back(curr);
        return;
    }

    if(sum > target) {
        return;
    }

    for(int i = start; i < nums.size(); i++) {

        if(vis[i])
            continue;
        if(i > start && nums[i] == nums[i - 1])
                continue;
// //1 1 3 5 6 
// 1 3 6 
// 1 3 6
// 1 1 3
// 1 3 5
// 1 3 5
        vis[i] = true;
        curr.push_back(nums[i]);

        solve(nums, target, sum + nums[i],i+1,
              curr, ans, vis);

        curr.pop_back();
        vis[i] = false;
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        
        vector<bool> vis(n,false);
        vector<vector<int>> ans;
        solve(candidates,target,0,0,curr,ans,vis);
        
        return ans;
    }
};