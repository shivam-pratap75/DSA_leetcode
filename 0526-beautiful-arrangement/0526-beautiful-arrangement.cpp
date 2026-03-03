class Solution {
    int count = 0;
public:
    void solve(vector<bool>& result,int& n,int start){

        if(start>n){
            count++;
            return ;
        }


        for(int i=1;i<=n;i++){

            if(!result[i] &&( start%i==0 || i%start==0)){
                result[i]=true;
                solve(result,n,start+1);
                result[i]=false;
            }
        }
    }
    int countArrangement(int n) {

  vector<bool>result(n+2,false);
  solve(result,n,1);  
  return count;    
    }
};