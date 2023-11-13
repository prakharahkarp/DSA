#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToBuses;
        unordered_set<int> visitedBuses;
        unordered_set<int> visitedStops;

        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        q.push({source, 0});

        while (!q.empty()) {
            int currStop = q.front().first;
            int busChanges = q.front().second;
            q.pop();

            if (currStop == target) return busChanges;

            for (int bus : stopToBuses[currStop]) {
                if (visitedBuses.count(bus) == 0) {
                    visitedBuses.insert(bus);

                    for (int nextStop : routes[bus]) {
                        if (visitedStops.count(nextStop) == 0) {
                            visitedStops.insert(nextStop);
                            q.push({nextStop, busChanges + 1});
                        }
                    }
                }
            }
        }

        return -1; // If target is not reachable
    }
};
