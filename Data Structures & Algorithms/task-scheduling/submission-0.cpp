class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(int i=0; i<tasks.size(); ++i){
            count[tasks[i] - 'A']++;
        }

        priority_queue<int>maxheap;
        for(int i=0; i<count.size(); ++i){
            if(count[i] > 0) maxheap.push(count[i]);
        }

        queue<pair<int,int>>cooldown; //cooldown time : remaining tasks.
        int cputime = 0;
        while(!maxheap.empty() || !cooldown.empty()){
            cputime++;
            if(!maxheap.empty()){
                int task = maxheap.top();
                task--;
                maxheap.pop();
                if(task > 0) cooldown.push({cputime + n , task});
            }


            
            if(!cooldown.empty() && cooldown.front().first == cputime) {
                maxheap.push(cooldown.front().second);
                cooldown.pop();
            }
        }

        return cputime;
    }
};
