class Solution {
public:

    string multiply(string num1, string num2) {

     reverse(num1.begin(),num1.end());
     reverse(num2.begin(),num2.end());

     int n1=num1.size();
     int n2=num2.size();

     vector<int> arr(n1+n2,0);

     for(int i=0;i<n1;i++){
        int a=num1[i]-'0';
        for(int j=0;j<n2;j++){
            int b=num2[j]-'0';
            int num=a*b;
            arr[i+j]+=num;
        }
     }

     for(int i=0;i<arr.size()-1;i++){

        if(arr[i]>9){
            int num=arr[i]%10;
            arr[i+1]+=arr[i]/10;
            arr[i]=num;
        }
     }

    reverse(arr.begin(),arr.end());
    string result="";
    int i=0;
    while (i < arr.size() && arr[i] == 0) i++;
    for( i;i<arr.size();i++){
        char ch=arr[i]+'0';
        result+=ch;
    }
    return result=="" ? "0" :result;
        
    }
};