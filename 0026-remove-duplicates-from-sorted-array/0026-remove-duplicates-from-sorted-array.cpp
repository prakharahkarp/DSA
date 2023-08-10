class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        int uniqueElePos=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]==1) nums[uniqueElePos++]=nums[i];
        }
        return uniqueElePos;
    }
};

// approach 1 use hash map