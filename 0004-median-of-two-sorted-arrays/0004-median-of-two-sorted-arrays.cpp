class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int medianPos=(m+n-1)/2;
        int i1=0,i2=0,count=0,ele1,ele2;
        while(i1<m&&i2<n){
            if(nums1[i1]<nums2[i2]){
                if(count==medianPos) ele1=nums1[i1];
                if(count==medianPos+1) ele2=nums1[i1];
                i1++;
            }
            else {
                if(count==medianPos) ele1=nums2[i2];
                if(count==medianPos+1) ele2=nums2[i2];
                i2++;
            }
            count++;
        }
        while(i1<m){
            if(count==medianPos) ele1=nums1[i1];
            if(count==medianPos+1) ele2=nums1[i1];
            i1++;
            count++;
        }
        while(i2<n){
            if(count==medianPos) ele1=nums2[i2];
            if(count==medianPos+1) ele2=nums2[i2];
            i2++;
            count++;
        }
        if((m+n)%2) return ele1;
        else return (ele1+ele2)/2.0;
    }
};

// approach 1 is to create another array of size equal to the sum of the size of the two arrays, sort this new array and find the median. TC->O(n1+n2)log(n1+n2); SC->O(n1+n2)
// approach 2 is find the median element(s) of the array using a merge sort type of algorithm. We won't store the elements of new array. TC-> O(max(n1,n2)); SC-> O(1)
