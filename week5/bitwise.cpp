#include<vector>
using namespace std;
#define ll long long

bool getBit(ll num, int idx) {
	return ((num >> idx) & 1);
}

ll setBit(ll num, int idx, bool val) {
	return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}

ll flipBit(ll num, int idx) {
	return (num ^ (1LL << idx));
}

ll leastBit(ll num) {
	return (num & -num);
}

//num%mod, mod is a power of 2
ll Mod(ll num, ll mod) {
	return (num & mod - 1);
}

bool isPowerOfTwo(ll num) {
	return (num & num - 1) == 0;
}

int turnOnLastZero(int S) {
	return S | S + 1;
}

int turnOffLastBit(int S) {
	return S & S - 1;
}

int turnOnLastConsecutiveZeroes(int S) {
	return S | S - 1;
}

int turnOffLastConsecutiveBits(int S) {
	return S & S + 1;
}

vector<int> genAllSubmask(int mask) {
	vector<int> v;
	for (int subMask = mask;; subMask = (subMask - 1) & mask) {
		v.push_back(subMask);
		if (subMask == 0)
			break;
	}
	return v;
}

// for run __builtin_popcount in visual studio
#ifdef _MSC_VER
#include <intrin.h>
#define __builtin_popcount __popcnt
#ifdef _WIN64
#define __builtin_popcountll __popcnt64
#else
inline int __builtin_popcountll(__int64 a) {
	return __builtin_popcount((unsigned int)a) + __builtin_popcount(a >> 32);
}
#endif
#endif
