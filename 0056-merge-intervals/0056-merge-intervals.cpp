class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        int low;
        int high = 0;
        while(high<intervals.size()){
            low = high;
            int MXSecond = intervals[low][1];
            while(high+1<intervals.size() && MXSecond>=intervals[high+1][0]){
                MXSecond = max(MXSecond,intervals[high+1][1]);
                high++;
            }
            ans.push_back({intervals[low][0],MXSecond});

            high++;

        }

        return ans;
    }
};