class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowDigit = 0;
        int L = low;
        while(L){
            lowDigit++;
            L/=10;
        }
        int highDigit = 0;
        int H = high;
        while(H){
            highDigit++;
            H/=10;
        }
        vector<int> ans;

        while(lowDigit<=highDigit){
            string str = "123456789";
            for(int i=0;i+lowDigit<=str.size();i++){
                if(stoi(str.substr(i,lowDigit)) >= low && stoi(str.substr(i,lowDigit)) <= high){
                    ans.push_back(stoi(str.substr(i,lowDigit)));
                }
            }
            lowDigit++;
        }

        return ans;
        
    }
};