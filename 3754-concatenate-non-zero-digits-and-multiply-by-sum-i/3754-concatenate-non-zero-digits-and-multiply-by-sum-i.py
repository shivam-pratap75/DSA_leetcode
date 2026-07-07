class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x=0
        sum=0
        num=1
        while n>0:
            a=n%10
            if a!=0:
                x=a*num+x
                sum+=a
                num=num*10
            n=n//10
        
        return x*sum
        