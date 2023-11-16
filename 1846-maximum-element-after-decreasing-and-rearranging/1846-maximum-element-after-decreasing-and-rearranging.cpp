class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        cout << arr.size() <<"\n";
        unordered_map<int, int> frequencies;
        for(auto it : arr) frequencies[it]++;
        
        int expectedVal = 1, traversedElements = 0;
        while(traversedElements < arr.size()){
            if(frequencies.count(expectedVal)) traversedElements += frequencies[expectedVal];
            else traversedElements++;
            
            expectedVal++;
        }
        cout << traversedElements << "\n";
        if(traversedElements > arr.size()) return expectedVal;
        return expectedVal - 1;
    }
};