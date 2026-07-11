class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

        for(auto el : mp){
            if(minHeap.size()<k){
                minHeap.push({el.second,el.first});
            }

            else if(mp[minHeap.top().second]< el.second){
                minHeap.pop();
                minHeap.push({el.second,el.first});
            }

        }

        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i] = minHeap.top().second;
            minHeap.pop();
        }

        return ans;
    }
};