class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> mp;
        for(int i=0;i<row.size();i++){
            mp[row[i]] = i;
        }

        int swapCount = 0;
        for(int i=0;i<row.size();i+=2){
            int first = row[i];
            int second = row[i]%2==0 ? row[i]+1 : row[i] - 1;

            if(row[i+1] != second){
                swapCount++;
                int nextIdx = i+1;
                int replaceIdx = mp[second];

                swap(row[nextIdx],row[replaceIdx]);

                mp[row[nextIdx]] = nextIdx;
                mp[row[replaceIdx]] = replaceIdx;
            }
        }

        return swapCount;
    }
};