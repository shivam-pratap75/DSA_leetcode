class Solution {
public:

    void left(vector<vector<int>>& mat,int k,int x,int y,vector<vector<int>>& temp){

            int m=mat[0].size();
            for(int i=0;i<mat[0].size();i++){
                temp[x][i]=mat[x][(k+i)%m];
            }
           

    }

    void right(vector<vector<int>>& mat,int k,int x,int y,vector<vector<int>>& temp){

        int m=mat[0].size();

        for(int i=0;i<mat[0].size();i++){
                temp[x][i]=mat[x][(i-k+m)%m];
            }

            
        
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int n=mat.size();
        int m=mat[0].size();
        k=k%m;
        vector<vector<int>>temp(n,vector<int>(m,0));
       

        for(int i=0;i<mat.size();i++){
            if(i%2==0){
                left(mat,k,i,0,temp);
            }else{
                right(mat,k,i,0,temp);
            }

            if(temp[i]!=mat[i])return false;
        }

        return mat==temp ? true : false;
        
    }
};