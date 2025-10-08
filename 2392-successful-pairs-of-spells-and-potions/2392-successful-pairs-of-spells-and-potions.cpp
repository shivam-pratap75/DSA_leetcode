class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

    int n=spells.size();
    int n1=potions.size();
    int left=0;
     vector<int> pairs;
    sort(potions.begin(),potions.end());
    for(int i=0;i<n;i++){
        left=0;

     while(left < n1 && (long long)spells[i] * potions[left] < success){
         left++;
     }
    pairs.push_back(n1-left);


    }


return pairs;

    }
};