class ProductOfNumbers {
public:
    vector<long long> prod;
    long long currProd = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        prod.push_back(num);
    }
    
    int getProduct(int k) {
       long long ans = 1;
       for(int i=prod.size()-1;i>=0 && k;i--,k--){
        ans *= prod[i];
       } 
       return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */