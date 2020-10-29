#include<cstring>
#include <iostream>

#define N          4
#define N_OF_CASES 5040 // 10P4

typedef struct {
	int strike;
	int ball;
} Result;

// API
extern Result query(int guess[]);

Result simulate(int guess1[], int guess2[]) {
	Result ret;
	ret.strike = 0;
	ret.ball = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(guess1[i] == guess2[j] ) {
				if(i == j) ret.strike++;
				else ret.ball++;
			} 
		}
	}
	return ret;
}


// brute-force problem
void doUserImplementation(int guess[]) {

	int candidate[N_OF_CASES][4];

	// fill all candidate 
	int idx = 0;
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++) {
			if(j == i) continue;
			for(int k = 0; k < 10; k++) {
				if(k == i || k == j) continue;
				for(int l = 0; l < 10; l++) {
					if(l == i || l == j || l == k) continue;
					candidate[idx][0] = i;
					candidate[idx][1] = j;
					candidate[idx][2] = k;
					candidate[idx][3] = l;
					idx++;
				}
			}
		}


	idx = 0; 
	bool flag[N_OF_CASES];
	for(int i = 0; i < N_OF_CASES; i++)
		flag[i] = true;
	// do guess while strike == 4
	do{
		memcpy(guess,candidate[idx++],N*sizeof(int));
		Result ret = query(guess);

		// won the game
		if(ret.strike == N) break;

		// remove unavailable cadidates
		for(int i = idx; i < N_OF_CASES; i++) {
			if(flag[i]) {
				Result sim_ret = simulate(candidate[i], guess);
				if(sim_ret.strike != ret.strike || sim_ret.ball != ret.ball)
					flag[i] = false;
				if(flag[i]) remain++;
			}
		}

		// find next candidate
		while(!flag[idx]&&(idx<N_OF_CASES)) {
			idx++;
		}

	} while(idx<N_OF_CASES);

}

