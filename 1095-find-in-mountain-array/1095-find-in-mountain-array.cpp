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
        
        // finding peak index
        int len = mountainArr.length();
        int l = 1, r = len - 2; // as our peak index can not be 0 or len - 1(given)
        int peakInd = -1;
        while(r >= l){
            int mid = l + (r - l)/2;
            int ele1 = mountainArr.get(mid - 1), ele2 = mountainArr.get(mid), ele3 = mountainArr.get(mid + 1);
            if(ele1 < ele2 && ele2 > ele3){
                peakInd = mid;
                break;
            }
            else if(ele1 < ele2 && ele2 < ele3){
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(mountainArr.get(peakInd) == target) return peakInd;
        
        // searching in the increasing array
        l = 0, r = peakInd - 1;
        while(r >= l){
            int mid = l + (r - l)/2;
            int ele = mountainArr.get(mid);
            if(ele == target) return mid;
            else if(ele < target) l = mid + 1;
            else r = mid - 1;
        }
        
//         searching in the decreasing array
        l = peakInd + 1, r = len - 1;
        while(r >= l){
            int mid = l + (r - l)/2;
            int ele = mountainArr.get(mid);
            if(ele == target) return mid;
            else if(ele < target) r = mid - 1;
            else l = mid + 1;
        }
        
//         element not found 
        return -1;
    }
};