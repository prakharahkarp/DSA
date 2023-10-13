//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void helper(int N, int from, int to, int aux, long long& totalSteps){
        if(N == 1){
            cout << "move disk " << N << " from rod " << from << " to rod " << to <<"\n";
            totalSteps++;
            return ;
        }
        // helper(N - 1, from, aux, to, ++totalSteps);
        // cout << "move disk " << N << " from rod " << from << " to rod " << to <<"\n";
        // helper(N - 1, aux, to, from, ++totalSteps);
        
        // earlier we were incrementing totalsteps multiple times for one valid move(while placing the n-1 discs on top of the nth to be specific) and hence our answer
        // was greter than the correct answer(greater by n-1) to be specific
        // the new code increases totalsteps once for each valid move
        
        helper(N - 1, from, aux, to, totalSteps);
        cout << "move disk " << N << " from rod " << from << " to rod " << to <<"\n";
        totalSteps++;
        helper(N - 1, aux, to, from, totalSteps);
    }
    
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long totalSteps = 0;
        helper(N, from, to, aux, totalSteps);
        return totalSteps;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends