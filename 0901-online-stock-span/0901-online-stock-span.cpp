class StockSpanner {
public:
  stack<pair<int,int>>s;
  int index=0;
  int ans ;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!s.empty()&& s.top().first<=price){
            s.pop();
        }
        if(s.empty()){
            ans=index+1;
        }else{
            ans=index-s.top().second;
        }
        s.push({price,index});
        index++;
        return ans ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */