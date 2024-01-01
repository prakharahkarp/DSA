class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0, j = s.size() - 1;
        for(int i = (int)g.size() - 1; i >= 0; i--){
            if(j < 0) break;
            if(g[i] <= s[j]){
                count++;
                j--;
            }
        }
        return count;
    }
};