#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  
  vector<ll> data;
  rep(i, N) {
    ll ai, bi;
    cin >> ai >> bi;
    data.push_back(bi);
    data.push_back(ai - bi);
  }
  
  sort(data.begin(), data.end(), greater<ll>());
  
  ll sum = 0LL;
  
  rep(i, K) {
    sum += data.at(i);
  }
  
  cout << sum << endl;
}

