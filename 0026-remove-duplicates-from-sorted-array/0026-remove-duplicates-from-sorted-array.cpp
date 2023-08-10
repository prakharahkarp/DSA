class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniqueElePos=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[uniqueElePos++]=nums[i];
            }
        }
        return uniqueElePos;
    }
};

// approach 1 use hash map

// approach 2 we can use the fact that the array is sorted and hence whenever we encounter a condition wherein nums[i]!=nums[i-1], it means that we will no longer see nums[i-1] and hence we can keep this nums[i-1] as a unique element
// keeping the last element of array always helps in certain edge case such as when there is only one element in the array or in case wherein, we dont encounter the condition nums[i]!=nums[i-1] for the last element either due to duplicacy or without any reason