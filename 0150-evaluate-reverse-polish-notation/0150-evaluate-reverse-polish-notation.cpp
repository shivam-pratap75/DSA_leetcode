
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                int num2 = s.top(); 
                s.pop();  
                int num1 = s.top(); 
                s.pop();  
                int result = 0;
                
                if (token == "+") {
                    result = num1 + num2;
                } 
                else if (token == "-") {
                    result = num1 - num2;  
                } 
                else if (token == "*") {
                    result = num1 * num2;
                } 
                else if (token == "/") {
                    result = num1 / num2;
                }
                
                s.push(result);
            } 
            else {
                
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
};