class Solution {
public:
    bool isGood(double x,vector<int>& nums,int threshold){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(nums[i]/x);
        }
        return sum<=threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=0;
        int r=1;
        while(!isGood(r,nums,threshold)){
            l=r;
            r*=2;
        }
        
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(isGood(mid,nums,threshold)) r=mid;
            else l=mid;
        }
        return r;
    }
};