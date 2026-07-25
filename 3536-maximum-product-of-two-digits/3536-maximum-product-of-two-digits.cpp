class Solution {
public:
    int maxProduct(int n) {
        int product;
        vector<int> store;
        while(n!=0){
            store.push_back(n%10);
            n/=10;
        }
        if(store.size()==1) product = n;
        if(store.size()==2) product=store[0]*store[1];
        else{
            sort(store.rbegin(), store.rend());
            product = store[0]*store[1];
        }
        return product;
    }
};