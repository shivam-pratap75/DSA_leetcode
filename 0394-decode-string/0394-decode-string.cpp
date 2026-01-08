class Solution {
public:
    string decodeString(string s) {

        int n=s.length();
        stack<int> st;
        stack<string> sts;
        string result="";
        int i=0;
        int num=0;
        while(i<n){

           if(isdigit(s[i])){
            num= num*10+s[i]-'0';
           }else if(s[i]=='['){
            st.push(num);
            sts.push(result);
            num=0;
            result="";
            string temp="";

           }else if(s[i]==']'){
            
            int repeat=st.top();
            st.pop();
            string temp=sts.top();
            sts.pop();

            while(repeat){

                temp+=result;
                repeat--;
            }
            result=temp;

           }else{
            result+=s[i];
           }
           i++;
        }
        return result;
    }
};