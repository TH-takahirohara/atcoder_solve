#include <bits/stdc++.h>
// #include <atcoder/segtree>
using namespace std;
// using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int N,M;

void loop(vector<int> vec) {
  if (vec.size() == N) {
    rep(i,0,vec.size()) {
      cout << vec.at(i) << " ";
    }
    cout << endl;
    return;
  } else {
    int last = vec.at(vec.size() - 1);
    rep(i,last+1,M+1) {
      vector<int> nvec = vec;
      nvec.push_back(i);
      loop(nvec);
    }
  }
}

int main() {
  cin >> N >> M;
  
  rep(i,1,M-N+2) {
    loop({i});
  }
}

