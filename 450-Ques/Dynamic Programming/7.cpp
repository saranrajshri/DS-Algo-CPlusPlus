#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;

int solve(vector<vector<int>> a, vector<vector<int>> t, vector<int> e, vector<int> x) {
	vector<int> dp1(a[0].size(), INT_MAX);
	vector<int> dp2(a[0].size(), INT_MAX);

	dp1[0] = e[0] + a[0][0];
	dp2[0] = e[1] + t[0][0];

	for(int i = 1; i < dp1.size(); i++) {
		dp1[i] = min(dp1[i - 1] + a[0][i], dp2[i - 1] + t[1][i] + a[0][i]);
		dp2[i] = min(dp2[i - 1] + t[0][i], dp1[i - 1] + t[0][i] + a[1][i]);
	}

	return min(dp1[dp1.size() - 1] + x[0], dp2[dp1.size() - 1] + x[1]);
}

int32_t main() {
	vector<vector<int>> a =  { { 4, 5, 3, 2 },
                   			 { 2, 10, 1, 4 } };
    vector<vector<int>> t =  { { 0, 7, 4, 5 },
                             { 0, 9, 2, 8 } };

    vector<int> e = { 10, 12 };
    vector<int> x = { 18, 7 };

    cout << solve(a, t, e, x);                           
	return 0;	
}
