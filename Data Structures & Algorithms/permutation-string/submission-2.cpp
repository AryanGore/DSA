class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
                if(s1.size() > s2.size()) return false;
                        vector<int>countS1(26,0);
                                vector<int>countS2(26,0);

                                        for(int i=0 ; i<s1.size(); ++i){
                                                    countS1[s1[i]-'a']++;
                                                                countS2[s2[i]-'a']++;
                                                                        };

                                                                                if(countS1 == countS2) return true;

                                                                                        int l = 0, r = s1.size();

                                                                                                while(r < s2.size()){
                                                                                                            countS2[s2[r] - 'a']++;
                                                                                                                        countS2[s2[l] - 'a']--;
                                                                                                                                    if(countS1 == countS2) return true;
                                                                                                                                                l++;
                                                                                                                                                            r++;
                                                                                                                                                                    }

                                                                                                                                                                            return false; 

                                                                                                                                                                                }
                                                                                                                                                                                };

