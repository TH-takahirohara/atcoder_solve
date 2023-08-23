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
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> A(N);

  rep(i,0,N) {
    string s;
    int a;
    cin >> s >> a;
    S.at(i) = s;
    A.at(i) = a;
  }

  int min_v = 1.2e9;
  int idx = -1;
  rep(i,0,N) {
    if (A.at(i) < min_v) {
      min_v = A.at(i);
      idx = i;
    }
  }

  rep(i,0,N) {
    cout << S.at((idx + i) % N) << endl;
  }
}
