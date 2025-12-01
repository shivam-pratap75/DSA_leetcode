class Solution {
public:
    long long maxRunTime(int n, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long sum = accumulate(arr.begin(), arr.end(), 0LL);

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] <= sum / n) break;
            sum -= arr[i];
            n--;
        }

        return sum / n;
    }
};
