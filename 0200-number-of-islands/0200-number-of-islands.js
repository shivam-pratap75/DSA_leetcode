/**
 * @param {character[][]} grid
 * @return {number}
 */


var numIslands = function(grid) {
    let count=0;
    
function calculate(i,j){
    if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] === '0') {
        return; 
    }
  
  grid[i][j]="0";
  calculate(i+1,j);
  calculate(i,j+1);
  calculate(i-1,j);
  calculate(i,j-1);


}

for(let i=0;i<grid.length;i++){
    for(let j=0;j<grid[0].length;j++){
        if(grid[i][j]==="1"){
            calculate(i,j);
            count++;


        }
    }
}


return count;
    
};