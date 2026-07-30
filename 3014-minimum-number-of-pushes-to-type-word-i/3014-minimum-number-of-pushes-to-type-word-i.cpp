class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int count = 0;
        int i = 1;
        while(n>8){
            count += (i*8);
            i++;
            n-=8;
        }
        count+= (i*n);


        return count;
    }
};