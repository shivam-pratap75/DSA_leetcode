/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    
let arr=[];

if(s.length%2 !==0){
    return false;
}
for(let i=0;i<s.length;i++){
    if( s[i]==='(' || s[i]==='{'|| s[i]==='['){
arr.push(s[i]);

    }else if( s[i]===')' || s[i]==='}'|| s[i]===']'){
        if(arr.length===0){
return false;
}
        

        if(arr[arr.length-1]==='(' && s[i]===')'){

           arr.pop();
        }else if(arr[arr.length-1]==='{' && s[i]==='}'){
           
           arr.pop();
            }else if(arr[arr.length-1]==='['&&s[i]===']'){
            arr.pop();
            
           
        }else{
            return false;
        }
       
    }

}
if(arr.length===0){
return true;
}

return false;

};