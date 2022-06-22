class Solution {
public:
    int par[100005];
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    void unite(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a > b) swap(a, b);
        par[b] = a;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(int i = 0; i < s.size(); i++){
            par[i] = i;
        }
        string ans;
        for(int i = 0; i < pairs.size(); i++){
            unite(pairs[i][0], pairs[i][1]);
        }
        map<int, string> mp;
        for(int i = 0; i < s.size(); i++){
            mp[find(i)] += s[i];
        }
        unordered_map<int,int> pointers;
        for(auto &x: mp) sort(x.second.begin(), x.second.end());
        for(int i = 0; i < s.size(); i++){
            ans += mp[par[i]][pointers[par[i]]];
            pointers[par[i]]++;
        }
        return ans;
    }
};