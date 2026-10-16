class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool> visi(n, false);
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visi[0] = true;

        while(!q.empty()){
            auto [idx, steps] = q.front();
            q.pop();
            
            if(idx == n - 1){
                return steps;
            }

            if (idx + 1 < n && !visi[idx + 1]) {
                visi[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }

            if (idx - 1 >= 0 && !visi[idx - 1]) {
                visi[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            if (mp.count(arr[idx])) {
                for(int nextIdx : mp[arr[idx]]){
                    if(!visi[nextIdx]){
                        visi[nextIdx] = true;
                        q.push({nextIdx, steps + 1});
                    }
                }
                mp.erase(arr[idx]); 
            }
        }
        return 0;
    }
};
