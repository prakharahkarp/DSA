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

// 000000000000000111111111111111 2 1 0 0 1 2 0 0 22222222222222
// 0......(low-1) low......(mid-1) mid.......high (high+1).....n