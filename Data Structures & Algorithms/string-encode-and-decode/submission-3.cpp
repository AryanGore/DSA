class Solution {
public:

    string encode(vector<string>& strs) {
        // string encoded = "";
        // for(auto str : strs){
        //     encoded += to_string(str.size()) + "#" + str;
        // }
        // return encoded;

        string encoded = "";
        for(auto str : strs){
            encoded += to_string(str.size()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        // vector<string> result;
        // int i = 0;
        // while(i < s.size()){
        //     int j = i;

        //     while(s[j] != '#') j++;
        //     int len = stoi(s.substr(i,j-i));
        //     j++;

        //     result.push_back(s.substr(j,len));
        //     i = j + len;
        // }

        // return result;

        vector<string> dvector;
        int i=0;
        while(i < s.size()) {
            int j = i;

            while(s[j] != '#') j++;

            int len = stoi(s.substr(i,j-i));
            j++;

            dvector.push_back(s.substr(j,len));

            i = j + len;
        }

        return dvector;

    }
};
