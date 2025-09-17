/**
 * @param {number[]} nums
 * @return {number[][]}
 */

function permutations(input ,output,array){
    
      if (input.length === 0) {
            array.push(output); 
            return;
        }
        for (let i = 0; i < input.length; i++) {
            
            let newInput = [...input.slice(0, i), ...input.slice(i + 1)];
            let newOutput = [...output, input[i]];
            
            permutations(newInput, newOutput,array);
        }
  return array;

}

var permute = function(nums) {
let array =[];
let output="";
 let result = permutations(nums,output,array);
 return result;
    
};