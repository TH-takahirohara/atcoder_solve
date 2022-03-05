#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

vector<int> output;
vector<bool> checker;
vector<bool> seen;

void dfs(const Graph &g, int v) {
  seen.at(v) = true;
  
  for (auto next_v : g.at(v)) {
    if (!checker.at(v)) {
      checker.at(next_v) = true;
      output.push_back(next_v);
    }
    if (seen.at(next_v)) continue;
    dfs(g, next_v);
  }
}

int main() {
  int N;
  cin >> N;
  Graph tree(N+1);
  
  for (int i=1; i<N; i++) {
    int a, b;
    cin >> a >> b;
    tree.at(a).push_back(b);
  }
  
  checker.assign(N+1, false);
  seen.assign(N+1, false);
  
  checker.at(1) = true;
  output.push_back(1);
  for (int v=1; v<=N; v++) {
    if (seen.at(v)) continue;
    dfs(tree, v);
  }
  
  if (output.size() > (N/2)) {
    for (int i=0; i<N/2; i++) {
      if (i != (N/2-1)) {
        cout << output.at(i) << " ";
      } else {
        cout << output.at(i) << endl;
      }
    }
    return 0;
  }
  
  checker.assign(N+1, false);
  seen.assign(N+1, false);
  output.clear();
  for (int v=1; v<=N; v++) {
    if (seen.at(v)) continue;
    dfs(tree, v);
  }
  for (int i=0; i<N/2; i++) {
    if (i != (N/2-1)) {
      cout << output.at(i) << " ";
    } else {
      cout << output.at(i) << endl;
    }
  }
}
