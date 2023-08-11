class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long maxNegEle=INT_MIN,countZero=0,countNeg=0,maxProduct=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) countZero++;
            else{
                if(nums[i]<0){
                    countNeg++;
                    maxNegEle=max(maxNegEle,(long long)nums[i]);
                }
                maxProduct*=nums[i];
            }
        }
        if(countNeg==1&&nums.size()==1) return maxProduct;
        if(countNeg%2) maxProduct/=maxNegEle;
        if(countNeg==1&&countZero==nums.size()-1) return 0;
        if(countZero==nums.size()) return 0;
        return maxProduct;
    }
};