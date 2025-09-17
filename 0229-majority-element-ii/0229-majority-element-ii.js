/**
 * @param {number[]} nums
 * @return {number[]}
 */

var majorityElement = function(nums) {
    const map =new Map();
    const result=[];
    for (let i = 0; i < nums.length; i++) {
        const count = map.get(nums[i]) || 0;
        map.set(nums[i], count + 1);
    }
     for (let [num, count] of map) {
        if (count > nums.length / 3) {
            result.push(num);
        }
    }
return result;
};