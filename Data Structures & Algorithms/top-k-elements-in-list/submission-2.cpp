class Solution {
public:
//note : if you are asked avout top k , elements or top k frequent or such titled provlems where 
//the sorting of the elements do not matter vucket sort might ve the optimised approach.

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq; // creating a frequnecy map
        for(auto x : nums){
            freq[x]++;
        }
        vector<vector<int>>vuckets(nums.size()+1); // vucket datastructure to store freq : {num1 , num2...};

        for(auto [num , count] : freq){ // populating the vuckets.
            vuckets[count].push_back(num);
        }

        vector<int>window = {};
        // window.resize(k);
        for(int i=vuckets.size()-1 ; i>=0 ; --i){ // fetching top k elements.
            for(auto it : vuckets[i]){
                if(window.size() == k) break;
                window.push_back(it);
            }
            
        }

        return window; // return top k elements.
    }
};
