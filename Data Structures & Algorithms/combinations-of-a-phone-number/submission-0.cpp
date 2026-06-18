class Solution {
public:
    vector<string>finalans;
    unordered_map<char, string>letters;


    void helper(int idx, string& digits, string& temp){
        if(idx == digits.size()){
            finalans.push_back(temp);
            return;
        }
        char str = digits[idx];
        string totraverse = letters[str];
        for(int i=0; i<totraverse.size(); ++i){
            temp += totraverse[i];
            helper(idx+1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";
        string temp = "";
        helper(0, digits, temp);
        return finalans;
    }
};
