// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {



//         priority_queue<int>pq;

//         for(int i=0;i<nums1.size();i++){

//             int num=nums1[i]-nums2[i];
//             num=abs(num);
//             pq.push(num);
//         }
//         int k = k1 + k2;

//         while(k>0 && pq.top()>0){
//             int num=pq.top();
//             pq.pop();
//             num-=1;
//             pq.push(num);
//           k--;
//         }

//         long long result=0;
//         while(!pq.empty()){
//              long long num = pq.top();
//             pq.pop();
//             result += num * num;
//         }

//        return result; 
//     }
// };




class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        int k = k1 + k2;

        unordered_map<int, long long> freq;
        int maxDiff = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            maxDiff = max(maxDiff, d);
        }

        for (int d = maxDiff; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long take = min((long long)k, freq[d]);
            freq[d] -= take;
            freq[d - 1] += take;
            k -= take;
        }

        long long result = 0;
        for (auto &p : freq) {
            result += p.second * (long long)p.first * p.first;
        }

        return result;
    }
};
