class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char result='z';
        bool found=false;
        for(int i=0;i<letters.size();i++){

            if(target<letters[i]){
                found=true;
                result=min(result,letters[i]);
            }

        }

        if(!found){
            return letters[0];
        }
        return result;
        
    }
};