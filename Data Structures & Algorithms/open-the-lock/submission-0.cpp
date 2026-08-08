class Solution {
public:
    vector<string> possibleOptions(string current){
        vector<string>ans;
        for(int i=0; i<4; ++i){
            string copy = current;
            copy[i] = (current[i] == '9') ? '0' : current[i]+1;
            ans.push_back(copy);
            copy = current;
            copy[i] = (current[i] == '0') ? '9' : current[i]-1;
            ans.push_back(copy);
        }
        return ans;
    }

    int bfs(string start, string target, unordered_map<string, bool>&visited){
        if(start == target) return 0;
        queue<string>q;
        q.push(start);
        visited[start] = true;
        int turns = 0;
        while(!q.empty()){
            int size = q.size();

            turns++;
            while(size--){
                auto front = q.front();
                q.pop();

                for(auto str: possibleOptions(front)){
                    if(visited[str]) continue;
                    if(str == target) return turns;
                    visited[str] = true;
                    q.push(str);
                }

            }
        }
        return -1;

    }
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool>visited;
        for(auto str: deadends){
            visited[str] = true;
        }

        if(visited["0000"]) return -1;

        return bfs("0000", target, visited);


    }
};