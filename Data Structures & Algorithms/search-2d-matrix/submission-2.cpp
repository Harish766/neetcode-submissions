class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if (matrix.empty() || matrix[0].empty()) return false;
        int m=matrix[0].size();
        int start=0;
        int end=(m*n)-1;
        while(start<=end){
           int mid= start + (end-start)/2;
            int r=mid/m;
            int c=mid%m;
            if(matrix[r][c]==target){
                return true;
            }
            else if(matrix[r][c]>target){
                end=mid-1;
            }
            else {
                start=mid+1;
            }

        }
        return false;
    }
};
