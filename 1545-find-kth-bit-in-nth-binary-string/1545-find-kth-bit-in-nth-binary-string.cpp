class Solution {
public:

    string inverte(string temp){

        for(int i=0;i<temp.length();i++){
            if(temp[i]=='0'){
                temp[i]='1';
            }else{
                temp[i]='0';
            }
        }
        return temp;
    }
    string rsev(string temp){
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
    string solve(int n){
        if(n==1)return "0";
        string temp=solve(n-1);
        return temp+"1"+rsev(inverte(temp));
    }
    char findKthBit(int n, int k) {

        string result=solve(n);
        
        return result[k-1];
        
    }
};