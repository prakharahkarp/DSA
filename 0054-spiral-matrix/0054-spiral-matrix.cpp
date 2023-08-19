class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int countEle=0,countRound=0;
        vector<int> ans(m*n,0);
        while(countEle<m*n){
//             traverse right
            for(int i=countRound;i<n-countRound;i++){
                ans[countEle++]=matrix[countRound][i];
                cout<<matrix[countRound][i]<<" ";
            }
            if(countEle>=m*n) break;
//             traverse down
            for(int i=countRound+1;i<m-countRound;i++){
                ans[countEle++]=matrix[i][n-1-countRound];
                cout<<matrix[i][n-1-countRound]<<" ";
            }
            if(countEle>=m*n) break;
//             traverse left
            for(int i=n-countRound-2;i>=countRound;i--){
                ans[countEle++]=matrix[m-1-countRound][i];
                cout<<matrix[m-1-countRound][i]<<" ";
            }
            if(countEle>=m*n) break;
//             traverse up
            for(int i=m-countRound-2;i>=countRound+1;i--){
                ans[countEle++]=matrix[i][countRound];
                cout<<matrix[i][countRound]<<" ";
            }
            countRound++;
        }
        return ans;
    }
};