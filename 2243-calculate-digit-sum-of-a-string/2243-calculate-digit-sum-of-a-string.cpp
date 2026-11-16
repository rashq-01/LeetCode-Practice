class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k){
            int sum = 0;
            string ans = "";
            int curr = 0;
            for(int i=0;i<s.size();i++){
                sum += (s[i] - '0');
                curr++;
                if(curr == k){
                    curr = 0;
                    ans += to_string(sum);
                    sum = 0;
                }
            }
            if(curr>0)ans += to_string(sum);
            s = ans;
        }

        return s;
    }
};