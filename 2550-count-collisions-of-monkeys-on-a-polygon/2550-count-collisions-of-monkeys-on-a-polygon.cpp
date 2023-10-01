class Solution {
public:
    int monkeyMove(int n) {
//         every monkey has two options, to move clockwise or anticlockwise
//        so there are a total of 2^n possibilites or ways of monkey movements and no collission occurs if all monkeys move in the same direction. So there are two possibilties of no collission -> when all monkeys move in clockwise direction and when all monkeys move in anti clockwise direction
        long long res = 1, x = 2;
        while(n > 0){
            if(n % 2){
                // If n is odd, multiply res with x and take modulo 1000000007
                res = (res % 1000000007 * x % 1000000007) % 1000000007;
            }
            // Square x and take modulo 1000000007
            x = (x % 1000000007 * x % 1000000007) % 1000000007;
            n /= 2; // Right shift n by 1, equivalent to n = n / 2
        }
        // Subtract 2 from the final result and return
        return (res - 2 + 1000000007) % 1000000007;
    }
};