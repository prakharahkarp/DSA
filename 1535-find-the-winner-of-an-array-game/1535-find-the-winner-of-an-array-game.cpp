class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = 1, winner = arr[0], consecCount = 0, prevWinner = arr[0];
        while(curr < arr.size()){
            if(arr[curr] > winner){
                prevWinner = winner;
                winner = arr[curr];
                consecCount = 1;
            } else {
                consecCount++;
            }
            if(consecCount >= k) break;
            cout << curr << " " << winner << "\n";
            curr++;
        }
        return winner;
    }
};