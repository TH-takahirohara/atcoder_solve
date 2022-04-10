#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

double PI = 3.14159265359;

int main() {
  double a,b,x;
  cin >> a >> b >> x;
  
  double theta;
  if (x/a > a*b/2) {
    theta = atan(2 / (a*a*a) * (a*a*b - x));
  } else {
    theta = PI / 2 - atan(2*x / (a*b*b));
  }
  
  cout << fixed << setprecision(7) << theta * 180 / PI;
}
