#include<stdio.h>

int func1(int N)
{
	int sum = 0;
	for (int i = 3; i<=N; i++) {
		if (i % 3 == 0) {
			sum+=i;
		} else if (i % 5 == 0) {
			sum+=i;
		}
	}
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