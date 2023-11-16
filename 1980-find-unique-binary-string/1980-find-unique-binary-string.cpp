class Solution {
public:
    string findRequiredString(string& str, int n, int& currInd, vector<string>& nums){
        if(str.length() == n){
            if(currInd == nums.size() || nums[currInd++] != str) return str;
            else return "";
        }
        
        str.push_back('0');
        string temp = findRequiredString(str, n, currInd, nums);
        if(temp.size() > 0) return temp;
        str.pop_back();
        
        str.push_back('1');
        temp = findRequiredString(str, n, currInd, nums);
        if(temp.size() > 0) return temp;
        str.pop_back();
        
        return "";
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        sort(nums.begin(), nums.end());
        
        string str = "", ans = "";
        int currInd = 0;
        return findRequiredString(str, nums.size(), currInd, nums);
    }
};