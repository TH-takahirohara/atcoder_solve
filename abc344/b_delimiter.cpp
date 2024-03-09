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
  vector<int> vec;
  while (true) {
    int A;
    cin >> A;
    if (A == 0) {
      vec.push_back(A);
      break;
    } else {
      vec.push_back(A);
    }
  }
  reverse(vec.begin(), vec.end());

  rep(i,0,vec.size()) {
    cout << vec.at(i) << endl;
  }
}
