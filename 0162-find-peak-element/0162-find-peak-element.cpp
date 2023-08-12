class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        if(nums.size()==2) return nums[0]>nums[1]?0:1;
        int l=0,r=nums.size()-1;
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[mid+1]) r=mid;
            else l=mid;
        }
        return nums[r]>nums[l]?r:l;
    }
};