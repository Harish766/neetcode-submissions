class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> minHeap;
        for(auto &pts:points){
            int n1=pts[0];
            int n2=pts[1];
            int dist=n1*n1 + n2*n2; 
            minHeap.push({dist,pts});

        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};
