class Solution {
public:
    long long Ispossible(vector<int> &piles,int k){
        long long hours=0;
        for(int pile:piles){
            hours += ceil((double)pile/k);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int max=-999;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>max){
                max=piles[i];
            }
        }
        int end=max;
        int maxbun=max;
        while(start<=end){
            int mid = start + (end-start)/2;
            long long hours = Ispossible(piles,mid);
            if(hours<=h){
                maxbun=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return maxbun;
    }
};
