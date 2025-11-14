class Solution {
public:



    void operation(vector<vector<int>>& result,int i,int j,int k, int l){

        for(int a=i;a<=k;a++){
            for(int b=j;b<=l;b++){
                result[a][b]++;
            }
        }

        

    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>> result(n,vector<int>(n,0));

        for(int i=0;i<queries.size();i++){
            operation(result,queries[i][0],queries[i][1],queries[i][2],queries[i][3]);
        }




    return result;
        
    }
};