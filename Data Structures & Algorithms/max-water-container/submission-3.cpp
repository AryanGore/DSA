class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        int lt = 0;
        int rt = heights.size()-1;
        int area;

        while(lt < rt){
            int leftmax = heights[lt];
            int rightmax = heights[rt];

            if(leftmax < rightmax){
                area = leftmax * (rt - lt);
                lt++;
            }else{
                area = rightmax * (rt - lt);

                rt--;
            }

            maxarea = max(maxarea, area);

            
        }

        return maxarea;
    }
};
