class Solution {
		unordered_map<string, unordered_map<string, double>> graph; // graph[a][b] = value means a / b = value 
		unordered_map<string, unordered_map<string, bool>> visited; // check a / b is exited
	public:
		void dfs(string a, string b) { // find every element that a can divide
			for(auto& [c, value] : graph[b]) {
				if(visited[a][c])
					continue;
				graph[a][c] = graph[a][b] * graph[b][c];
				visited[a][c] = true;
				dfs(a, c);
			}
		}
		vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
			for(int i = 0; i < equations.size(); i++) {
				string a = equations[i][0], b = equations[i][1];
				graph[a][b] = values[i];      visited[a][b] = true;
				graph[b][a] = 1 / values[i];  visited[b][a] = true;
				graph[a][a] = 1;              visited[a][a] = true;
				graph[b][b] = 1;              visited[b][b] = true; 
			}
			vector<double> ans;
			for(int i = 0; i < queries.size(); i++) {
				string a = queries[i][0], c = queries[i][1];
				for(auto& [b, value] : graph[a])  // find every element that a can divide
					dfs(a, b);
				ans.push_back(!visited[a][c] ? -1 : graph[a][c]); // Can't find c that a can divide c, return -1
			}
			return ans;
		}
	};