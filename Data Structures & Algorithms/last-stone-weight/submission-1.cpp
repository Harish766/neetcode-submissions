class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone:stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size()>1){
            int x=maxHeap.top();
            maxHeap.pop();
            int y=maxHeap.top();
            maxHeap.pop();
            if(x==y){
                continue;
            }else{
                if(x>y){
                    x=x-y;
                    maxHeap.push(x);
                }else{
                    y=y-x;
                    maxHeap.push(y);
                }
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
