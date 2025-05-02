#include<stdio.h>

int func1(int N)
{
	int cnt3 = N / 3;
	int cnt5 = N / 5;
	int cnt15 = N / 15;

	int sum3 = 3 * cnt3 * (cnt3 + 1) / 2;
	int sum5 = 5 * cnt5 * (cnt5 + 1) / 2;
	int sum15 = 15 * cnt15 * (cnt15 + 1) / 2;
	
	sum = sum3 + sum5 - sum15;
	return sum;
}

int main()
{
	int N;
	int ans;
	scanf("%d", &N);
	ans = func1(N);
	printf("%d", ans);
	return 0;
}