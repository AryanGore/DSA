class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int sptr = 0 , currlen = 0 , maxi = 0;
        // unordered_set<char> hs;

        // while(sptr < s.size()){
        //     if(hs.find(s[sptr]) != hs.end()){
        //         maxi = max(maxi , currlen);
        //         currlen = 0;
        //         hs.clear();
        //     }else{
        //         hs.insert(s[sptr]);
        //         currlen++;
        //     }

        //     sptr++;    
        // }

        // return maxi;

        int left = 0;
        int maxi = 0;

        unordered_set<char> hs;
        for(int i = 0 ; i < s.size() ; ++i){
            char currentchar = s[i];

            while(hs.find(currentchar) != hs.end()){
                hs.erase(s[left]);
                left++;
            }


            hs.insert(currentchar);

            maxi = max(maxi , i - left + 1);
        }

        return maxi;
    }
};
