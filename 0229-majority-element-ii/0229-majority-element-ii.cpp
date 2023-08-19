// at max there can be 2 elements that occur in the array more than n/3 times 
// so we'll 

class Solution {
public:
    bool check(int ele,vector<int>& nums){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele) count++;
        }
        return count>nums.size()/3;
    }
    
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1) return {nums[0]};
        int count1=0,count2=0,ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<nums.size();i++){
           if(count1==0&&nums[i]!=ele2) {
               ele1=nums[i]; 
               count1=1;
           }
           else if(count2==0&&nums[i]!=ele1) {
               ele2=nums[i]; 
               count2=1;
           }
           else if(nums[i]==ele1) count1++; 
           else if(nums[i]==ele2) count2++;
           else {
               count1--;
               count2--; 
           }
        }
        vector<int> ans;
        if(count1>0&&check(ele1,nums)) ans.push_back(ele1);
        if(count2>0&&check(ele2,nums)) ans.push_back(ele2);
        return ans;
    }
};

// 1 2 3 4 5 1 1 1 1 2 2 2 2
