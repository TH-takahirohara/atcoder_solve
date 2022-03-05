#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  
  ll me = __gcd(__gcd(A, B), C);
  cout << A/me + B/me + C/me - 3 << endl;
}
