class Solution {
public:
    string minWindow(string s, string t) {

        int result=INT_MAX;
        vector<int> temp(128, 0), temp1(128, 0);

        for(int i=0;i<t.size();i++){
            int a=t[i]-'A';
            temp[a]++;
    }

        int x,y;
        int count =t.size();

    int left=0,right=0;
    int n=s.length();

    while(right<n){

        int a=s[right]-'A';
        
            temp1[a]++;
        

        if(temp1[a]<=temp[a])count--;



        if(count==0){

           
            while(count==0){
             if(right - left + 1 < result){
                x=left;
                y=right;
                result=min(result,right-left+1);
               }
                int b=s[left]-'A';
                if(temp1[b]>0){
                    temp1[b]--;
                   if(temp1[b] < temp[b]) count++;
                    
                }
                left++;
            }

        }

       
        right++;

    }

    string res="";
    if(result!=INT_MAX){
        for(int i=x;i<=y;i++){
            res+=s[i];
        }
    }
        return res;
    }
};