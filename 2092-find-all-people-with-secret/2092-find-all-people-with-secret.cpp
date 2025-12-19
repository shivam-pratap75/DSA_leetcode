class Solution {
public:

    void solve(unordered_set<int>& temp1, unordered_set<int>& temp, vector<pair<int, int>>& meetingsAtTime) {
        // We need to process meetings, not just check if anyone in temp1 knows
        bool changed = true;
        
        while (changed) {
            changed = false;
            
            // Check all meetings at this time
            for (auto& meeting : meetingsAtTime) {
                int x = meeting.first;
                int y = meeting.second;
                
                // If x knows and y is in temp1, y learns the secret
                if (temp.find(x) != temp.end() && temp1.find(y) != temp1.end()) {
                    temp.insert(y);
                    temp1.erase(y);
                    changed = true;
                }
                // If y knows and x is in temp1, x learns the secret
                if (temp.find(y) != temp.end() && temp1.find(x) != temp1.end()) {
                    temp.insert(x);
                    temp1.erase(x);
                    changed = true;
                }
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> result;
        unordered_set<int> temp;
        
        // Initial people who know the secret
        temp.insert(0);
        temp.insert(firstPerson);
        
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        int m = meetings.size();
        int i = 0;
        unordered_set<int> temp1;  // People who don't know secret yet
        vector<pair<int, int>> currentMeetings;  // Store meetings at current time
        int currentTime = -1;
        
        while (i < m) {
            int x = meetings[i][0];
            int y = meetings[i][1];
            int time = meetings[i][2];
            
            // If time changes, process temp1 with meetings at that time
            if (currentTime != -1 && time != currentTime) {
                solve(temp1, temp, currentMeetings);
                temp1.clear();
                currentMeetings.clear();
                currentTime = time;
            }
            
            if (currentTime == -1) {
                currentTime = time;
            }
            
            // Store current meeting
            currentMeetings.push_back({x, y});
            
            // Check if either person knows the secret
            if (temp.find(x) != temp.end()) {
                temp.insert(y);
                // If y was in temp1, remove it
                temp1.erase(y);
            } 
            else if (temp.find(y) != temp.end()) {
                temp.insert(x);
                // If x was in temp1, remove it
                temp1.erase(x);
            }
            else {
                // Neither knows, add both to temp1
                temp1.insert(x);
                temp1.insert(y);
            }
            
            i++;
        }
        
        // Process any remaining people in temp1
        if (!temp1.empty()) {
            solve(temp1, temp, currentMeetings);
        }

        // Convert set to vector
        for (const auto &x : temp) {
            result.push_back(x);
        }
        
        return result;
    }
};