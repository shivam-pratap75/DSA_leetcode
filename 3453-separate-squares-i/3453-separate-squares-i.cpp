class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea = 0;
        long double minY = 1e18, maxY = 0;

        for (auto &s : squares) {
            long double y = s[1], l = s[2];
            totalArea += l * l;
            minY = min(minY, y);
            maxY = max(maxY, y + l);
        }

        long double target = totalArea / 2.0;

        for (int i = 0; i < 70; i++) {
            long double mid = (minY + maxY) / 2;
            long double areaBelow = 0;

            for (auto &s : squares) {
                long double y = s[1], l = s[2];
                long double height = min(max(mid - y, (long double)0), l);
                areaBelow += height * l;
            }

            if (areaBelow < target)
                minY = mid;
            else
                maxY = mid;
        }

        return (double)minY;
    }
};