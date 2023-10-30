class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        long long val = 1;
        row.push_back(val);
        for(int i = 0; i < rowIndex; i++){
            val *= (rowIndex - i);
            val /= (i + 1);
            row.push_back(val);
        }
        return row;
    }
};