class Solution {
public:
    bool isGood(double x,vector<int>& piles,int h){
        double totalTime=0;
        for(int i=0;i<piles.size();i++){
            totalTime+=ceil(piles[i]/x);
        }
        return totalTime<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=0; // l is never good
        int r=1; // r is always good
        while(!isGood(r,piles,h)){
            l=r;
            r*=2;
        }
        
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(isGood(mid,piles,h)) r=mid;
            else l=mid;
        }
        
        return r;
    }
};