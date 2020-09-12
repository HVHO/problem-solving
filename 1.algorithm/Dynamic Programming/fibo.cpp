// fibo
#include <stdio.h>
#include <time.h>
#define MAX 101
int memo1[MAX];
int memo2[MAX];
int memo3[3];
int cnt;
int dpcnt;
int fibo(int n){
	cnt++;
	if (n < 2){
		return n;
	}

	return fibo(n - 1) + fibo(n - 2);
}
int fibo_rec_dp(int n){
	dpcnt++;
	if (n < 2){
		return n;
	}
	if (!memo1[n]){
		memo1[n] = fibo_rec_dp(n - 1) + fibo_rec_dp(n - 2);
	}
	return memo1[n];
}
int fibo_iter_dp(int n){
	memo2[1] = 1;
	for (int i = 2; i <= n; i++){
		memo2[i] = memo2[i - 1] + memo2[i - 2];
	}
	return memo2[n];
}
int fibo_iter_dp2(int n){
	memo3[1] = 1;
	for (int i = 2; i <= n; i++){
		memo3[i%3] = memo3[(i - 1)%3] + memo3[(i - 2)%3];
	}
	return memo3[n%3];
}
int main(){
	time_t start = clock();
	int n = 50;
//	printf("fibo(%d) = %d\n", n, fibo(n));
	printf("fibo_rec_dp(%d) = %d\n", n, fibo_rec_dp(n));
	printf("fibo_iter_dp(%d) = %d\n", n, fibo_iter_dp(n));
	printf("fibo_iter_dp2(%d) = %d\n", n, fibo_iter_dp2(n));

//	printf("cnt : %d, dpcnt : %d\n", cnt, dpcnt);
	time_t end = clock();

	printf("time : %f\n", (double)(end - start));
	return 0;
}

