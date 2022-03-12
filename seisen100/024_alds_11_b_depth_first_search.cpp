#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int T = 0;
vector<int> F;
vector<int> C;
vector<bool> seen;

void dfs(vector<vector<int> > &G, int x) {
  seen.at(x) = true;
  T++;
  F.at(x) = T;
  
  rep(i,0,G.at(x).size()) {
    if (seen.at(G.at(x).at(i))) continue;
    dfs(G, G.at(x).at(i));
  }
  
  T++;
  C.at(x) = T;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > G(N+1);
  
  seen.assign(N+1, false);
  F.assign(N+1, 0);
  C.assign(N+1, 0);
  
  rep(i,0,N) {
    int U, K;
    cin >> U >> K;
    rep(j,0,K) {
      int tmp;
      cin >> tmp;
      G.at(U).push_back(tmp);
    }
  }
  
  rep(i,1,N+1) {
    if (seen.at(i)) continue;
    dfs(G, i);
  }
  
  rep(i,1,N+1) {
    cout << i << " " << F.at(i) << " " << C.at(i) << endl;
  }
}
