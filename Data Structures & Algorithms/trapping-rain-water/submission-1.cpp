class Solution {
public:
    int trap(vector<int>& height) {
        int l = 1;
        int r = height.size()-2;
        int lmax = height[0];
        int rmax = height[height.size()-1];
        int maxarea = 0;

        while(l<=r){
            if(lmax < rmax){
                lmax = max(lmax , height[l]);
                maxarea += lmax - height[l];
                l++;
            }else{
                rmax = max(rmax, height[r]);
                maxarea += rmax - height[r];
                r--;
            }
        }

        return maxarea;
    }
};
