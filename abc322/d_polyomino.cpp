#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

vector<string> kaiten(vector<string> vec) {
  vector<string> nv(4, "....");
  for (int i=0; i <= 3; i++) {
    for (int j=0; j <= 3; j++) {
      nv.at(i).at(j) = vec.at(j).at(3-i);
    }
  }
  return nv;
}

vector<vector<bool>> crop(vector<string> vec) {
  int x1 = 10, x2 = -1, y1 = 10, y2 = -1;
  rep(i,0,vec.size()) {
    rep(j,0,4) {
      if (vec.at(i).at(j) == '#') {
        x1 = min(x1, j);
        x2 = max(x2, j);
        y1 = min(y1, i);
        y2 = max(y2, i);
      }
    }
  }

  vector<vector<bool>> res(y2-y1+1, vector<bool>(x2-x1+1, false));
  rep(i,y1,y2+1) {
    rep(j,x1,x2+1) {
      if (vec.at(i).at(j) == '#') {
        res.at(i-y1).at(j-x1) = true;
      }
    }
  }
  return res;
}

bool umeru(vector<vector<bool>> nfir, vector<vector<bool>> &filled) {
  rep(i1,0,4-nfir.size()) {
    rep(i2,0,4-nfir.at(0).size()) {
      rep(i11,0,nfir.size()) {
        rep(i22,0,nfir.at(0).size()) {
          if (!filled.at(i1+i11).at(i2+i22) && nfir.at(i11).at(i22)) {
            filled.at(i1+i11).at(i2+i22) = true;
          } else if (filled.at(i1+i11).at(i2+i22) && nfir.at(i11).at(i22)) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

vector<vector<bool>> snap(int i, int j, vector<vector<bool>> vec) {
  vector<vector<bool>> res(4, vector<bool>(4, false));
  rep(ite1,0,vec.size()) {
    rep(ite2,0,vec.at(0).size()) {
      res.at(ite1+i).at(ite2+j) = vec.at(ite1).at(ite2);
    }
  }
  return res;
}

int main() {
  vector<vector<string>> P(3, vector<string>(4));
  rep(i,0,3) {
    rep(j,0,4) {
      cin >> P.at(i).at(j);
    }
  }

  // vector<int> jun = {0,1,2};
  rep(i,0,4) {
    vector<string> fir = P.at(0);
    rep(iter1,0,i) fir = kaiten(fir);
    vector<vector<bool>> nfir = crop(fir);

    rep(i1,0,4-nfir.size()+1) {
      rep(i2,0,4-nfir.at(0).size()+1) {
        auto first = snap(i1,i2,nfir);
        rep(j,0,4) {
          vector<string> sec = P.at(1);
          rep(iter2,0,j) sec = kaiten(sec);
          vector<vector<bool>> nsec = crop(sec);
          rep(j1,0,4-nsec.size()+1) {
            rep(j2,0,4-nsec.at(0).size()+1) {
              auto second = snap(j1,j2,nsec);
              rep(k,0,4) {
                vector<string> thi = P.at(2);
                rep(iter3,0,k) thi = kaiten(thi);
                
                vector<vector<bool>> nthi = crop(thi);
                // rep(iterate1,0,nthi.size()) {
                //   rep(iterate2,0,nthi.at(0).size()) {
                //     if (nthi.at(iterate1).at(iterate2)) cout << '#';
                //     else cout << '.';
                //   }
                //   cout << endl;
                // }
                // cout << endl;
                rep(k1,0,4-nthi.size()+1) {
                  rep(k2,0,4-nthi.at(0).size()+1) {
                    auto third = snap(k1,k2,nthi);
                    // cout << "test" << endl;
                    // rep(iterate1,0,4) {
                    //   rep(iterate2,0,4) {
                    //     if (third.at(iterate1).at(iterate2)) cout << '#';
                    //     else cout << '.';
                    //   }
                    //   cout << endl;
                    // }
                    // cout << endl;
                    bool can = true;
                    rep(iii,0,4) {
                      rep(jjj,0,4) {
                        if (first.at(iii).at(jjj) && !second.at(iii).at(jjj) && !third.at(iii).at(jjj) || !first.at(iii).at(jjj) && second.at(iii).at(jjj) && !third.at(iii).at(jjj) || !first.at(iii).at(jjj) && !second.at(iii).at(jjj) && third.at(iii).at(jjj)) {
                          continue;
                        } else {
                          can = false;
                        }
                      }
                    }
                    if (can) {
                      cout << "Yes" << endl;
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
