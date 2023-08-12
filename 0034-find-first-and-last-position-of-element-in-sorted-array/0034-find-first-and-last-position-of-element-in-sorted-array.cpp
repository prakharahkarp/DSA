class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=-1,r=nums.size(),first=-1,last=-1;
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid;
        }
        if(nums.size()==0||r<0||r>=nums.size()||nums[r]!=target) return {-1,-1};
        first=r;
        l=-1;
        r=nums.size();
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) l=mid;
            else r=mid;
        }
        if(nums.size()==0||l<0||l>=nums.size()||nums[l]!=target) return {-1,-1};
        last=l;
        return {first,last};
    }
};