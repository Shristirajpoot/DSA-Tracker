class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> mp;
        mp[0].insert(0);

        for(int s : stones)
            mp[s];

        for(int s : stones){
            for(int k : mp[s]){
                for(int d : {k-1, k, k+1}){
                    if(d > 0 && mp.count(s+d))
                        mp[s+d].insert(d);
                }
            }
        }
        return !mp[stones.back()].empty();
    }
};
