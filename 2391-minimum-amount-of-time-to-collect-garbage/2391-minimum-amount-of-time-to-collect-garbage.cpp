class Solution {
public:
    int findTime(vector<string>& garbage, vector<int>& travel, char ch){
        
        int totalTime = 0, pickTime = 0, travelTime = 0, houseInd = 0;
        // cout << ch << "\n";
        for(auto waste : garbage){
            
            int pickTime = 0;
            
            for(auto cateogory : waste){
                if(cateogory == ch) pickTime++;
            }
            
            totalTime += pickTime;
            
            if(pickTime){
                totalTime += travelTime;
                travelTime = 0;
            }
            
            if(houseInd == travel.size()) break;
            travelTime += travel[houseInd++];
            // cout << totalTime << " " << pickTime << " " << travelTime << "\n";
        }
        
        return totalTime;
    }
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        return findTime(garbage, travel, 'G') + findTime(garbage, travel, 'M') + findTime(garbage, travel, 'P');
    }
};