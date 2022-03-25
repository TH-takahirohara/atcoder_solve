#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<vector<ll> > dist;
vector<vector<ll> > times;
vector<vector<vector<ll>> > dp;
ll INF = 11000000000000000LL;
ll V, E;

vector<ll> rec(ll bit, ll v, ll tim) {
  if (bit==(1<<v)) {
    if (dist.at(0).at(v) != -1 && tim + dist.at(0).at(v) <= times.at(0).at(v)) {
      return {dist.at(0).at(v), 1, tim};
    } else {
      return {INF,0,0};
    }
  }
  
  if (dp.at(bit).at(v).at(0) != -1 && dp.at(bit).at(v).at(0) < INF) {
    if (tim < dp.at(bit).at(v).at(2)) return dp.at(bit).at(v);
  }
  
  ll res = INF;
  ll cnt = 0;
  ll bit2 = bit & ~(1<<v);
  
  rep(i,0,V) {
    if ((bit2 & (1<<i)) && dist.at(i).at(v) != -1) {
      if (tim + dist.at(i).at(v) > times.at(i).at(v)) continue;
      vector<ll> tmp_p = rec(bit2, i, tim+dist.at(i).at(v));
      ll tmp = tmp_p.at(0) + dist.at(i).at(v);
      if (tmp < res) {
        res = tmp;
        cnt = tmp_p.at(1);
      } else if (tmp == res) {
        cnt += tmp_p.at(1);
      }
    }
  }
  
  if (res >= INF) return {INF,0,0};
  else return dp.at(bit).at(v) = {res,cnt,tim};
}

int main() {
  cin >> V >> E;
  
  dist.assign(V, vector<ll>(V, -1LL));
  times.assign(V, vector<ll>(V, -1LL));
  rep(i,0,E) {
    ll s,t,d,time;
    cin >> s >> t >> d >> time;
    s--;t--;
    dist.at(s).at(t) = d;
    dist.at(t).at(s) = d;
    times.at(s).at(t) = time;
    times.at(t).at(s) = time;
  }
  
  dp.assign((1<<V)+1, vector<vector<ll>>(V, {-1LL, 0LL, 0LL}));
  
  vector<ll> res_p = rec((1<<V)-1, 0, 0);;
  
    
  if (res_p.at(0) >= INF) cout << "IMPOSSIBLE" << endl;
  else cout << res_p.at(0) << " " << res_p.at(1) << endl;
}
