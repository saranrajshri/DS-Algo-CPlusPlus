#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>arr, vector<int> temp, int left, int mid, int right) {
	int i = left;
	int j = mid;
	int k = left;
	int inverseCount = 0;

	while(i <= (mid - 1) && j <= right) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
			
			inverseCount += (mid - i);
		}
	}

	while(i <= (mid - 1)) {
		temp[k++] = arr[i++];
	}

	while(j <= right) {
		temp[k++] = arr[j++];
	}

	for(int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}

	return inverseCount;
} 

int mergeSort(vector<int>arr, vector<int> temp, int left, int right) {
	int inverseCount = 0;

	if(right > left) {
		int mid = left + (right - left) / 2;
		
		inverseCount += mergeSort(arr, temp, left, mid);
		inverseCount += mergeSort(arr, temp, mid + 1, right);
		inverseCount += merge(arr, temp, left, mid + 1, right);
	}
	return inverseCount;
}

int solve(vector<int> arr) {
	vector<int> tempArr(arr.size());	

	return mergeSort(arr, tempArr, 0, arr.size() - 1);
}

int main() {
	vector<int>arr = { 1, 20, 6, 4, 5 };
	cout << solve(arr);
	return 0;	
}
