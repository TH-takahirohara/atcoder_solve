#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  
  vector<ll> a(46, 0), b(46, 0), c(46, 0);
  
  rep(i, N) {
    int tmp;
    cin >> tmp;
    a.at(tmp % 46) += 1;
  }
  rep(i, N) {
    int tmp;
    cin >> tmp;
    b.at(tmp % 46) += 1;
  }
  rep(i, N) {
    int tmp;
    cin >> tmp;
    c.at(tmp % 46) += 1;
  }
  
  ll sum = 0LL;
  for (int i=0; i<46; i++) {
    for (int j=0; j<46; j++) {
      for (int k=0; k<46; k++) {
        if ((i+j+k) % 46 == 0) {
          sum += a.at(i) * b.at(j) * c.at(k);
        }
      }
    }
  }
  
  cout << sum << endl;
}

