class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1,nonZeroCount=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) count++;
            else{
                count=count>2?2:count;
                while(count--){
                    nums[nonZeroCount++]=nums[i-1];
                }
                count=1;
            }
        }
        count=count>2?2:count;
        while(count--){
            nums[nonZeroCount++]=nums[nums.size()-1];
        }
        return nonZeroCount;
    }
};

// approach 1 use hashmap and place the elements
// approach 2 keep a count variabble for each element