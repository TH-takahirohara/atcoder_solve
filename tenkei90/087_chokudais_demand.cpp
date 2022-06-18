// 087 全点対間最短経路はワーシャルフロイド法 ／ 答えで二分探索
// 自力でACできた。
#include <bits/stdc++.h>
#include <atcoder/segtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll INF = 1LL << 59;

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

ll N, P, K;

void chA(vector<vector<ll>> &A, ll num) {
  rep(i,0,N) {
    rep(j,0,N) {
      if (A.at(i).at(j) == -1) A.at(i).at(j) = num;
    }
  }
}

void fw(vector<vector<ll>> &A) {
  rep(k,0,N) {
    rep(i,0,N) {
      rep(j,0,N) {
        A.at(i).at(j) = min(A.at(i).at(j), A.at(i).at(k) + A.at(k).at(j));
      }
    }
  }
}

ll cntUndP(vector<vector<ll>> &A) {
  ll cnt = 0LL;
  rep(i,0,N) {
    rep(j,0,N) {
      if (A.at(i).at(j) <= P) cnt++;
    }
  }
  return (cnt - N) / 2;
}

int main() {
  cin >> N >> P >> K;
  
  vector<vector<ll>> A(N, vector<ll>(N));
  rep(i,0,N) rep(j,0,N) cin >> A.at(i).at(j);
  
  vector<vector<ll>> Ainf = A;
  chA(Ainf, INF);
  fw(Ainf);
  
  if (cntUndP(Ainf) == K) {
    cout << "Infinity" << endl;
    return 0;
  }
  
  ll lef = 0, rig = 1000000001;
  while (rig - lef > 1) {
    ll mid = lef + (rig - lef) / 2;
    vector<vector<ll>> Atmp = A;
    chA(Atmp, mid);
    fw(Atmp);
    if (cntUndP(Atmp) > K) lef = mid;
    else rig = mid;
  }
  
  ll left = 0, right = 1000000001;
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;
    vector<vector<ll>> Atmp = A;
    chA(Atmp, mid);
    fw(Atmp);
    if (cntUndP(Atmp) >= K) left = mid;
    else right = mid;
  }
  
  cout << right - rig << endl;
}

