class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueElePos=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[uniqueElePos++]=nums[i-1];
            }
        }
        nums[uniqueElePos++]=nums[nums.size()-1];
        return uniqueElePos;
    }
};

// approach 1 use hash map