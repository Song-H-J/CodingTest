#include<stdio.h>

int func2(int arr[], int N) // O(N^2)
{
	for (int i = 0; i<N; i++) {
		for (int j = i+1; j<N; j++) {
			if (arr[i] + arr[j] == 100)
				return 1;
		}
	}
	return 0;	
}

int main()
{
	//int arr[] = {1, 52, 48};
	//int N = 3;
    //int arr[] = {50, 42};
	//int N = 2;
    int arr[] = {4, 13, 63, 87};
	int N = 4;
    
	int ans = func2(arr, N);
	printf("%d", ans);
	return 0;
}