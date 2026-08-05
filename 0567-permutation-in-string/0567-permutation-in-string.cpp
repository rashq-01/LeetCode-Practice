class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2)return false;

        vector<int> C1(26,0),C2(26,0);
        for(auto& ch : s1)C1[ch-'a']++;
        for(int i=0;i<n1;i++)C2[s2[i]-'a']++;

        if(C1==C2)return true;

        for(int i=n1;i<s2.size();i++){
            C2[s2[i]-'a']++;
            C2[s2[i-n1]-'a']--;

            if(C1==C2)return true;
        }


        return false;


    }
};