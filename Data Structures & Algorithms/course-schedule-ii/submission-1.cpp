class Solution {
public: 
    unordered_map<int, vector<int>>premap;
    bool isSchedulable = true;
    void helper(int val, unordered_map<int,vector<int>>&premap, vector<int>&temp,vector<int>&visited, vector<int>&path){
        if(path[val] == 1){
            isSchedulable = false;
            return;
        }
        if(visited[val] == 1) return;
        path[val] = 1;
        visited[val] = 1;
        
        for(auto x: premap[val]){
            helper(x,premap,temp,visited, path);
        }
        path[val] = 0;
        temp.push_back(val);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto vec: prerequisites ){
            premap[vec[0]].push_back(vec[1]);
        }
        vector<int>path(numCourses, 0);
        vector<int>visited(numCourses, 0);
        vector<int>temp;
        for(int i=0; i<numCourses; ++i){
            helper(i,premap,temp,visited,path);
        }
        if(isSchedulable) return temp;

        return {};
    }
};
