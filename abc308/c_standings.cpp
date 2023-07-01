#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

struct bunsuu {
  ll bunsi, bunbo, idx;
};

bool comp(bunsuu& lh, bunsuu& rh) {
  if (lh.bunsi * rh.bunbo == rh.bunsi * lh.bunbo) {
    return lh.idx < rh.idx;
  }
  return lh.bunsi * rh.bunbo > rh.bunsi * lh.bunbo;
}

int main() {
  int N;
  cin >> N;
  vector<bunsuu> vec(N);
  rep(i,0,N) {
    ll a, b;
    cin >> a >> b;
    bunsuu bun = {a, a+b, i+1};
    vec.at(i) = bun;
  }

  sort(vec.begin(), vec.end(), comp);
  rep(i,0,N) {
    cout << vec.at(i).idx << " ";
  }
  cout << endl;
}
