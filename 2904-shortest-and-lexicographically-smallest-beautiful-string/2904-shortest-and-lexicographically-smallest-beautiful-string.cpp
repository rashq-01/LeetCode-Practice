class Solution {
public:
    string compare(string& s1, string& s2){
        if(s1.size()<s2.size())return s1;
        if(s2.size()<s1.size())return s2;

        for(int i=0;i<s1.size();i++){
            if(s1[i]<s2[i])return s1;
            if(s2[i] < s1[i])return s2;
        }
        return s1;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";

        int count = 0;
        
        for(int i=0,j=0;i<n;i++){
            while(i<n && count<k){
                if(s[i]=='1')count++;
                if(count==k)break;
                i++;
            }
            while(count==k){
                string sub = s.substr(j,i-j+1);
                if(ans.size()==0){
                    ans = sub;
                }
                else{
                    ans = compare(sub,ans);
                }

                if(s[j]=='1')count--;
                j++;
            }
            
        }

        return ans;
    }
};