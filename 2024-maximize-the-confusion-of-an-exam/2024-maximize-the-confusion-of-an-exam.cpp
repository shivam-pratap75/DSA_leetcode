class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int countf=0,countt=0;
        int leftf=0,leftt=0;
        int result=0;

        for(int i=0;i<answerKey.size();i++){

            if(answerKey[i]=='T')countf++;
            if(answerKey[i]=='F')countt++;

            if(countf>k){
                while(countf>k){
                    if(answerKey[leftf]=='T')countf--;
                    leftf++;
                }
            }

            if(countt>k){
                while(countt>k){
                    if(answerKey[leftt]=='F')countt--;
                    leftt++;
                }
            }

            int num1=i-leftf+1;
            int num2=i-leftt+1;

    result=max(result,max(num1,num2));



        }

        return result;
    }
};