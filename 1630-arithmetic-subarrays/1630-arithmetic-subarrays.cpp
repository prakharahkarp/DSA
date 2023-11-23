class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int start=l[i],end=r[i],smallest=INT_MAX,largest=INT_MIN;
            for(int j=start;j<=end;j++){
                smallest=min(smallest,nums[j]);
                largest=max(largest,nums[j]);
            }
            if(smallest==largest){
                ans.push_back(true);
                continue;
            }

            if((largest-smallest)%(end-start)){
                ans.push_back(false);
                continue;
            }
            int commonDiff=(largest-smallest)/(end-start);
            unordered_set<int> s;
            for(int j=start;j<=end;j++){
                int val=nums[j]-smallest;
                if(!(val%commonDiff)) s.insert(val);
            }
            ans.push_back(s.size()==end-start+1);
        }
        return ans;
    }
};