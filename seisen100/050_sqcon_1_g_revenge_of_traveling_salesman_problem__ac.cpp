#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

vector<vector<ll> > dist;
vector<vector<ll> > times;
vector<vector<pair<ll,ll>> > dp;
ll INF = 11000000000000000LL;
ll V, E;
map<ll,ll> saitan;

pair<ll,ll> rec(ll bit, ll v) {
  
  if (bit==(1<<v)) {
    if (dist.at(0).at(v) != -1) {
      return dp.at(bit).at(v) = make_pair(dist.at(0).at(v), 1);
    } else {
      return make_pair(INF, 0);
    }
  }
  
  if (dp.at(bit).at(v).first != -1LL && dp.at(bit).at(v).first < INF) {
    return dp.at(bit).at(v);
  }
  
  ll res = INF;
  ll cnt = 0;
  ll bit2 = bit & ~(1<<v);
  
  rep(i,0,V) {
    if ((bit2 & (1<<i)) && dist.at(i).at(v) != -1) {
      pair<ll,ll> tmp_p = rec(bit2, i);
      if (tmp_p.first + dist.at(i).at(v) > times.at(i).at(v)) continue;
      ll tmp = tmp_p.first + dist.at(i).at(v);
      if (tmp < res) {
        res = tmp;
        cnt = tmp_p.second;
      } else if (tmp == res) {
        cnt += tmp_p.second;
      }
    }
  }
  
  if (res >= INF) return make_pair(INF,0);
  else return dp.at(bit).at(v) = make_pair(res,cnt);
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
  
  dp.assign((1<<V)+1, vector<pair<ll,ll>>(V, make_pair(-1LL,0LL)));
  
  pair<ll,ll> res_p = rec((1<<V)-1, 0);;
  
    
  if (res_p.first >= INF) cout << "IMPOSSIBLE" << endl;
  else cout << res_p.first << " " << res_p.second << endl;
}
