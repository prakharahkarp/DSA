class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1,nonZeroCount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                count++;
                if(count<=2) nums[nonZeroCount++]=nums[i];
            }
            else{
                count=1;
                nums[nonZeroCount++]=nums[i];
            }
        }
        return nonZeroCount;
    }
};

// approach 1 use hashmap and place the elements
// approach 2 keep a count variabble for each element