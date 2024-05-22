class ATM {
public:
long long put[5];
map<int,int>mp;
    ATM() {
        for(int i=0; i<5; i++){
            put[i]=0;
        }
        mp[0]=20;
        mp[1]=50;
        mp[2]=100;
        mp[3]=200;
        mp[4]=500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++){
            put[i]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        for(int i=4; i>=0; i--){
            if(amount>=mp[i]){
                int c=amount/mp[i];
                if(c>put[i]) c=put[i];
                put[i]-=c;
                amount-=(c*mp[i]);
                ans[i]+=c;
            }
        }
        if(amount==0) return ans;
        else{
            for(int i=0; i<5; i++){
                put[i]+=ans[i];

            }
            vector<int> ans(1,-1);
            return ans;
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
