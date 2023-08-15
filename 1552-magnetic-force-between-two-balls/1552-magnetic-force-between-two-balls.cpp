class Solution {
public:
    bool isGood(int x, vector<int>& position, int m){
        int start=position[0],countBall=1;
        for(int i=1;i<position.size();i++){
            if(position[i]>=start+x){
                start=position[i];
                countBall++;
            }
        }
        return countBall>=m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=0;
        int r=position[position.size()-1]+1;
        while(r>l+1){
            int mid=l+(r-l)/2;
            if(isGood(mid,position,m)) l=mid;
            else r=mid;
        }
        return l;
    }
};