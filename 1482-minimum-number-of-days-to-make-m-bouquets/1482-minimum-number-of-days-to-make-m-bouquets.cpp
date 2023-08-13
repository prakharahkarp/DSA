class Solution {
public:
    bool isGood(int x,vector<int>& bloomDay,int m,int k){
        long long totalFlowers=0,totalBoquets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=x) totalFlowers++;
            else{
                totalBoquets+=totalFlowers/k;
                totalFlowers=0;
            }
        }
        totalBoquets+=totalFlowers/k;
        return totalBoquets>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int l=0; // l is never good
        int r=1; // r is always good
        while(!isGood(r,bloomDay,m,k)){
            l=r;
            r*=2;
        }
        
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(isGood(mid,bloomDay,m,k)) r=mid;
            else l=mid;
        }
        return r;
    }
};