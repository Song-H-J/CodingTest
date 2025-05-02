#include<stdio.h>

int func4(int N) // O(lgN)
{
	int i;
    for (i = 1; i < N; i = i<<1) {
        continue;
	}
    if (i > N)
        i = i>>1;
	return i;
}

int main()
{
	//int N = 5;
	//int N = 97615282;
	int N = 1024;

	int ans = func4(N);
	printf("%d", ans);
	return 0;
}