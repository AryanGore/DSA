class Solution {
public:
    bool isAnagram(string s, string t) {
        // vector<int>freq(255,0);
        // for(int i=0 ; i<s.size() ; ++i){
        //     freq[s[i]]++;
        // }

        // for(int i=0 ; i<t.size() ; ++i){
        //     freq[t[i]]--;
        // }

        // for(int i=0 ; i<freq.size() ; ++i){
        //     if(freq[i] != 0) return false;
        // }

        // return true;

        vector<int> freq(256,0);

        for(int i=0 ; i<s.size() ; ++i){
            freq[s[i]]++;
        }

        for(int i=0 ; i<t.size() ; ++i){
            freq[t[i]]--;
        }

        for(int i=0 ; i<freq.size() ; ++i){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};
