/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l=-1,r=mountainArr.length();
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)) r=mid;
            else l=mid;
        }
        cout<<r<<"\n";
        int peak=r;
        l=0,r=peak;
        while(r>=l){
            int mid=l+(r-l)/2;
            int currentElement=mountainArr.get(mid);
            if(currentElement==target) return mid;
            else if(currentElement>target) r=mid-1;
            else l=mid+1;
        }
        l=peak+1,r=mountainArr.length()-1;
        while(r>=l){
            int mid=l+(r-l)/2;
            int currentElement=mountainArr.get(mid);
            if(currentElement==target) return mid;
            else if(currentElement>target) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};