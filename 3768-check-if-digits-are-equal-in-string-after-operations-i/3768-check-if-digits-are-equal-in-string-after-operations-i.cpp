class Solution {
public:

    string operation(string a){
        string s="";
        for(int i =0;i<a.size()-1;i++){
        int k=a[i] -'0';
        int l=a[i+1]-'0';
        int sum=(k+l)%10;
        s += (sum + '0');
        }
        return s;

    }

    bool hasSameDigits(string s) {


        while(s.size()>2){
            s= operation(s);
            
        }

        if(s.size()==2 && s[0]==s[1]){
            return true;

        }else{
            return false;
        }
        
    }
};