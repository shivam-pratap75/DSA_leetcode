class Solution {
public:
 char solve(vector<char> &temp,char op){

    if(op=='!'){
        if(temp[0]=='f'){
            return 't';
        }else{
            return 'f';
        }
    }else if(op=='|'){
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='t'){
                return 't';
            }
        }
        return 'f';
    }else{
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='f'){
                return 'f';
            }
        }
        return 't';
    }

    return 'f';



 }
    bool parseBoolExpr(string expression) {
        int n=expression.length();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(expression[i]==',') continue;
            if(expression[i]==')'){
                vector<char> temp;

                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solve(temp,op));


            }else{
                st.push(expression[i]);
            }

        }
        return st.top() =='t' ;
    }
};