#include<stdio.h>

int func3(int N) // O(root of N)
{
	for (int i = 1; i * i <= N; i++) {
		if (i * i == N)
			return 1;
	}
	return 0;
}

int main()
{
	//int N = 9;
	//int N = 693953651;
	int N = 756580036;
	
	int ans = func3(N);
	printf("%d", ans);
	return 0;
}