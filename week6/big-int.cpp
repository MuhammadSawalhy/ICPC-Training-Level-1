#include <bits/stdc++.h>

#define ll long long
using namespace std;

template<int base = 10>
class bigint {
public:
    vector<int> digits;

    bigint(unsigned ll value = 0) { set_value(value); }

    bigint(string s) {
        digits.resize(s.size());
        for (int i = 0; i < (int) s.size(); i++) {
            digits[i] = s[(int) s.size() - 1 - i] - '0';
        }
    }

    template<typename RandomIt>
    bigint(RandomIt begin, RandomIt end) {
        digits.assign(begin, end);
    }

    void set_value(ll value) {
        digits.clear();
        while (value) {
            digits.push_back(value % base);
            value /= base;
        }
    }

    int size() const { return digits.size(); }

    void trim() {
        while (digits.back() == 0 && digits.size() > 1)
            digits.pop_back();
    }

    int &operator[](int i) { return digits[i]; }

    int operator[](int i) const { return digits[i]; }

    void operator*=(const bigint &rhs) {
        vector<int> res(size() + rhs.size() + 1);
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < rhs.size(); j++) {
                res[i + j] += digits[i] * rhs[j];
            }
        }
        for (int i = 0; i < (int) res.size() - 1; i++) {
            res[i + 1] += res[i] / base;
            res[i] %= base;
        }
        digits = res;
        trim();
    }

    void operator+=(const bigint &rhs) {
        digits.resize(max(size(), rhs.size()) + 1);
        int i;
        for (i = 0; i < rhs.size(); i++) {
            digits[i] += rhs[i];
            if (digits[i] >= base) {
                digits[i + 1] += digits[i] / base;
                digits[i] %= base;
            }
        }
        while (i < (int) digits.size() - 1 && digits[i] >= base) {
            digits[i + 1] = digits[i] / base;
            digits[i] %= base;
        }
        trim();
    }

    void operator%=(ll mod) {
        ll p = 1;
        ll res = 0;
        for (int i = 0; i < size(); i++) {
            res = (res + p * digits[i] % mod) % mod;
            p = p * base % mod;
        }
        *this = res;
    }

    friend bool operator==(bigint &lhs, bigint &rhs) {
        return lhs.digits == rhs.digits;
    }

    friend bool operator!=(bigint &lhs, bigint &rhs) {
        return lhs.digits != rhs.digits;
    }

    friend bool operator<(bigint &lhs, bigint &rhs) {
        if (lhs.size() != rhs.size())
            return lhs.size() < rhs.size();
        for (int i = lhs.size() - 1; i >= 0; i--) {
            if (lhs[i] < rhs[i]) return true;
            if (lhs[i] > rhs[i]) return false;
        }
        return false;// equal
    }

    friend ostream &operator<<(ostream &os, const bigint &bi) {
        for (int i = bi.size() - 1; i >= 0; i--) os << bi[i];
        return os;
    }
};

