class ATM {
public:
    
     vector<int>v={20, 50, 100, 200,500};
    vector<long long>atm={0,0,0,0,0};
    ATM() {
        
    }
    
    void deposit(vector<int> bC) {
        for(int i=0;i<5;i++)atm[i]+=bC[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int>ret(5),mn={-1};
        for (int i = 4; i >= 0; --i) {
            ret[i] = min(atm[i], (long long)amount / v[i]);
            amount -= ret[i] * v[i];
        }
        if(amount) return {-1};
        else 
            for(int i=0;i<5;i++)atm[i]-=ret[i];
        return ret;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */