#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;
        
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }
        
        vector<int> ans(m);
        int currentTime = 0;

        for (int i = 0; i < m; i++) {
            currentTime = max(currentTime, i);

            while (!busyServers.empty() && busyServers.top().first <= currentTime) {
                auto server = busyServers.top();
                busyServers.pop();
                freeServers.push({servers[server.second], server.second});
            }

            if (freeServers.empty()) {
                currentTime = busyServers.top().first;
                while (!busyServers.empty() && busyServers.top().first <= currentTime) {
                    auto server = busyServers.top();
                    busyServers.pop();
                    freeServers.push({servers[server.second], server.second});
                }
            }

            auto availableServer = freeServers.top();
            freeServers.pop();
            ans[i] = availableServer.second;
            busyServers.push({currentTime + tasks[i], availableServer.second});
        }
        
        return ans;
    }
};
