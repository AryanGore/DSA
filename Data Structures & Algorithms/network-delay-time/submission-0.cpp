class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
                unordered_map<int, vector<pair<int,int>>> adj;

                        for(auto &t : times) {
                                    adj[t[0]].push_back({t[1], t[2]});
                                            }

                                                    vector<int> dist(n+1, INT_MAX);
                                                            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

                                                                    pq.push({0, k});
                                                                            dist[k] = 0;

                                                                                    while(!pq.empty()) {
                                                                                                auto [time, node] = pq.top();
                                                                                                            pq.pop();

                                                                                                                        for(auto &[nei, wt] : adj[node]) {
                                                                                                                                        if(time + wt < dist[nei]) {
                                                                                                                                                            dist[nei] = time + wt;
                                                                                                                                                                                pq.push({dist[nei], nei});
                                                                                                                                                                                                }
                                                                                                                                                                                                            }
                                                                                                                                                                                                                    }

                                                                                                                                                                                                                            int ans = 0;
                                                                                                                                                                                                                                    for(int i=1; i<=n; i++) {
                                                                                                                                                                                                                                                if(dist[i] == INT_MAX) return -1;
                                                                                                                                                                                                                                                            ans = max(ans, dist[i]);
                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                            return ans;
                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                };
