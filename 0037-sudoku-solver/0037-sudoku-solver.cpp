class Solution {
public:

bool check_row(int i, vector<vector<char>>& arr,char num){

    for(int k=0;k<9;k++){
        if(arr[i][k]==num){
            return false;
        }
    }
return true;


}

bool check_col(int j, vector<vector<char>>& arr,char num){

    for(int k=0;k<9;k++){
        if(arr[k][j]==num){
            return false;
        }
    }
return true;
}

bool check_cell(int i, int j,vector<vector<char>>& arr,char num){

    int x=(i/3)*3;
    int y=(j/3)*3;
    
for(int a=x;a<x+3;a++){
        for( int b=y;b<y+3;b++){
            if(arr[a][b]==num){
                return false;
            }
        }
    }
    return true;
}

bool is_safe(int i, int j, vector<vector<char>>& arr, char num) {
    return check_row(i, arr, num) &&
           check_col(j, arr, num) &&
           check_cell(i, j, arr, num);
}
bool fill(vector<vector<char>>& arr){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             if(arr[i][j]=='.'){
                for(char num='1';num<='9';num++){
                    if(is_safe(i,j,arr,num)){
                         arr[i][j] = num;
                          if (fill(arr)) return true;
                          arr[i][j] = '.'; 
                    }
                }
                  return false; 
             }
            
        }
    }
  return true; 

}

    void solveSudoku(vector<vector<char>>& arr) {
        fill(arr);
    }
};