class Solution {
public:
    int count(vector<int>& nums, long long num) {
        int left = 0, right = nums.size() - 1;
        int result = 0;

        while (left < right) {

            long long check = 1LL * nums[left] * nums[right];

            if (check == num) {

                if (nums[left] == nums[right]) {
                    long long len = right - left + 1;
                    result += (len * (len - 1)) / 2;
                    break;
                }

                long long leftCount = 1, rightCount = 1;

                while (left + 1 < right && nums[left] == nums[left + 1]) {
                    leftCount++;
                    left++;
                }

                while (right - 1 > left && nums[right] == nums[right - 1]) {
                    rightCount++;
                    right--;
                }

                result += leftCount * rightCount;
                left++;
                right--;
            }

            else if (check > num) right--;
            else left++;
        }

        return result;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int result = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long num = 1LL * nums1[i] * nums1[i];
            result += count(nums2, num);
        }

        for (int i = 0; i < nums2.size(); i++) {
            long long num = 1LL * nums2[i] * nums2[i];
            result += count(nums1, num);
        }

        return result;
    }
};