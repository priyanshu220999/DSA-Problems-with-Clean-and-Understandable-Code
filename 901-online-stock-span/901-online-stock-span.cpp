class StockSpanner {
    
    stack<int> stk;
    vector<int> prices;
    int i = 0;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        prices.push_back(price);
        
        int result = 1;
        
        while(!stk.empty() && prices[stk.top()]<=price)
            stk.pop();
        
        result = stk.empty()?i+1:(i-stk.top());
        stk.push(i++);
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */