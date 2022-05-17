// 058 キーワード：周期性を考える
// waの解法では、loop_start_cnt をloop開始の箇所から-1していたが、これがいけなかった。
// （0 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3 -> ... というループを、 0 -> [ 1 -> 2 -> 3 ] -> [ 1 -> 2 -> 3 ] -> ... という周期で捉えていた。）
// このようにしていたことで、例えば 0 -> 1 -> 2 -> 3 -> 1 -> 2 -> 3 -> ... というループだったとしても、
// loop_start_cntが0になってしまうので、 0 -> 1 -> 2 -> 3 -> 0 -> 1 -> 2 -> 3 -> ... というループとして取り扱ってしまっていたため、WAとなっていた。
// loop_start_cntは-1せず、上記のループで言えば、
// 0 -> [ 1 -> 2 -> 3 ] -> [ 1 -> 2 -> 3 ] -> ... ではなく
// 0 -> 1 -> [ 2 -> 3 -> 1 ]　-> [ 2 -> 3 -> 1 ] -> ... として捉え直して書き直すことで、WAしていた箇所がACになった。
#include <bits/stdc++.h>
using namespace std;
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

ll next_num(ll x) {
  ll inix = x;
  ll sum_keta = 0;
  while (x > 0) {
    sum_keta += (x % 10);
    x /= 10;
  }
  return (sum_keta + inix) % 100000;
}

int main() {
  ll N,K;
  cin>>N>>K;
  
  vector<ll> vec(100000, -1);
  vec.at(N) = 0;
  
  ll now = N;
  ll loop = 0;
  ll lsi = -1;
  ll loop_start_cnt = 0;
  rep(i,0,100000) {
    ll nx = next_num(now);
    if (vec.at(nx) == -1) {
      vec.at(nx) = vec.at(now) + 1;
      now = nx;
    } else {
      loop = vec.at(now) - vec.at(nx) + 1;
      lsi = nx;
      loop_start_cnt = vec.at(nx);
      break;
    }
  }
  
  if (K < loop_start_cnt) {
    ll ind = N;
    rep(i,0,K) {
      ll nx = next_num(ind);
      ind = nx;
    }
    cout << ind << endl;
    return 0;
  } else {
    ll push_cnt = (K - (loop_start_cnt + 1)) % loop + loop_start_cnt + 1;
    ll ind = N;
    rep(i,0,push_cnt) {
      ll nx = next_num(ind);
      ind = nx;
    }
    cout << ind << endl;
    return 0;
  }
}

