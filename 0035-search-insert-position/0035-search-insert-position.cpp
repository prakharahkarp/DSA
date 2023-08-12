class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if(target<nums[0]) return 0;
        // else if(target>nums[nums.size()-1]) return nums.size();
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