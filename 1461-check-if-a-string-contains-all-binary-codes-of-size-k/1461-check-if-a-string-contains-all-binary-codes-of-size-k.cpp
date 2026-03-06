class Solution {
public:
    bool hasAllCodes(string s, int k) {


            int n=s.length(),i=0;

            int left=0;
            unordered_set<int> tempo;
            long long temp=0;
            int check=(1<<k);
            int mask=(1<<k)-1;

            while(i<n){


                temp=(temp<<1);
                if(s[i]=='1'){
                    temp=temp | 1;
                }
                temp=temp & mask;
                if(i>=k-1){
                    tempo.insert(temp);

                }
                

                    if(tempo.size()==check)return true;
                i++;
            }

            

            return false;
           
       
    }
};