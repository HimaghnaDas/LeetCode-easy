#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   int totalFruit(vector<int>& tree) {
      int n = tree.size();
      int j = 0;
      map <int, int> m;
      int ans = 0;
      for(int i = 0; i < n; i++){
         m[tree[i]] += 1;
         while(m.size() > 2 && j <= i){
            m[tree[j]]--;
            if(m[tree[j]] == 0)m.erase(tree[j]);
            j++;
         }
         ans = max(i - j + 1, ans);
      }
      return ans;
   }
};