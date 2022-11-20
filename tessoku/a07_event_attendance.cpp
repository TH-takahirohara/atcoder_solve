#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int D, N;
  cin >> D >> N;
  vector<int> vec(100005);
  rep(i,0,N) {
    int l, r;
    cin >> l >> r;
    vec.at(l)++;
    vec.at(r+1)--;
  }
  rep(i,0,100004) {
    vec.at(i+1) += vec.at(i);
  }

  rep(i,1,D+1) {
    cout << vec.at(i) << endl;
  }
}
