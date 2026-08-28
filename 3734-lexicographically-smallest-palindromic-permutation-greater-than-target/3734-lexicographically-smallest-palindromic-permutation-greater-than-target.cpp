class Solution {
public:
    string res = "";
    bool solve(int i, string& curr, string& target, vector<int>& freq, bool isGreater, bool isEven, int n) {
        if ((isEven && i >= n / 2) || (!isEven && i > n / 2)) {

    string palindrome = curr;

    if (!isEven) {
        char middle = palindrome.back();
        palindrome.pop_back();

        string right = palindrome;
        reverse(right.begin(), right.end());

        palindrome += middle;
        palindrome += right;
    }
    else {
        string right = palindrome;
        reverse(right.begin(), right.end());

        palindrome += right;
    }

    if (palindrome > target) {
        res = palindrome;
        return true;
    }

    return false;
}

        for (int ch = 'a'; ch <= 'z'; ch++) {
            if (!isEven && i == n / 2) {
                if (freq[ch - 'a'] < 1)
                    continue;
            }
            else {
                if (freq[ch - 'a'] < 2)
                    continue;
            }
            if (!isGreater && ch < target[i])continue;

            bool nextGreater = isGreater;

            if(!nextGreater && ch>target[i])nextGreater = true;


            curr.push_back(ch);

            if (!isEven && i == n / 2) {
                freq[ch - 'a']--;
            }
            else {
                freq[ch - 'a'] -= 2;
            }

            if (solve(i + 1, curr, target,
                      freq, nextGreater, isEven, n))
                return true;

            curr.pop_back();

            if (!isEven && i == n / 2) {
                freq[ch - 'a']++;
            }
            else {
                freq[ch - 'a'] += 2;
            }
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        string curr = "";
        vector<int> freq(26, 0);
        for (auto& ch : s)
            freq[ch - 'a']++;
        
        int oddCount = 0;
        for(int i=0;i<26;i++){
            if(freq[i]%2 == 1)oddCount++;
            if(oddCount>1)return "";
        }
        bool isEven = (s.size() % 2) == 0;
        if (solve(0, curr, target, freq, false, isEven, n))
            return res;

        return "";
    }
};