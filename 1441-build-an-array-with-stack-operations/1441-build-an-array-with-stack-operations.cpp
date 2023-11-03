class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int j = 0;
        for(int i = 1; i <= n; i++){
            if(j == target.size()) return ans;
            ans.push_back("Push");
            if(i != target[j]){
                ans.push_back("Pop");
                continue;
            }
            j++;
        }
        return ans;
    }
};