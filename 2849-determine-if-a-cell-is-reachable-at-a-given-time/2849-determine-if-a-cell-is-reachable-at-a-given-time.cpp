class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
//         the most optimal way to reach destination from source is to travel via diagonals
//         if our minTime < t, then we will always have an alternate path in our infinite grid to reach the target in t time
//         the only case where this fails is when the source and destination points are same, i.e. we dont have to travel, in such a case we case go on a roundabout trip, visiting some cells multiple times to reach our destination at exact time but if our t == 1, then we will go on a neighbouring cell, but won't be able to traverse back
        if(sx == fx && sy == fy) return t != 1;
        int minTime = 0;
        if(abs(sx - fx) > abs(sy - fy)){
//             time take to reach the destination source or column via diagonals
            minTime += abs(sy - fy);
//             time required to cover the remaining path via the x or y axis
            minTime += abs(sx - fx) - abs(sy - fy);
        } else {
            minTime += abs(sx - fx);
            minTime += abs(sy - fy) - abs(sx - fx);
        }
        return minTime <= t;
    }
};