class Solution {
public:
 char solve(vector<char> &temp,char op,bool is_T,bool is_F){

    if(op=='!'){
        if(temp[0]=='f'){
            return 't';
        }else{
            return 'f';
        }
    }else if(op=='|'){
        if(is_T){
            return 't';
        }else{
            return 'f';
        }
        // for(int i=0;i<temp.size();i++){
        //     if(temp[i]=='t'){
        //         return 't';
        //     }
        // }
        // return 'f';
    }else{
         if(is_F){
            return 'f';
        }else{
            return 't';
        }
        // for(int i=0;i<temp.size();i++){
        //     if(temp[i]=='f'){
        //         return 'f';
        //     }
        // }
        // return 't';
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
                bool is_F =false;
                bool is_T =false;

                while(st.top()!='('){
                    
                    if(st.top()=='f'){
                        is_F=true;
                    }else{
                        is_T=true;
                    }
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solve(temp,op,is_T,is_F));


            }else{
                st.push(expression[i]);
            }

        }
        return st.top() =='t' ;
    }
};