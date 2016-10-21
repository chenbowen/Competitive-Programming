#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>

using namespace std;

#define LOCAL
#define maxn 1010

struct BigInteger {
    static const int BASE = 1e8;
    static const int WIDTH = 8;
    vector<int> s;
    
    BigInteger(long long num = 0) { *this = num; }
    BigInteger operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % WIDTH);
            num /= BASE;
            
        } while(num > 0);
        return *this;
    }
    BigInteger operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end-WIDTH);
            sscanf(str.substr(start, end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    BigInteger operator + (const BigInteger& b) const {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            if (i < s.size()) g += s[i];
            if (i < b.s.size()) g += b.s[i];
            c.s.push_back(g % BASE);
            g /= BASE;
        }
        return c;
    }
    BigInteger operator += (const BigInteger& b) {
        *this = *this + b; return *this;
    }
    bool operator < (const BigInteger& b) const {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = 0; i < s.size(); i++) 
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
};

ostream& operator << (ostream &out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}
istream& operator >> (istream &in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    string str = "123456780000000031415";
    BigInteger a, b;
    a = str;
    cin >> b;
    cout << (b < a) << endl;
    
    return 0;
}