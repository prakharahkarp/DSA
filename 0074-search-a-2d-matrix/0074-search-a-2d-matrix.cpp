class Solution {
public:
    bool binSearchinRow(vector<vector<int>>& matrix, int l, int r,int row, int target){
        while(r>l){
            int mid=l+(r-l)/2;
            if(matrix[row][mid]>=target) r=mid;
            else l=mid+1;
        }
        return (matrix[row][r]==target||matrix[row][l]==target);
    }
    
    int binSearchinCol(vector<vector<int>>& matrix, int l, int r,int col, int target){
        while(r>l){
            int mid=l+(r-l)/2;
            if(matrix[mid][col]>target) r=mid;
            else l=mid+1;
        }
        return r;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1;
        int row=binSearchinCol(matrix, l, r, 0, target);
        if(matrix[row][0]==target) return true;
        if(matrix[row][0]>target) row--;
        if(row<0) return false;
        l=0,r=matrix[row].size()-1;
        return binSearchinRow(matrix, l, r, row, target); 
    }
};