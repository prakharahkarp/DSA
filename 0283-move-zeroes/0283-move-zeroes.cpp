class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroesFilled=0;
        for(int i=0;i<nums.size()-zeroesFilled;i++){
            if(!nums[i]){
                for(int j=i+1;j<nums.size()-zeroesFilled;j++){
                    nums[j-1]=nums[j];
                }
                i--;
                nums[nums.size()-zeroesFilled-1]=0;
                zeroesFilled++;
            }
        }
    }
};

// approach 1 is to check every index and if we find a zero, puhs every element one position back and placing a zero at the end