class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>, greater<>> busyRooms;

        for (int i = 0; i < n; i++)
            freeRooms.push(i);

        vector<int> cnt(n, 0);

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end, room});
                cnt[room]++;
            } else {
                auto [finish, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.push({finish + duration, room});
                cnt[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[ans])
                ans = i;
        }

        return ans;
    }
};
