class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int r=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(!map[nums[i]]){
                map[nums[i]]++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};