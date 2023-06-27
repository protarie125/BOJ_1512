#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int m;
string s;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> m >> s;
	auto slen = static_cast<int>(s.length());

	auto ans = numeric_limits<int>::max();
	for (auto p = m; 1 <= p; --p) {
		auto ans1 = int{ 0 };
		for (auto i = 0; i < p; ++i) {
			auto nA = int{ 0 };
			auto nC = int{ 0 };
			auto nG = int{ 0 };
			auto nT = int{ 0 };
			for (auto j = i; j < slen; j += p) {
				if (slen <= j) {
					continue;
				}

				if ('A' == s[j]) {
					++nA;
					continue;
				}

				if ('C' == s[j]) {
					++nC;
					continue;
				}

				if ('G' == s[j]) {
					++nG;
					continue;
				}

				if ('T' == s[j]) {
					++nT;
					continue;
				}
			}

			ans1 += nA + nC + nG + nT - max({ nA, nC, nG, nT });
		}

		if (ans1 < ans) {
			ans = ans1;
		}

		auto ans2 = int{ 0 };
		for (auto i = 0; i < p; ++i) {
			auto nA = int{ 0 };
			auto nC = int{ 0 };
			auto nG = int{ 0 };
			auto nT = int{ 0 };
			for (auto j = slen - 1 - i; 0 <= j; j -= p) {
				if (slen <= j) {
					continue;
				}

				if ('A' == s[j]) {
					++nA;
					continue;
				}

				if ('C' == s[j]) {
					++nC;
					continue;
				}

				if ('G' == s[j]) {
					++nG;
					continue;
				}

				if ('T' == s[j]) {
					++nT;
					continue;
				}
			}

			ans2 += nA + nC + nG + nT - max({ nA, nC, nG, nT });
		}

		if (ans2 < ans) {
			ans = ans2;
		}

		if (0 == ans) {
			break;
		}
	}

	cout << ans;

	return 0;
}