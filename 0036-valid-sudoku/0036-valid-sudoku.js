/**
 * @param {character[][]} board
 * @return {boolean}
 */

var check_row=function(i,j,board){

for(let k=0;k<9;k++){
    if(k==j){
        continue;
    }
    if(board[i][k]==board[i][j]){
        return false;
    }
  
}
  return true;
}
var check_col=function(i,j,board){
    
for(let k=0;k<9;k++){
    if(k==i){
        continue;
    }
    if(board[k][j]==board[i][j]){
        return false;
    }
   
}
  return true;   
}
var check_box=function(i,j,board){
let a= Math.floor(i/3)*3;
let b= Math.floor(j/3)*3;
for(let x=a;x<a+3;x++){
    for(let y=b;y<b+3;y++){
        if(x==i && y==j){
            continue;
        }
        if(board[x][y]==board[i][j]){
            return false;
        }
    }
}
return true;

}
var is_safe=function( i, j,board){
    return check_row(i,j,board) && check_col(i,j,board) && check_box(i,j,board);
}
var isValidSudoku = function(board) {
    
for(let i=0;i<9;i++){
    for(let j=0;j<9;j++){
        if(board[i][j]=='.'){

        }else if(is_safe(i,j,board)){

        }else{
            return false;
        }
    }
}

return true;

};