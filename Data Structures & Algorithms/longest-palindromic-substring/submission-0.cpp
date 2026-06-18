class Solution {
public:
    string longestPalindrome(string s) {
        int startIndex = 0;
        int longestSize = INT_MIN;

        int i = 0;

        while(i < s.size()){

            int centers[] = {i, i+1};

            for(int it: centers){
                int l = i;
                int r = it;

                while(l >= 0 && r < s.size() && s[l] == s[r]){
                    if(r-l+1 > longestSize){
                        startIndex = l;
                        longestSize = r - l + 1;
                    }
                    l--;
                    r++;
                }

            }

            i++;
        }

        return s.substr(startIndex, longestSize);
    }
};
