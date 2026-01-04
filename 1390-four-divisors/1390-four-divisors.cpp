// class Solution {
// public:
//     int sumFourDivisors(vector<int>& nums) {

//    int result=0;

//    for(int i=0;i<nums.size();i++){
//     int curr=0;
//     int flag=0;
//     for(int j=2;j*j<=nums[i];j++){
//         if(flag>2){
//             break;
//         }
//         if(nums[i]%j==0){
//            flag++;
//            curr+=j;
//         int a=nums[i]/j;
//         if(nums[i]%a==0 && a!=j){
//             flag++;
//             curr+=a;
//         }

//         }
//     }
//     if(flag==2){
//         result+=curr;
//         result+=1+nums[i];
//     }
//    }



// return result;
        
//     }
// };

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int n=nums.size();
        int result=0;

        for(int i=0;i<n;i++){
            int check=0;
            int sum=0;

            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    check++;
                    sum+=j;
                    int b=nums[i]/j;
                    if(nums[i]%b==0 && j!=b){
                        check++;
                        sum+=b;
                    }
                    
                }
                if(check>2)break;
               
            }
            if(check==2){
                result=result+1+nums[i]+sum;
                
            }
        }
            return result;
    }
};