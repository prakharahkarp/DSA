class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // why this approach works is because when the loop breaks we will have a winner
//         the winner would have already won 'k' rounds 
//         and if the number of rounds won is less than k, then we would have reached the end of the array and at this point , we would have the largest number in the array and since all elements in our array are distinct, therefore our winner will win all further rounds(and hence will win k consecutive rounds at some point) and hence we don't need to shift the loser to the end of the array.
        int curr = 1, winner = arr[0], consecCount = 0, prevWinner = arr[0];
        while(curr < arr.size()){
            prevWinner = winner;
            winner = max(winner, arr[curr]);
            if(winner == prevWinner) consecCount++;
            else consecCount = 1;
            if(consecCount >= k) break;
            curr++;
        }
        return winner;
    }
};