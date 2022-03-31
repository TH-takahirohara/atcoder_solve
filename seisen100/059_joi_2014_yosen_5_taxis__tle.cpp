// テストケース4/5正解　最後のテストケースのみTLEとなった
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

const ll INF = 1LL << 60;

struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};

typedef vector<vector<Edge> > Graph;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int> C(N), R(N);
  rep(i,0,N) {
    cin >> C.at(i);
    cin >> R.at(i);
  }
  
  vector<vector<int>> G(N);
  rep(i,0,K) {
    int a,b;
    cin >> a >> b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  
  vector<ll> price(N,INF);
  priority_queue<vector<ll>,
                 vector<vector<ll>>,
                 greater<vector<ll>>> que;
  // 運賃, 残り, 今の位置, どこから来たかの位置
  price.at(0) = 0;
  que.push({C.at(0), R.at(0), 0, 0});
  
  while (!que.empty()) {
    ll p = que.top().at(0);
    ll nokori = que.top().at(1);
    ll v = que.top().at(2);
    ll from = que.top().at(3);
    que.pop();
    
    for (auto nv : G.at(v)) {
      if (chmin(price.at(nv), price.at(from)+p)) {
        if (nv!=N-1) que.push({C.at(nv), R.at(nv), nv, nv});
      }
      if (nv!=N-1 && nokori-1 != 0) que.push({p, nokori-1, nv, from});
    }
  }
  
  cout << price.at(N-1) << endl;
}
