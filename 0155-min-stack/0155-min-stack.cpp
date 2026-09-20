class MinStack {
public:

    stack<int> temp;
    
    stack<int> minTemp;
    MinStack() {
        
    }
    
    void push(int value) {
        temp.push(value);
        

        if(minTemp.empty() || value <= minTemp.top()) {
        minTemp.push(value);
    }
    }
    
    void pop() {
        
         if(!temp.empty()) {

            if(temp.top() == minTemp.top()) {
                minTemp.pop();
            }
            
            temp.pop();
        }
        
    }
    
    int top() {
        return temp.top();
        
    }
    
    int getMin() {
        return minTemp.top();

        // if(temp.size()==1){
        //     return temp.top();
        // }

        // int a=temp.top();
        // temp.pop();
        // int b=getMin();

        //     temp.push(a);
        // return min(a,b);

          
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */