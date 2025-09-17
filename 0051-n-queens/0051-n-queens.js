/**
 * @param {number} n
 * @return {string[][]}
 */
   

let safe=function(matrix,i,j,n){
    let k=i;
    let s=j;

 while(k>0){
    k--;
   if(matrix[k][j]=="Q"){
    return false;
   }
      let k1=i-1;
    let s1=j+1;
while(k1>=0 && s1<=n-1){
    
    if(matrix[k1][s1]=="Q"){
return false;
    }
     k1--;
    s1++;
}
  let k2=i-1;
    let s2=j-1;
while(k2>=0 && s2>=0){
    
    if(matrix[k2][s2]==="Q"){
   return false;
    }
     k2--;
    s2--;
}

 }
return true;

}
  

let first=function(matrix,n,row,result){

if(row===n){
let preresult=[];
    for(let i=0;i<n;i++){
     preresult.push(matrix[i].join(""));
    }
    result.push(preresult);
    return ;
}
  for(let i=0;i<n;i++){
    if(safe(matrix,row,i,n)){
        matrix[row][i]="Q";        
      first(matrix,n,row+1,result);
      
       matrix[row][i] = ".";
    }
     
  }

}






var solveNQueens = function(n) {
    let matrix = [];
    
 let result=[];

    for(let i=0;i<n;i++){
        matrix[i]=[];
        for(let j=0;j<n;j++){
            matrix[i][j]='.';
        }
    }

    first(matrix,n,0,result);
  
return result;
};