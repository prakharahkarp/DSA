class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minTime = 0, currX = points[0][0], currY = points[0][1];

        for(int i = 1; i < points.size(); i++){
            int nextX = points[i][0], nextY = points[i][1];
            minTime += max(abs(currX - nextX), abs(currY - nextY));
            currX = nextX, currY = nextY;
        }

        return minTime;
    }
};