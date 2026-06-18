class Solution {
public:
    int timerequired(vector<int>& piles, int k){
        int totalHour = 0;

        for(int i=0; i<piles.size(); ++i){
            totalHour += (piles[i] + k - 1) / k;
        }

        return totalHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxOfpiles = INT_MIN;
        for(int i=0; i<piles.size(); ++i){
            maxOfpiles = max(maxOfpiles, piles[i]);
        }

        int s = 1;
        int e = maxOfpiles;
        int mid;
        int ans = maxOfpiles;

        while(s<=e){
            mid = s + (e-s)/2;
            int totalHour = timerequired(piles, mid);
            if(totalHour <= h){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }

        return ans;

    }
};
