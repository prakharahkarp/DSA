class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int left=(m+n+1)/2;
        int l=0, r=m;
        while(r>=l){
            int mid=l+(r-l)/2;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid<m) r1=nums1[mid];
            if(left-mid<n) r2=nums2[left-mid];
            if(mid-1>=0) l1=nums1[mid-1];
            if(left-mid-1>=0) l2=nums2[left-mid-1];
            if(l1<=r2&&l2<=r1){
                if((m+n)%2) return max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
};

// approach 1 is to create another array of size equal to the sum of the size of the two arrays, sort this new array and find the median. TC->O(n1+n2)log(n1+n2); SC->O(n1+n2)
// approach 2 is find the median element(s) of the array using a merge sort type of algorithm. We won't store the elements of new array. TC-> O(n1+n2); SC-> O(1)


// approach 3 is to use binary search to find the number of elements from each array contained in the first half of the new array and we will use this to find the median
// we consider that each array has (m+n+1)/2 elements on the left half and the remaining on the right
// we just have to make sure that there are equal number of elements on both sides in case the total number of elements is even and in such a case, the median would be between these two elements.
// in case the total number of elements is even, we just have to make sure that we make a division such that there is just one element more on either side and the extra element at last in left half or the first element at the begining in right half is the median.
// we do a binary search on any array(preferabley shorter) to find the number of elements that this array contributes to either half of array(0-n) and then we find the median

//    ........l1 r1........
                              // (l1<=r2&&l2<=r1)
//    ......l2 r2......
