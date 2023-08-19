class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int countEle=0,countRound=0;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(countEle<n*n){
//             traverse right
            for(int i=countRound;i<n-countRound;i++){
                ans[countRound][i]=++countEle;
            }
            if(countEle>=n*n) break;
//             traverse down
            for(int i=countRound+1;i<n-countRound;i++){
                ans[i][n-1-countRound]=++countEle;
            }
            if(countEle>=n*n) break;
//             traverse left
            for(int i=n-countRound-2;i>=countRound;i--){
                ans[n-1-countRound][i]=++countEle;
            }
            if(countEle>=n*n) break;
//             traverse up
            for(int i=n-countRound-2;i>=countRound+1;i--){
                ans[i][countRound]=++countEle;
            }
            countRound++;
        }
        return ans;
    }
};