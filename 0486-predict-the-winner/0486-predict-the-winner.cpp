class Solution {
public:
    long long player1Score(int i,bool isPlayer1Turn,vector<int>& nums,int lastIdx){
        if(i>lastIdx)return 0;

        long long takeFirst,takeLast;
        if(isPlayer1Turn){
            takeFirst = (long long)nums[i] + player1Score(i+1,false,nums,lastIdx);
            takeLast = (long long)nums[lastIdx] + player1Score(i,false,nums,lastIdx-1);
            return max(takeFirst,takeLast);
        }

        takeFirst = player1Score(i+1,true,nums,lastIdx);
        takeLast = player1Score(i,true,nums,lastIdx-1);
        

        return min(takeFirst,takeLast);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        if(n==1)return true;

        long long totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += (long long)nums[i];
        }

        long long p1Score = player1Score(0,true,nums,n-1);
        long long p2Score = totalSum - p1Score;

        if(p1Score>=p2Score)return true;

        return false;

    }
};