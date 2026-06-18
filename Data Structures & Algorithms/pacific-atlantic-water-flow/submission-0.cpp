class Solution {
public:
    set<pair<int,int>>pacific;
    set<pair<int,int>>atlantic;

    void helper(int i, int j, int prevHeight, bool isPacific , vector<vector<int>>& heights){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || heights[i][j] == -2 || heights[i][j] < prevHeight){
            cout<<"base";
            return;
        }
        cout<<heights[i][j];

        
        
        if(isPacific) {
            if(pacific.find({i,j}) != pacific.end()) return;
            pacific.insert({i,j});
        }
        else {
            if(atlantic.find({i,j}) != atlantic.end()) return;
            atlantic.insert({i,j});
        }

        helper(i,j+1,heights[i][j],isPacific,heights);
        helper(i+1,j,heights[i][j],isPacific,heights);
        helper(i,j-1,heights[i][j],isPacific,heights);
        helper(i-1,j,heights[i][j],isPacific,heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        for(int i=0; i<heights[0].size(); ++i){
            helper(0,i,-1,true,heights);
        }
        for(int i=0; i<heights.size(); ++i){
            helper(i,0,-1, true, heights);
        }
        for(int i=0; i < heights.size(); ++i){
            helper(i,heights[0].size()-1,-1,false,heights);
        }
        for(int i=0; i < heights[0].size(); ++i){
            helper(heights.size()-1,i,-1,false,heights);
        }

        vector<vector<int>>finalans;

        for(auto [i,j]: pacific){
            if(atlantic.find({i,j}) != atlantic.end()){
                finalans.push_back({i,j});
            }
        }

        return finalans;

    }
};
