class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> wid_ht_ratio;
        for(int i = 0; i < rectangles.size(); i++){
            double temp = (double)rectangles[i][0] / rectangles[i][1];
            wid_ht_ratio[temp]++;
        }
        long long total_pairs = 0;
        for(auto it : wid_ht_ratio){
            total_pairs += (long long)it.second * (it.second - 1) / 2;
        }
        return total_pairs;
    }
};