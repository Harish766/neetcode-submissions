class Solution {
public:
    void solve(vector<int>&nums,vector<int> &curr,vector<vector<int>> &ans,int target,int sum,int index){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(sum>target || index==nums.size()){
            return;
        }
        curr.push_back(nums[index]);
        solve(nums,curr,ans,target,sum + nums[index],index);
        curr.pop_back();
        solve(nums,curr,ans,target,sum,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(nums,curr,ans,target,0,0);
        return ans;
    }
};
