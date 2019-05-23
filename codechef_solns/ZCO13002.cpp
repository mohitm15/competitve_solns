//ZCO Practice Contest : ZCO13002 : Little Red Riding Hood

#include <iostream>
#include <utility>
#include <cmath>

int main(){
	int N, M;
	std::cin >> N >> M;
	
	int** grid = new int* [N];
	for(int iii=0; iii<N; iii++){
		grid[iii] = new int[N];
		for(int jjj=0; jjj<N; jjj++)
			std::cin >> grid[iii][jjj];
	}
	
	int** charms = new int* [M];
	for(int iii=0; iii<M; iii++){
		charms[iii] = new int[M];
		std::cin >> charms[iii][0] >> charms[iii][1] >> charms[iii][2];
	}
	
	int** safe = new int* [N];
	for(int iii=0; iii<N; iii++){
		safe[iii] = new int[N]();
	}
	
	for(int iii=0; iii<M; iii++)
		for(int xxx=charms[iii][0]-1-charms[iii][2]; xxx<=charms[iii][0]-1+charms[iii][2]; xxx++)
			for(int yyy=charms[iii][1]-1-charms[iii][2]; yyy<=charms[iii][1]-1+charms[iii][2]; yyy++)
				if ((0 <= xxx) && (xxx < N) && (0 <= yyy) && (yyy < N) && (abs(charms[iii][0]-1 - xxx) + abs(charms[iii][1]-1 - yyy) <= charms[iii][2]))
					safe[xxx][yyy] = 1;
	
	int** score = new int* [N];
	for(int iii=0; iii<N; iii++){
		score[iii] = new int[N]();
		for(int jjj=0; jjj<N; jjj++){
			if ((iii==0) && (jjj==0)){
				score[iii][jjj] = grid[0][0];
				continue;
			}
			score[iii][jjj] = -1024;
			if (!safe[iii][jjj]){
				continue;
			}
			if ((iii==0)){
				if (score[iii][jjj-1] != -1024)
					score[iii][jjj] = grid[iii][jjj] + score[iii][jjj-1];
				continue;
			}
			if ((jjj==0)){
				if (score[iii-1][jjj] != -1024)
					score[iii][jjj] = grid[iii][jjj] + score[iii-1][jjj];
				continue;
			}
			if ((score[iii-1][jjj] != -1024) && (score[iii][jjj-1] != -1024)){
				score[iii][jjj] = grid[iii][jjj] + std::max(score[iii-1][jjj], score[iii][jjj-1]);
				continue;	
			}
			if (score[iii-1][jjj] != -1024){
				score[iii][jjj] = grid[iii][jjj] + score[iii-1][jjj];
				continue;
			}
			if (score[iii][jjj-1] != -1024){
				score[iii][jjj] = grid[iii][jjj] + score[iii][jjj-1];
				continue;
			}
		}
	}
	
	if (score[N-1][N-1] == -1024)
		std::cout << "NO" << std::endl;
	else{
		std::cout << "YES" << std::endl;
		std::cout << score[N-1][N-1] << std::endl;
	}
			
}
