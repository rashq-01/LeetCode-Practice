class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int ans = 0;
        int arr[26] = {0};

        for(int i=0,j=0;i<n;i++){
            bool status = false;
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']>2){
                status = true;
            }

            while(status){
                if(arr[s[j]-'a']>2)status = false;

                arr[s[j++]-'a']--;
            }
            ans = max(ans,i-j+1);
        }

        return ans;
    }
};