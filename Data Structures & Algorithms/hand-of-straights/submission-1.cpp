class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        map<int,int>mp;
        for(int i: hand)mp[i]++;

        for(auto &x: mp){
            while(x.second){
                int a = x.first;
                int b = x.second;
                int k = groupSize;
                for(int i=0;i<k;i++){
                    if(!mp[a+i])return false;
                    mp[a + i]--;
                }
            }
        }
        return true;
    }
};
