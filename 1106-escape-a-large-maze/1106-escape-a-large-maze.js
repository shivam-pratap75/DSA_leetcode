/**
 * @param {number[][]} blocked
 * @param {number[]} source
 * @param {number[]} target
 * @return {boolean}
 */
  let left_safe =function(s_et,source){
    let x=source[0];
    let y=source[1]-1;
    if(y>=0 && !(s_et.has(`${x},${y}`))){
        return true;
    }
     return false;    
 }
 let right_safe =function(s_et,source){
    let x=source[0];
    let y=source[1]+1;
    if(y<=999999 && !(s_et.has(`${x},${y}`))){
        return true;
    }
     return false;    
 }
  let up_safe =function(s_et,source){
    let x=source[0]-1;
    let y=source[1];
    if(x>=0 && !(s_et.has(`${x},${y}`))){
        return true;
    }
     return false;    
 }
 
  let down_safe =function(s_et,source){
    let x=source[0]+1;
    let y=source[1];
    if(x<=999999 && !(s_et.has(`${x},${y}`))){
        return true;
    }
     return false;    
 }

let path= function(s_et,source,target){

   let queue = [];
   let visited=new Set();

  queue.push(source);
  visited.add(`${source[0]},${source[1]}`);
  const max_vist=20000;

  while(queue.length!=0 && visited.size<max_vist){
    let [x,y]=queue.shift();

    if(x == target[0] && y == target[1]  ){
        return true;
    }


     if (left_safe(s_et, [x, y]) && !visited.has(`${x},${y-1}`)) {
                queue.push([x, y-1]);
                visited.add(`${x},${y-1}`);
            }
      if(right_safe(s_et,[x,y]) && !visited.has(`${x},${y+1}`)){
      
        queue.push([x,y+1]);
        visited.add(`${x},${y+1}`);
    }
      if(up_safe(s_et,[x,y]) && !visited.has(`${x-1},${y}`)){
      
        queue.push([x-1,y]);
        visited.add(`${x-1},${y}`);
    }
      if(down_safe(s_et,[x,y]) && !visited.has(`${x+1},${y}`)){
       
        queue.push([x+1,y]);
        visited.add(`${x+1},${y}`);
    }

  }      

   return visited.size>=max_vist;

}



var isEscapePossible = function(blocked, source, target) {

if(blocked.length<2){
    return true;
}
                                                        

let s_et = new Set();
for (let [x, y] of blocked) {
        s_et.add(`${x},${y}`);
    }
// if(!(left_safe(s_et,target))&& !(right_safe(s_et,target))&& !(up_safe(s_et,target))&& !(down_safe(s_et,target)))){
//     return false;
// } 

return path(s_et,source,target)&& path(s_et,target,source);

    
};