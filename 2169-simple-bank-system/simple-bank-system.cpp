class Bank {
public:
    vector<long long> real;
    Bank(vector<long long>& balance) {
        real=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1-1>=real.size() || account2-1>=real.size()) return false;
        if(real[account1-1]>=money){
            real[account1-1]-=money;
            real[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account-1>=real.size()) return false;
        real[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account-1>=real.size()) return false;
        if(real[account-1]>=money){
            real[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */