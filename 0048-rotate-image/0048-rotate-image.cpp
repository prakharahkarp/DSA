class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void revRow(vector<int>& row){
        int i=0,j=row.size()-1;
        while(i<j){
            swap(row[i],row[j]);
            i++;
            j--;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i=0;i<matrix.size();i++){
            revRow(matrix[i]);
        }
    }
};