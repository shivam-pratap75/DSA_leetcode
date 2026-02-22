class Solution {
public:

    string tobinary(int n){
        string result="";

        while(n>0){
            int a=n%2;
            n=n/2;
            result+=a;
        }

        reverse(result.begin(),result.end());
        return result;
    }
    int binaryGap(int n) {

        string temp=tobinary(n);
        int c1=-1,c2=-1;
        int result=0;
        for(int i=0;i<temp.length();i++){
            if(temp[i]==1){
                c1=c2;
                c2=i;
            }
            if(c1 !=-1 && c2 !=-1){
                result=max(result,c2-c1);
            }


        }
        return result;
    }
};