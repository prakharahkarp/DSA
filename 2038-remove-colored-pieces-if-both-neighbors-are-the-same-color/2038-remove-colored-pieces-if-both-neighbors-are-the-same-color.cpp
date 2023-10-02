class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA = 0, countB = 0, consCount = 1;
        char consChar = colors[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == colors[i - 1]){
                consCount++;
                consChar = colors[i];
            } else{
                if(consCount > 2){
                    if(consChar == 'A'){
                        countA += consCount - 2;
                    } else{
                        countB += consCount - 2;
                    }
                }
                consCount = 1;
                consChar = colors[i];
            }
        }
        if(consCount > 2){
            if(consChar == 'A'){
                countA += consCount - 2;
            } else{
                countB += consCount - 2;
            }
        }
        return countA > countB;
    }
};