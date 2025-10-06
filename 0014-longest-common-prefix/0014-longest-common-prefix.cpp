class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n=strs.size();
        if(n==0){
            return "";
        }
        string result=strs[0];
        int n1=strs[0].size();
        int k;

       
        for(int i=0;i<n;i++){
            k=0;
            string temp="";
            if(strs[i].size()==0 || result.size()==0){
                return "";
            }
         for(int j=0;j<strs[i].size();j++){
               if(strs[i][j]==result[k]){
                temp+=strs[i][j];

               }else{
                break;
               }
               k++;
               
            }
            result=temp;
            
        }

        return result;
    }
};