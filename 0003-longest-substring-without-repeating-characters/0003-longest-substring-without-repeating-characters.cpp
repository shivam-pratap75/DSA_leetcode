class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
set<int> numSet;
int len=0;
int curr=0;
int right=0,left=0;
int n=s.size();
while(right<n){
numSet.insert(s[right]);
right++;
curr++;
if(numSet.find(s[right])!=numSet.end() && right<n){
    char a=s[right];
    while(!(s[left]==a)){
        numSet.erase(s[left]);
        left++;
    }
    left++;
}


len=max(len,curr);
curr=right-left;


}
 

return len;
    }
};