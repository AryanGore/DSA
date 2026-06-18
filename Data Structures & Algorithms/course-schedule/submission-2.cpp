class Solution {
public:
    bool isSchedulable = true;
    unordered_map<int, vector<int>>premap;
   // vector<bool>visited(numCourses, false);
    void helper(int val, unordered_map<int,vector<int>>&premap, vector<int>&visited, vector<int>&path){
        if(path[val] == 1){
            isSchedulable = false;
            return;
        }
        if(visited[val] == 1) return;

        visited[val] = 1;
        path[val] = 1;
        for(auto x : premap[val]){
            helper(x,premap, visited, path);
        }
        path[val] = 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto vec: prerequisites){
            premap[vec[0]].push_back(vec[1]);
        }
        vector<int>visited(numCourses, 0);
        vector<int>pathVisited(numCourses, 0);
        for(int i=0; i<visited.size(); ++i){
            helper(i,premap, visited, pathVisited);
        }
        //helper(0, premap, visited, pathVisited);
        return isSchedulable;
    }
};
