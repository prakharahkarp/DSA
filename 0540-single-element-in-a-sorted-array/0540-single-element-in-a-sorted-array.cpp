class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0,r=nums.size()-1,ans=nums[0];
        while(r>l+1){
            int mid=l+(r-l)/2;
            // cout<<mid<<"\n";
            // if((mid==0||nums[mid]!=nums[mid-1])&&(mid==nums.size()-1)||(nums[mid+1]!=nums[mid])) return nums[mid];
            if(mid%2){
                if(nums[mid]==nums[mid+1]) r=mid;
                else l=mid;
            }
            else{
                if(nums[mid]==nums[mid+1]) l=mid; 
                else r=mid;
            }
        }
        if((l==0&&nums[l]!=nums[l+1])||(nums[l]!=nums[l-1]&&nums[l]!=nums[l+1])) return nums[l];
        return nums[r];
    }
};

// 1 2 2