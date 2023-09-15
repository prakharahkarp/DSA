class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n == 0) return ans;
        int curr = 1;
        for(int i = 1; i <= n; i++){
            if(i == curr*2){
                ans.push_back(1);
                curr = i;
            }
            else{
                ans.push_back(1+ans[i%curr]);
            }
        }
        return ans;
    }
};