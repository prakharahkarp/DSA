class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=-1,r=nums.size();
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid;
        }
        if(nums[r]==target) return r;
        return r;
    }
};