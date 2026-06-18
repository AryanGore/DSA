class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int lt =0 ;
        int rt = height.size()-1;
        int lmax = 0 , rmax = 0;

        while(lt < rt){
            lmax = max(lmax , height[lt]);
            rmax = max(rmax , height[rt]);

            if(lmax < rmax){
                ans += lmax - height[lt];
                lt++;
            }else{
                ans += rmax - height[rt];
                rt--;
            }
        }

        return ans;
    }
};
