#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		vector <long long> vec;
		for (int i = 1; i <= n; i++) {
			vec.push_back((n-i)*a + (i-1)*b); 
		}
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}
}