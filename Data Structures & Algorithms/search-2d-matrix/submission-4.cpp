class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int e=matrix.size()-1;
        int mid;

        while(s<=e){
            int mid = s + (e - s)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        if(e < 0) return false;

        int s1 = 0;
        int e1 = matrix[0].size()-1;
        int mid1;

        while(s1<=e1){
            mid1 = s1+(e1-s1)/2;
            if(matrix[e][mid1] == target) return true;
            else if(matrix[e][mid1] < target){
                s1 = mid1 + 1;
            }else{
                e1 = mid1 - 1;
            }
        }

        return false;

    }
};
