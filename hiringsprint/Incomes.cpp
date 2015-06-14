#include <iostream>
#include <algorithm>

using namespace std;
#define N 100005

int arr[N];
int n, q;

int binary_search(int val) {
	int low = 0, high = n-1;
	int mid;
	while (low <= high) {
		mid = low + (high - low)/2;
		if (arr[mid] < val && mid < n-1 && arr[mid+1] >= val)
			return mid+1;
		else if (arr[mid] >= val)
			high = mid-1;
		else if (arr[mid] < val)
			low = mid+1;
	}
	return low;
}


int main () {	
	scanf("%d\n",&n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr,arr+n);
	scanf("%d\n",&q);
	// printf("HERE\n");
	// exit(0);
	for (int i = 0; i < q; i++) {
		int tmp;
		scanf("%d", &tmp);
		// printf("HERE %d\n",tmp);
		printf("%d\n",binary_search(tmp));	
	}

}