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
  int Q;
  cin >> Q;

  vector<int> vec = {};
  rep(i,0,Q) {
    int c;
    cin >> c;
    if (c == 1) {
      int x;
      cin >> x;
      vec.push_back(x);
    } else {
      int k;
      cin >> k;
      // k--;
      cout << vec.at(vec.size() - k) << endl;
    }
  }
}
