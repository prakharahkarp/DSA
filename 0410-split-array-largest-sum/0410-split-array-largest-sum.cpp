class Solution {
public:
    bool isGood(int x, vector<int>& nums, int k){
        long long sum=0,totalSubarrays=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>x) return false;
            if(sum+nums[i]<=x){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                totalSubarrays++;
            }
        }
        totalSubarrays++;
        return totalSubarrays<=k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int l=-1;
        int r=1;
        while(!isGood(r,nums,k)){
            l=r;
            r*=2;
        }
        
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(isGood(mid,nums,k)) r=mid;
            else l=mid;
        }
        return r;
    }
};