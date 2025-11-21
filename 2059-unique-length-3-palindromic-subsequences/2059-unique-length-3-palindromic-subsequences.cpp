class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int,int> freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        int result=0;
        
        for(int left=0;left<n;left++){
            int right=n-1;
            if(freq[s[left]]>=2){
                while(right > left && s[right] != s[left]){
                    right--;
                }
                if(right > left) {  
                    unordered_set<char> val(s.begin()+left+1,s.begin()+right);
                    result += val.size();  
                }
                freq[s[left]]=0;
            }
        }
        return result;
    }
};