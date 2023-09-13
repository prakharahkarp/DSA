class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minEle = nums[0], maxEle = nums[0], minElePos = 0, maxElePos = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > maxEle){
                maxEle = nums[i];
                maxElePos = i;
            }
            if(nums[i] < minEle){
                minEle = nums[i];
                minElePos = i;
            }
        }
        int delOpp = 0, delSame1 = 0, delSame2;
        
//         when the two elements to be deleted are nearer to the opposite ends
        delOpp += min(minElePos+1, n - minElePos) + min(maxElePos+1, n - maxElePos);
        
//         when the two elements to be deleted are nearer to one another and hence the deletion take place from one end only
        if(minElePos < maxElePos) delSame1 = maxElePos + 1;
        else delSame1 = minElePos + 1;
        if(n - minElePos < n - maxElePos) delSame2 = n - maxElePos;
        else delSame2 = n - minElePos;
        // cout << delOpp << " " << delSame1 << " " << delSame2 << "\n";
        return min({delOpp, delSame1, delSame2});
    }
};