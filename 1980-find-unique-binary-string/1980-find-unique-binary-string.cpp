class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {

        int n=nums[0].length();

        int num1=(1<<n)-1;
        unordered_map<int,int> temp;

        for(string x:nums){
            int num=0;
            int len=0;
            for(char i:x){
                if(i=='1')num+=(1<<len);
                len++;
            }
            temp[num]++;


        }
        int i;
        for(i=0;i<num1;i++){

            if(temp.find(i)==temp.end())break;
        }

            string result="";

            if(i==0){
                int sz=n;
                while(sz){
                    result.push_back('0');
                    sz--;
                }
                return result;
            }
            for(int j=0;j<n;j++){
                
                if(i &(1<<j)){
                    result.push_back('1');
                }else{
                    result.push_back('0');
                }
            }    

            return result;   
    }
};