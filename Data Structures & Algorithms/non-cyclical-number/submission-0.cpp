class Solution {
public:
    int getnext(int n){
        int total_sum=0;
        while(n>0){
            int digit=n%10;
            total_sum+=digit*digit;
            n/=10;
        }
        return total_sum;
    }
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        int ck=n;
        unordered_set<int> seen;
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            n=getnext(n);
        }
        return n==1;
    }
};