#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main () {

	vector<int> A;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		A.push_back(tmp);
	}

	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < n; i++) {
		pq.push(A[i]);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int top = pq.top();
		pq.pop();
		int top2 = pq.top();
		pq.pop();
		ans += top + top2;
		pq.push(top + top2);
	}
	printf("%d\n",ans);
}