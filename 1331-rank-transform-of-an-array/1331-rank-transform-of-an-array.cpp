class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)return arr;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        for(int i=0;i<arr.size();i++){
            minHeap.push({arr[i],i});
        }

        int i = 1;
        while(!minHeap.empty()){
            auto topEl = minHeap.top();
            minHeap.pop();
            arr[topEl.second] = i;
            while(!minHeap.empty() && minHeap.top().first== topEl.first){
                arr[minHeap.top().second] = i;
                minHeap.pop();
            }
            i++;
        }

        return arr;
    }
};