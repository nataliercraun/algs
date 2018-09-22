/*
	CSCI 270 Fall 2018
	Programming Assignment
	Name   : Natalie Craun
	Email  : craun@usc.edu
	USC ID : 5986500254
*/
#include <iostream>
#include <vector> 
#include <string>
//	Feel free to include any other C++ standard library if necessary.

using namespace std;
//	You can add any custom classes / helper functions here.

void printGrid(vector<vector<int> > G, int N) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << G[i][j]; 
			cout << " "; 
		}
		cout << endl; 
	}

}

int solve(int N, vector<vector<int> > G) {
/*
	Please complete this function.
	N: Number of rows / columns of the grid.
	G: A 2d vector (N*N) indicating the grid.
		G[0][0] is the top left corner
		G[N-1][N-1] is the bottom right corner
	Return: the minimum life Brain needs to complete his task.
*/ 
	// Need to find the path that includes the min. amount <= 0
	// the largest min. amount <<--- BFS but keep track of path with largest min. 

	// MTG Vector 
	vector<vector<int> > mtg; 
	vector<vector<int> > runningSum; 
	mtg.resize(N); 
	runningSum.resize(N); 
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			runningSum[i].push_back(0);
			mtg[i].push_back(0); 
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ( (i+1 <= N-1) && (j+1 <= N-1)) {
				if (max((G[i][j]+G[i+1][j]), (G[i][j]+G[i][j+1])) == G[i][j]+G[i+1][j]) {
					G[i+1][j] = G[i][j]+G[i+1][j];
				} else {
					G[i][j+1] = G[i][j]+G[i][j+1];
				}
				
			} else if ( (i+1 <= N-1) && (j+1 > N-1)) {
				G[i+1][j] = G[i][j]+G[i+1][j];  
			} else {
				G[i][j+1] = G[i][j]+G[i][j+1]; 
			} 

			printGrid(G, N); 
			cout << endl; 

			// if (G[i][j] < 0) {
			// 	mtg[i][j] += (G[i][j] + 1); 
			// } else if (G[i][j] == 0) {
			// 	mtg[i][j] += 1; 
			// } else {
			// 	mtg[i][j] = 0; 
			// }
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << mtg[i][j];
			cout << " "; 		
		}
	}

	cout << "running sum "; 

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			cout << G[i][j];
			cout << " "; 		
		}
	}


	return 0; // replace this obviously 
}

//	The main function reads the input and outputs your answer.
//	Please do not modify it. (Assume the input is well-formed;
//	You don't need to do any error-check)
int main(int argc, char **argv) {
	int N;
	vector<vector<int> > G;
	cout << "what is N" << endl; 
	cin >> N;
	G.resize(N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			int tmp;
			cin >> tmp;
			G[i].push_back(tmp);
		}
	}
	cout << solve(N, G) << endl;
	return 0;
}