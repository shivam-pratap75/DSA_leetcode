/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

 function result(nums1,nums2,val1,val2=-1){

     let j=0;
    let k=0;
if(val2!==-1){
    let a=0,b=0;

for(let i=0;i<=val2;i++){
 if(k>=nums2.length ){
           a=b;
            b=nums1[j];
           j++;
        }else if(j>=nums1.length ){
           a=b;
            b=nums2[k];
           k++;
        }else if( nums1[j]>=nums2[k] ){
            a=b;
            b=nums2[k];
            k++;

        }else{
           a=b;
            b=nums1[j];
           j++;
        }
        
         
        }
         return (a+b)/2;
        

}else{
   let a;
    for(let i=0;i<=val1;i++){
        if(k>=nums2.length ){
           
            a=nums1[j];
           j++;
        }else if(j>=nums1.length ){
        
            a=nums2[k];
           k++;
        }else if(nums1[j]>=nums2[k] ){
            a=nums2[k];
            k++;              
        }else{
            a=nums1[j];
            j++;
             
        }
       
       
        
        }  
        return a;    
    }
}

 
var findMedianSortedArrays = function(nums1, nums2) {

let num=nums1.length+nums2.length;
let num1,num2;
if(num%2===0){
    num2=num/2;
    num1=num2-1;
    return result(nums1,nums2,num1,num2);
}else{
    num=num-1;
    num1=num/2;
   return result(nums1,nums2,num1);
    
}
};