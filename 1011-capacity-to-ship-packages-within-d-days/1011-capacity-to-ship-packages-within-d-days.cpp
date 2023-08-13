class Solution {
public:
    bool isGood(int x, vector<int>& weights, int days){
        int currentWeight=0,time=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>x) return false;
            if(currentWeight+weights[i]<=x){
                currentWeight+=weights[i];
            }
            else{
                time++;
                currentWeight=weights[i];
            }
        }
        time++; // last shipment
        return time<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0;
        int r=1;
        while(!isGood(r,weights,days)){
            l=r;
            r*=2;
        }
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(isGood(mid,weights,days)) r=mid;
            else l=mid;
        }
        return r;
    }
};