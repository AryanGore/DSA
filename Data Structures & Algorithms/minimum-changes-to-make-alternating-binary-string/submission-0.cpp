class Solution {
public:
    int minOperations(string s) {
        int startswith0 = 0;
        int startswith1 = 0;

        for(int i=0; i<s.size(); ++i){
            char expecting0 = (i%2 == 0) ? '0' : '1';
            char expecting1 = (i%2 == 0) ? '1' : '0';

            if(s[i] != expecting0) startswith0++;
            if(s[i] != expecting1) startswith1++;
        }

        return min(startswith0, startswith1);
    }
};