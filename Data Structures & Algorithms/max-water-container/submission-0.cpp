class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxi = INT_MIN;

        while(left < right){
            int area = min(heights[left] , heights[right]) * abs(left - right);
            maxi = max(maxi , area);

            if(heights[left] < heights[right]) left++;
            else right--;

        }

        return maxi;
    }
};
