class Solution {
public:
    int myAtoi(string s) {

    int n=s.size();
    int result=0;
    int sign =1;
    int i=0;
    int int_max = INT_MAX;
    int int_min = INT_MIN;

   while(i<n){

   if(s[i]==' '){
    i++;

   }else if(s[i]=='-'){
    sign=-1;
    i++;
    break;
   }else if(s[i]=='+'){
    i++;
    break;
   }else{
    break;
   }

   }

   while(s[i]=='0'){
    i++;
   }
 
 while(i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            
            if(result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            result = result * 10 + digit;
            i++;
        }
return sign * result;

    }
};