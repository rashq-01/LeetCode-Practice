class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26,0);
        for(auto& ch : word){
            arr[ch - 'a']++;
        }
        sort(arr.begin(),arr.end(),greater<>());
        int ans = 0;
        for(int i=0;i<8;i++){
            ans +=arr[i];
        }
        for(int i=8;i<16;i++){
            ans += (arr[i]*2);
        }
        for(int i=16;i<24;i++){
            ans += (arr[i]*3);
        }
        ans += (arr[24] *4);
        ans += (arr[25] * 4);


        return ans;
    }
};