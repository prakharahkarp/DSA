class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zeroes=0,ones=0,twos=nums.size()-1;
        while(ones<=twos){
            if(nums[ones]==2){
                swap(nums[ones],nums[twos]);
                twos--;
            }
            else if(nums[ones]==0){
                swap(nums[ones],nums[zeroes]);
                zeroes++;
                ones++;
            }
            else ones++;
        }
    }
};

// 0 0 1 1 2 2