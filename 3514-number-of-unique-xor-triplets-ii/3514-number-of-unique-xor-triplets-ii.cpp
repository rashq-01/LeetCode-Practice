class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> doubleXOR(2049,false);
        vector<bool> tripleXOR(2049,false);

        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                doubleXOR[(nums[i] ^ nums[j])] = true;
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<2049;j++){
                if(doubleXOR[j]){
                    tripleXOR[j ^ nums[i]] = true;
                }
            }
        }
        int count = 0;
        
        for(int i=0;i<2049;i++){
            if(tripleXOR[i])count++;
        }

        return count;
    }
};