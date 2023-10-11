class Solution {
public:
    int countFlowers(vector<int>& time, int arrivalTime){
        int l = 0, r = time.size() - 1, count = 0;
        while(r >= l){
            int mid = l + (r - l)/2;
            if(time[mid] <= arrivalTime){
                count = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return count + 1;
    }
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> startTime(flowers.size(), 0), endTime(flowers.size(), 0), res(people.size(), 0);
        int k = 0;
        for(auto it : flowers){
            startTime[k] = it[0];
            endTime[k++] = it[1];
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        
        for(int i = 0; i < people.size(); i++){
            int bloomingFlowers = 0, bloomedFlowers = 0;
            if(people[i] >= startTime[0]){
                bloomingFlowers = countFlowers(startTime, people[i]);
            }
            if(people[i] > endTime[0]){
                bloomedFlowers = countFlowers(endTime, people[i] - 1);
            }
            // cout<<bloomedFlowers<<" "<<bloomingFlowers<<"\n";
            res[i] = bloomingFlowers - bloomedFlowers;
        }
        // cout<<"yes\n";
        return res;
    }
};