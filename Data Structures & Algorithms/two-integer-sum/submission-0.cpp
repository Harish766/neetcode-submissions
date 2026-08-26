class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int r=0;
        int p=r+1;
        int l=nums.size();
        while(r<l){
            if(p>=l){
                r++;
                p=r+1;
            }

            int num1=nums[r];
            int num2=nums[p];
            int targ=num1+num2;
            if(targ==target){
                return {r,p};
            }
            p++;
        }
        return {-1,-1};
    }
};
