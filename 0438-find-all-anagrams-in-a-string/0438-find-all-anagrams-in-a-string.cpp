class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;
        int left=0,right=0;
        int n=s.size();
        int k=p.size();
        vector<int> temp(26,0),temp1(26,0);

        for(char ch:p){
            int a=ch-'a';
            temp[a]++;
        }

        while(right<n){
            int a=s[right]-'a';
            temp1[a]++;
            
            if(right-left+1 > k){
                int b=s[left]-'a';
                temp1[b]--;
                left++;
            }


            if(temp==temp1)result.push_back(left);
            right++;
        }



        return result;
        
    }
};