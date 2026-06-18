class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, window = 0;
        int maxFreq = 0;
        vector<int>count(26,0);

        while(r < s.size()){
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            if((r-l+1) - maxFreq > k){
                count[s[l] - 'A']--;
                l++;
            }

            window = max(window, r-l+1);
            r++;
        }

        return window;
    }
};
