class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int>mp;
        for(char x: tasks){
            mp[x]++;
        }

        priority_queue<pair<int,char> , vector<pair<int,char>>, greater < pair<int,char>>>pq;
        for(auto x: mp){
            pq.push({1,x.first});
        }

        int time = 1;
        while(!pq.empty()){
            int a = pq.top().first;
            char b = pq.top().second;

            if(time >= a){
                mp[b]--;
                pq.pop();
                if(mp[b] > 0){
                    pq.push({a + n + 1 , b});
                }
            }
            time++;
        }

        return time-1;
    }
};
