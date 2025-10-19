class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int result = 0;
        unordered_map<int, int> basket;
        unordered_map<int, int> lastOccurrence;

        for(int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;
            lastOccurrence[fruits[right]] = right;

            if(basket.size() > 2) {
                // Find the fruit with minimum last occurrence
                int minIndex = INT_MAX;
                int keyToRemove = -1;
                
                for(const auto& pair : lastOccurrence) {
                    if(pair.second < minIndex) {
                        minIndex = pair.second;
                        keyToRemove = pair.first;
                    }
                }
                
                // Remove the fruit that appeared earliest
                lastOccurrence.erase(keyToRemove);
                basket.erase(keyToRemove);
                left = minIndex + 1;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};