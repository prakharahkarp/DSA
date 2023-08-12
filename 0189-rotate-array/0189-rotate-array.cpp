class Solution {
public:
    void reverse(int start, int end, vector<int>& nums){
        end--;
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    } 
    
    void print(vector<int>& nums){
        for(int i=0;i<nums.size();i++) cout<<nums[i]<<" ";
        cout<<"\n";
    }
    
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k==0) return ;
        reverse(0,nums.size()-k,nums);
        print(nums);
        reverse(nums.size()-k,nums.size(),nums);
        print(nums);
        reverse(0,nums.size(),nums);
        print(nums);
    }
};

// approach 1 : SC->O(1) TC->O(n^2) when k=n; we rotate the array by 1 place at a time and we do this k%n times

// approach 2 : SC->O(n) when k=n; TC->O(n); we store k elements in another array, and push the remaining elements ahead by k and later we place these copied elements in the first k positions

// approach 3 : SC->O(1) TC->O(n) we first reverse first n-k elements, then we reverse the remaing k elements and then we reverse the complete array

// 1 2 3 4 5 6 7

// -1 -100 3 99