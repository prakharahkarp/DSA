class Solution {
public:
    int binSearch(vector<int>& nums, int l, int r,int target){
        while(r>=l){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        }
        int lastEle=nums[nums.size()-1];
        int pivot=binSearch(nums,0,nums.size()-1,lastEle);
        cout<<pivot<<"\n";
        int l,r;
        if(target>lastEle) l=0,r=pivot-1;
        else l=pivot,r=nums.size()-1;
        while(r>=l){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};