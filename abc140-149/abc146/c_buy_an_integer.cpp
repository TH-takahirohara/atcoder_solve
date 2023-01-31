#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

ll A,B,X;

bool isok(ll x) {
  string str = to_string(x);
  ll keta = str.size();
  return A * x + B * keta <= X;
}

int main() {
  cin >> A >> B >> X;
  
  ll left = -1;
  ll right = 1000000001;
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;
    if (isok(mid)) left = mid;
    else right = mid;
  }
  
  if (left == -1) cout << 0 << endl;
  else cout << right - 1 << endl;
}

