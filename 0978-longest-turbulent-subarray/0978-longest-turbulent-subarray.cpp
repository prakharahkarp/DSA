class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int flag=nums[1]>nums[0]?0:1;
        int maxLen=1,tempLen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]&&(flag==0||flag==-1)){
                flag=1;
                tempLen++;
            }
            else if(nums[i]<nums[i-1]&&(flag==1||flag==-1)){
                flag=0;
                tempLen++;
            }
            else if(nums[i]==nums[i-1]){
                maxLen=max(maxLen,tempLen);
                tempLen=1;
                flag=-1;
            }
            else{
                maxLen=max(maxLen,tempLen);
                tempLen=2;
                flag=nums[i]>nums[i-1]?1:0;
            }
        }
        maxLen=max(maxLen,tempLen);
        return maxLen;
    }
};