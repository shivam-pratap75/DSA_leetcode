class Solution {
public:
    int findTheLongestSubstring(string s) {

        int result=0;

        unordered_map<int,int> temp;
        temp[0]=-1;
        int mask=0;
        for(int i=0;i<s.size();i++){

            char ch=s[i];

            if(ch=='a'){
                mask=mask ^ (1<<0);
            }else if(ch=='e'){
                    mask = mask^ (1<<1);
            }else if(ch=='i'){
                    mask=mask ^ (1<<2);
            }else if(ch=='o'){
                mask=mask^(1<<3);
                
            }else if(ch=='u'){
                mask=mask^(1<<4);
            }

            if(temp.count(mask)){
                result=max(result,i-temp[mask]);

            }else{
                temp[mask]=i;
            }
        }
        return result;
    }
};