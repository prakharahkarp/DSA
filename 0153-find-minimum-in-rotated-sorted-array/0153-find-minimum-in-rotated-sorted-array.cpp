class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int ans;
        while(r>=l){
            int mid=l+(r-l)/2;
            if(nums[mid]<=nums[nums.size()-1]){
                ans=nums[mid];
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};