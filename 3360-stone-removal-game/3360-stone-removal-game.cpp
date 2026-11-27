class Solution {
public:
    bool canAliceWin(int n) {
        int removeItem = 10;
        bool isAliceTurn = true;

        while(n>=removeItem){
            n-=removeItem;
            removeItem--;
            isAliceTurn = !isAliceTurn;
        }

        return !isAliceTurn;
    }
};