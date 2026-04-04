class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int n=encodedText.size();

        if(rows==1)return encodedText;

        int col=n/rows;

        string result;
        result.reserve(n);
        for(int i=0;i<col;i++){
            int a=0,b=i;

            while(a<rows && b<col){
                result+=encodedText[a*col+b];
                a++;
                b++;
            }
        }

        while(!result.empty() && result.back()==' '){
            result.pop_back();
        }
        return result;
    }
};