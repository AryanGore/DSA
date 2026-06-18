class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>maxheap;
       for(auto stone: stones){
          maxheap.push(stone);
       }

       while(maxheap.size() > 1){
          int x = maxheap.top();
          maxheap.pop();
          int y = maxheap.top();
          maxheap.pop();

          if(x==y){
            continue;
          }else if(x < y){
            maxheap.push(y-x);
          }else{
            maxheap.push(x-y);
          }
       }

       return maxheap.size() > 0 ? maxheap.top() : 0;
    }
};
