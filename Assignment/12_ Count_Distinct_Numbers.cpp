#include <iostream>
#include <unordered_map>
using namespace std;

void countDistinct(int arr[], int k, int n)
{
	unordered_map<int, int> hm;
	int dist_count = 0;
	for (int i = 0; i < k; i++) {
		if (hm[arr[i]] == 0) {
			dist_count++;
		}
		hm[arr[i]] += 1;
	}

	cout << dist_count<<" ";
	for (int i = k; i < n; i++) {
		if (hm[arr[i - k]] == 1) {
			dist_count--;
		}
		hm[arr[i - k]] -= 1;
		if (hm[arr[i]] == 0) {
			dist_count++;
		}
		hm[arr[i]] += 1;
		cout << dist_count<<" ";
	}
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		countDistinct(a,k,n);
	}

	return 0;
}