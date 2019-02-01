struct Bign {
    vector<int> num;
    Bign() {
        num.clear();
    }
    Bign(int x) {
        num.clear();
        while(x) {
            num.PB(x % 10);
            x /= 10;
        }
        if(!SZ(num)) num.PB(0);
    }
    Bign(char *p) {
        num.clear();
        while(*p) {
            num.PB(*p - '0');
            p++;
        }
        reverse(ALL(num));
        if(!SZ(num)) num.PB(0);
    }
    bool operator < (const Bign &rhs) const {
        if(SZ(num) != SZ(rhs.num)) return SZ(num) < SZ(rhs.num);
        for(int i = SZ(num) - 1; i >= 0; i--) {
            if(num[i] != rhs.num[i]) return num[i] < rhs.num[i];
        }
        return 0;
    }
    bool operator > (const Bign &rhs) const {
        if(SZ(num) != SZ(rhs.num)) return SZ(num) > SZ(rhs.num);
        for(int i = SZ(num) - 1; i >= 0; i--) {
            if(num[i] != rhs.num[i]) return num[i] > rhs.num[i];
        }
        return 0;
    }
    bool operator == (const Bign &rhs) const {
        if(SZ(num) != SZ(rhs.num)) return 0;
        for(int i = SZ(num) - 1; i >= 0; i--) {
            if(num[i] != rhs.num[i]) return 0;
        }
        return 1;
    }
    bool operator <= (const Bign &rhs) const {
        return *this < rhs || *this == rhs;
    }
    bool operator >= (const Bign &rhs) const {
        return *this > rhs || *this == rhs;
    }
    bool operator != (const Bign &rhs) const {
        return !(*this == rhs);
    }
};
inline Bign operator + (const Bign &a , const Bign &b) {
    Bign c;
    REP(i , max(SZ(a.num) , SZ(b.num))) {
        if(i >= SZ(c.num)) c.num.PB(0);
        if(SZ(a.num) > i) c.num[i] += a.num[i];
        if(SZ(b.num) > i) c.num[i] += b.num[i];
        if(c.num[i] >= 10) {
            if(i + 1 >= SZ(c.num)) c.num.PB(0);
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
        }
    }
    while(SZ(c.num) && c.num.back() == 0) c.num.pop_back();
    if(!SZ(c.num)) c.num.PB(0);
    return c;
}
inline Bign operator * (const Bign &a , const Bign &b) {
    Bign c;
    REP(i , SZ(a.num)) {
        REP(j , SZ(b.num)) {
            if(i + j >= SZ(c.num)) c.num.PB(0);
            c.num[i + j] += a.num[i] * b.num[j];
        }
    }
    REP(i , SZ(c.num)) {
        if(c.num[i] >= 10) {
            if(i + 1 >= SZ(c.num)) c.num.PB(0);
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
        }
    }
    while(SZ(c.num) && c.num.back() == 0) c.num.pop_back();
    if(!SZ(c.num)) c.num.PB(0);
    return c;
}
inline Bign operator - (const Bign &a , const Bign &b) { // a >= b
    Bign c;
    c.num = a.num;
    REP(i , SZ(c.num)) {
        if(SZ(b.num) > i) c.num[i] -= b.num[i];
        if(c.num[i] < 0) {
            c.num[i + 1]--;
            c.num[i] += 10;
        }
    }
    while(SZ(c.num) && c.num.back() == 0) c.num.pop_back();
    if(!SZ(c.num)) c.num.PB(0);
    return c;
}
inline void print(const Bign &x) {
    for(int i = SZ(x.num) - 1; i >= 0; i--) putchar(x.num[i] + '0');
    putchar('\n');
}
inline Bign operator / (const Bign &a , const Bign &b) {
    Bign c , r(0);
    for(int i = SZ(a.num) - 1; i >= 0; i--) {
        r = (r * Bign(10)) + Bign(a.num[i]);
        c.num.PB(0);
        while(r >= b) {
            c.num.back()++;
            r = r - b;
        }
    }
    reverse(ALL(c.num));
    while(SZ(c.num) && c.num.back() == 0) c.num.pop_back();
    if(!SZ(c.num)) c.num.PB(0);
    return c;
}
inline Bign operator % (const Bign &a , const Bign &b) {
    return a - ((a / b) * b);
}
Bign gcd(Bign a , Bign b) {
    return b == Bign(0) ? a : gcd(b , a % b);
}
