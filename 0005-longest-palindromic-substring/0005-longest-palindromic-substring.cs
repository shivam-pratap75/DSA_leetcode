public class Solution {

    public (int,int) check(string s,int left,int right){

        while(left>=0 && right<s.Length){
            if(s[left]!=s[right]){
               break;
            }
            left--;
            right++;
        }
        return (left+1,right-1);
    }
    public string LongestPalindrome(string s) {
        
        int start=0;
        int maxlength=0;

        for(int i=0;i<s.Length;i++){
            var odd=check(s,i,i);
            var even=check(s,i,i+1);

            int oddlength=odd.Item2 - odd.Item1 + 1;
            int evenlength=even.Item2 - even.Item1 + 1;

            if(oddlength>maxlength){
                maxlength=oddlength;
                start=odd.Item1;
            }

            if(evenlength>maxlength){
                maxlength=evenlength;
                start=even.Item1;
            }

        }


        return s.Substring(start,maxlength);
    }
}