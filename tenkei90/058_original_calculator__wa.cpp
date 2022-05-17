// 058 キーワード：周期性を考える
// 方向性は合っていると思うが、どうしても3つWAが出る。テストケースを見ても分からず。
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
  ll loop_start_cnt = 0;
  rep(i,0,1000000) {
    ll nx = next_num(now);
    if (vec.at(nx) == -1) {
      vec.at(nx) = vec.at(now) + 1;
      now = nx;
    } else {
      loop = vec.at(now) - vec.at(nx) + 1;
      loop_start_cnt = vec.at(nx) - 1;
      break;
    }
  }
  
  if (K <= loop_start_cnt) {
    ll ind = N;
    rep(i,0,K) {
      ll nx = next_num(ind);
      ind = nx;
    }
    cout << ind << endl;
    return 0;
  } else {
    ll push_cnt = (K - loop_start_cnt) % loop + loop_start_cnt;
    ll ind = N;
    rep(i,0,push_cnt) {
      ll nx = next_num(ind);
      ind = nx;
    }
    cout << ind << endl;
    return 0;
  }
}

