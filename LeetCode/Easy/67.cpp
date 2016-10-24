#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define OUT(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
#define UNQ(x) sort(ALL(x)),(x).erase(unique(ALL(x)),(x).end())
#define x first
#define y second
#define mp make_pair
#define pb push_back
template<class T> void rd(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,long long n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
typedef long long ll;
using namespace std;
/****head****/
class Solution {
        public:
                string addBinary(string a, string b) {
                        if(a.size() < b.size()) swap(a, b);
                        reverse(a.begin(), a.end());
                        reverse(b.begin(), b.end());
                        a.push_back('0');
                        while(a.size() > b.size()) b.push_back('0');
                        string res((int)a.size(), '0');
                        int flag = 0;
                        for(int i = 0, t1, t2, t; i < (int)a.size(); ++i){
                                t1 = a[i]-'0'; t2 = b[i]-'0'; t = flag + t1 + t2;
                                res[i] = (t % 2) + '0';
                                if(t > 1) {
                                        flag = 1;
                                } else {
                                        flag = 0;
                                }
                        }
                        if(res[(int)res.size()-1] == '0') res.erase(res.end()-1);
                        reverse(res.begin(), res.end());
                        return res;
                }
}A;
int main() {
        cout << A.addBinary("1", "11") << endl;
        return 0;
}
