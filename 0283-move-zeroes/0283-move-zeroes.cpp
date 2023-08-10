class Solution {
public:
    void swap(int pos1,int pos2,vector<int>& nums){
        int temp=nums[pos1];
        nums[pos1]=nums[pos2];
        nums[pos2]=temp;
    }
    
    void moveZeroes(vector<int>& nums) {
        int nonzeroPos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                swap(i,nonzeroPos,nums);
                nonzeroPos++;
                }
            }
    }
};

// approach 2 is to use a pointer that points to places where non-zero elements must reside and whenever we find a non-zero element, we move it to this position and increase the pos value by 1.