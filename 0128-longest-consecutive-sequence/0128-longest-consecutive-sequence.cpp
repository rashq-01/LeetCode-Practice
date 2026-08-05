class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;

        unordered_set<int> st(nums.begin(),nums.end());



        for(auto& num : st){
            if(!st.count(num-1)){
                int curr = num;
                int len = 1;
                while(st.count(curr+1)){
                    len++;
                    curr++;
                }
                ans = max(ans,len);
            }
        }

        return ans;
    }
};