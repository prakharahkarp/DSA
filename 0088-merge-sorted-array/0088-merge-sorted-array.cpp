class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
            // k--;
        }
//         if(j==0) the first m elements are already ordered correctly in nums1
//         if(i==0) then only j is left to be added in nums1 and hence it will be added
//         if(i>0 && j>0) then the above loop wont exit
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};