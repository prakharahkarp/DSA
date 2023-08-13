class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0,r=arr.size()-1;
        while(r>l){
            int mid=l+(r-l)/2;
            if(arr[mid]-mid-1>=k) r=mid;
            else l=mid+1;
        }
        int start=arr[r],missingCnt=arr[r]-r-1;
        if(missingCnt<k) return start+(k-missingCnt);
        return start-(missingCnt-k+1);
    }
};

// we will apply binary search on the array to find the minimum position at which the number of missing elements in the array is greater than or equal to k
// number of missing elements before arr[i]=arr[i]-i-1