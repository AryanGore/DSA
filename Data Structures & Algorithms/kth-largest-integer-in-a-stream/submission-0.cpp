class KthLargest {
    priority_queue<int>pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto num: nums){
            pq.push(num);
        }
        this->k = k;
    }
    
    int add(int val) {
        vector<int>temp;
        int popped;
        pq.push(val);
        for(int i = 0; i<k; ++i){
            popped = pq.top();
            pq.pop();
            temp.push_back(popped);
        }


        for(int i=0; i<temp.size(); ++i){
            pq.push(temp[i]);
        }

        return popped;
    }
};
