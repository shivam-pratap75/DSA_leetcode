// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {

//         vector<int> temp(cardPoints.begin(),cardPoints.end());

//         temp.insert(temp.end(),temp.begin(),temp.begin()+k);
//         int n=cardPoints.size();

//         int left=n-k;
//         int right=n-k;
//         int sz=temp.size();
//         int sum=0;
//         int result=-1;
//         while(right<sz){
//             sum+=temp[right];

//             if(right-left+1>k){
//                 sum-=temp[left];
//                 left++;
//             }
//             right++;
//             result=max(result,sum);
//         }
//         return result;
        
//     }
// };




class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
  
  int n=cardPoints.size();

    int left=0,right=0;
    long long mini=INT_MAX,sum=0;

    int len=n-k;
    while(right<n){
        sum+=cardPoints[right];

        if(right-left+1>len){
            sum-=cardPoints[left];
            left++;
        }

        if(right-left+1==len){
            mini=min(mini,sum);
        }
        right++;
    }

    long long total=accumulate(cardPoints.begin(),cardPoints.end(),0);

    return total-mini;



    }      
};