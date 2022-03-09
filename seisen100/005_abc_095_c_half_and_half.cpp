#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  ll sum = 0;
  if (A+B >= 2*C) {
    if (X < Y) {
      sum += C * (2 * X);
      if (B >= 2*C) sum += C * (2 * (Y - X));
      else sum += B * (Y - X);
    } else {
      sum += C * (2*Y);
      if (A >= 2*C) sum += C * (2 * (X - Y));
      else sum += A * (X - Y);
    }
  } else {
    sum += A*X + B*Y;
  }
  
  cout << sum << endl;
}

