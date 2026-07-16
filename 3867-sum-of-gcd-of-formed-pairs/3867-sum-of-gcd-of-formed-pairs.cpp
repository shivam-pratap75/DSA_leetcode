class Solution {
public:

    int gcd(int a, int b){
        while(b){
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {


        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = nums[0];

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int left = 0, right = n - 1;

        while(left < right){
            ans += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return ans;
    }
};