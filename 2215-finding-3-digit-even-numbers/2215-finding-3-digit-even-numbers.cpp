class Solution {
public:
bool check(int a, int b, int c,unordered_map<int, int>m){

if(c==0){
    return false;
}
if(a==b && a==c){
    if(m[a]>=3){

    }else{
        return false;
    }
}

if(m.find(a)!=m.end() && m.find(b)!=m.end() && m.find(c)!=m.end()){
   if(a==b || a==c){
    if(m[a]>=2){
    
    }else{
        return false;
    }
   }
    if(b==a || b==c){
    if(m[b]>=2){
    
    }else{
        return false;
    }
   }
   

}else{
    return false;
}


return true;

}

    vector<int> findEvenNumbers(vector<int>& digits) {
 unordered_map<int ,int>m;
 vector<int>res;
 for(int ele : digits){
    m[ele]++;
 }

 for(int i=100;i<=998;i+=2){
    int x=i;
    int a=x%10;
    x=x/10;
    int b=x%10;
    x=x/10;
    int c=x;
    if(check(a,b,c,m)){
   res.push_back(i);
    }

 }
return res;
    }
};