class Solution {
public:
    int minPartitions(string n) {

        int k=n.length();
        int result=0;
        for(int i=0;i<k;i++){
            result=max(n[i]-'0',result);
            if(result==9)return result;
        }

    return result;

        
    }
};