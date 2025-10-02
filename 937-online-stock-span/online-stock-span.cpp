class StockSpanner {
public:
    vector<int> arr;
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int ind=arr.size()-1;
        while(!st.empty() && arr[st.top()]<=arr[ind]){
            st.pop();
        }
        int ans=0;
        if(st.empty()) ans=ind+1;
        else ans=abs(st.top()-ind);
        st.push(ind);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */