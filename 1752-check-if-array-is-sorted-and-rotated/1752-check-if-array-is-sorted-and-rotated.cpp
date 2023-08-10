class Solution {
public:
    bool check(int start,vector<int>& nums){
        for(int i=start;i<start+nums.size()-1;i++){
            if(nums[i%nums.size()]>nums[(i+1)%nums.size()]) return false;
        }
        return true;
    }
    
    bool check(vector<int>& nums) {
        int minElePos=min_element(nums.begin(),nums.end())-nums.begin();
        if(check(minElePos,nums)) return true;
        int minEle=nums[minElePos],i=nums.size()-1;
        if(minElePos==0){
            while(nums[i]==minEle){
                minElePos=i;
                i--;
            }
        }
        return check(minElePos,nums);
    }
};

// approach 1 find the min element in the array and starting from this element, search the complete array in circular manner such that there should be no elements nums[i]>nums[i+1]