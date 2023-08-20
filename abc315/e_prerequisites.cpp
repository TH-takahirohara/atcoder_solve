#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N;
vector<vector<int>> G;
vector<bool> seen;
stack<int> st;
queue<int> que;

void rec(int v) {
  if (seen.at(v)) return;
  seen.at(v) = true;
  for (auto nv : G.at(v)) {
    if (seen.at(nv)) continue;
    rec(nv);
  }
  que.push(v);
}

int main() {
  cin >> N;
  G.assign(N, {});
  seen.assign(N, false);
  rep(i,0,N) {
    int c;
    cin >> c;
    rep(j,0,c) {
      int p;
      cin >> p;
      p--;
      G.at(i).push_back(p);
    }
  }

  for (auto nv1 : G.at(0)) {
    rec(nv1);
  }

  while (!que.empty()) {
    cout << que.front() + 1 << " ";
    que.pop();
  }
  
  cout << endl;
}
