#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<vector<int> > dist;
vector<vector<int> > dp;
int INF = 1000000000;
int V, E;

int rec(int bit, int v) {
  if (dp.at(bit).at(v) != -1 && dp.at(bit).at(v) < INF) {
    return dp.at(bit).at(v);
  }
  
  if (bit==(1<<v)) {
    if (dist.at(0).at(v) != -1) return dist.at(0).at(v);
    else return INF;
  }
  
  int res = INF;
  int bit2 = bit & ~(1<<v);
  
  rep(i,0,V) {
    if ((bit2 & (1<<i)) && dist.at(i).at(v) != -1) {
      res = min(res, rec(bit2, i) + dist.at(i).at(v));
    }
  }
  
  return dp.at(bit).at(v) = res;
}

int main() {
  cin >> V >> E;
  
  dist.assign(V, vector<int>(V, -1));
  rep(i,0,E) {
    int s,t,d;
    cin >> s >> t >> d;
    dist.at(s).at(t) = d;
  }
  
  dp.assign((1<<V)+1, vector<int>(V,-1));
  
  int res = INF;
  res = rec((1<<V)-1, 0);
    
  if (res == INF) cout << -1 << endl;
  else cout << res << endl;
}
