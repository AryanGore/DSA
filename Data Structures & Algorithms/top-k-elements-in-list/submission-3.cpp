class Solution {
public:
//note : if you are asked avout top k , elements or top k frequent or such titled provlems where 
//the sorting of the elements do not matter vucket sort might ve the optimised approach.

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> Nfreq;
        for(int i=0 ; i<nums.size() ; ++i){
            Nfreq[nums[i]]++;
        }

        vector<vector<int>>freqN(nums.size() + 1);
        for(auto [nums , count] : Nfreq){
            freqN[count].push_back(nums);
        }
        
        vector<int> window = {};
        // window.resize(k);
        for(int i=freqN.size()-1 ; i>=0 && window.size() < k ; --i){
            for(auto x : freqN[i]){
                if(window.size() == k) break;
                window.push_back(x);
            }
        }

        return window;
    }
};
