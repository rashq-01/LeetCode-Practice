class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i=0;i<arr1.size();i++){
            int num1 = arr1[i];
            bool status = true;

            for(int j=0;j<arr2.size();j++){
                int num2 = arr2[j];
                if(abs(num1 - num2) <= d){
                    status = false;
                    break;
                }
            }

            if(status)ans++;
        }

        return ans;
    }
};