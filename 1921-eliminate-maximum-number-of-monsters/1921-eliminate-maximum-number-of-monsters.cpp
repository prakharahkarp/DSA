class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time(dist.size(), 0);
        int minDist = *min_element (dist.begin(), dist.begin());
        for(int i = 0; i < dist.size(); i++){
            time[i] = (double)(dist[i])/speed[i];
        }
        sort(time.begin(), time.end());
        int countDefeatedMonsters = 0;
        for(int t = 0; t < time.size(); t++){
            if(time[t] > t)  countDefeatedMonsters++;
            else break;
        }
        return countDefeatedMonsters;
    }
};