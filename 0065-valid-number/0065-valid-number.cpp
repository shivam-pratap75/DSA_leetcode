class Solution {
public:
    bool isNumber(string s) {
   int n=s.size();
   int i=0;
   int check_dot=0,check_e=0;
   int check_e2=0;
   if(s[i]=='-' || s[i]=='+'){
    i++;
   }else if(s[i]=='e' ||s[i]=='E'){
    return false;
   }



   for(i;i<n;i++){
   if(s[i]>='0' && s[i]<='9'){
         check_e2=1;
   }else if(s[i]=='e' || s[i]=='E'){
    if(check_e2==0){
       return false; 
    }
     check_e2=0;
     if(check_e!=0){
        return false;
     }else{
        check_e++;
     }

   }else if(s[i]=='.'){
     if(check_dot!=0 || check_e!=0){
        return false;
     }else{
        check_dot++;
     } 
     
   }else if(s[i]=='+' || s[i]=='-'){
    
    if(s[i-1]=='e' ||s[i-1]=='E'){

    }else{
        return false;
    }
   }else{
    return false;
   }





   }
if(check_e2==0){
    return false;
}else{
    return true;
}

        
    }
};