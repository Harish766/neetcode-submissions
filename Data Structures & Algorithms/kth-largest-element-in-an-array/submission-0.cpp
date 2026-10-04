class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxhp;
        for(int num:nums){
            maxhp.push(num);
        }
        for(int i=0;i<k-1;i++){
            maxhp.pop();
        }
        return maxhp.top();
    }
};
