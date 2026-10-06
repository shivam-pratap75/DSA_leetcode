class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        temp={}

        for i in range(len(nums)):
            num=target-nums[i]
            if num in temp:
                return [temp[num],i]
            
            temp[nums[i]]=i


        

        