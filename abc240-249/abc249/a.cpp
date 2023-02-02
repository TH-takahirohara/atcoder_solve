#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int a,b,c,d,e,f,x;
  cin >> a >> b >> c >> d >> e >> f >>x;
  
  int taka = 0;
  int aoki = 0;
  
  int takaloop = x / (a+c);
  taka += takaloop * a * b;
  int taka_amari = x % (a+c);
  if (taka_amari > a) {
    taka += a*b;
  } else {
    taka += taka_amari * b;
  }

  int aoloop = x / (d+f);
  aoki += aoloop * d * e;
  int ao_amari = x % (d+f);
  if (ao_amari > d) {
    aoki += d*e;
  } else {
    aoki += ao_amari * e;
  }

  if (taka > aoki) {
    cout << "Takahashi" << endl;
  } else if (aoki > taka) {
    cout << "Aoki" << endl;
  } else {
    cout << "Draw" << endl;
  }
}
