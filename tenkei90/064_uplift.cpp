#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

template<class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int INF = 1000000000;

void calc(vector<bool> &r_high, vector<ll> &diffs, ll V, ll idx, ll &sum) {
  if (r_high.at(idx)) {
    if (V >= 0) {
      diffs.at(idx) += V;
      sum += V;
    } else {
      if (diffs.at(idx) + V >= 0) {
        diffs.at(idx) += V;
        sum += V;
      } else {
        ll pre = diffs.at(idx);
        diffs.at(idx) = abs(pre + V);
        r_high.at(idx) = false;
        sum += (diffs.at(idx) - pre);
      }
    }
  } else {
    if (V < 0) {
      diffs.at(idx) += abs(V);
      sum += abs(V);
    } else {
      if (diffs.at(idx) - V >= 0) {
        diffs.at(idx) -= V;
        sum -= V;
      } else {
        ll pre = diffs.at(idx);
        diffs.at(idx) = abs(pre - V);
        r_high.at(idx) = true;
        sum += (diffs.at(idx) - pre);
      }
    }
  }
}

int main() {
  ll N,Q;
  cin >> N >> Q;
  vector<ll> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  vector<bool> r_high(N-1);
  vector<ll> diffs(N-1);
  
  rep(i,0,N-1) {
    if (A.at(i) < A.at(i+1)) r_high.at(i) = true;
    else r_high.at(i) = false;
    diffs.at(i) = abs(A.at(i) - A.at(i+1));
  }
  
  ll sum = 0;
  rep(i,0,N-1) sum += diffs.at(i);
  
  rep(i,0,Q) {
    ll L,R,V;
    cin >> L >> R >> V;
    L--;R--;
    
    if (L-1 >= 0) {
      calc(r_high, diffs, V, L-1, sum);
    }
    
    if (R <= N-2) {
      calc(r_high, diffs, -V, R, sum);
    }
    cout << sum << endl;
  }
}
