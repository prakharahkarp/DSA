class Solution {
public:
    int binSearch(vector<int>& nums, int l, int r,int target){
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) r=mid;
            else l=mid;
        }
        return r;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
        int lastEle=nums[nums.size()-1];
        int pivot=binSearch(nums,-1,nums.size(),lastEle);
        cout<<pivot<<"\n";
        int l,r;
        if(target>lastEle) l=-1,r=pivot;
        else l=pivot-1,r=nums.size();
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid;
        }
        if(r>=0&&r<nums.size()&&nums[r]==target) return r;
        return -1;
    }
};