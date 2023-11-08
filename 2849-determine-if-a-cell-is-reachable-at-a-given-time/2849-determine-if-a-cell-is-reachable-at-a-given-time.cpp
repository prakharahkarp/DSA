class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy) return t != 1;
        int minTime = 0;
        if(abs(sx - fx) > abs(sy - fy)){
            minTime += abs(sy - fy);
            minTime += abs(sx - fx) - abs(sy - fy);
        } else {
            minTime += abs(sx - fx);
            minTime += abs(sy - fy) - abs(sx - fx);
        }
        return minTime <= t;
    }
};