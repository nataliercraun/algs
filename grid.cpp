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
	P: prevent Brian's next damage 
	D: double Brian's next healing 
	Return: the minimum life Brain needs to complete his task.
*/
	vector<vector<int> > mtg; 
	mtg.resize(N); 
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			mtg[i].push_back(0); 
		}
	}
	
	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j >= 0; j--) {

			// base cases 
			if (j == N-1 && i == N-1) {
				int temp = 0; 
				int val = G[i][j];
				while (val < 1) {
					temp++;
					val++; 
				}
				mtg[i][j] += temp; 
			} else if (j == N-1 && i < N-1) {
				mtg[i][j] = mtg[i+1][j] - G[i][j]; 
			} else if (j < N-1 && i == N-1) {
				mtg[i][j] = mtg[i][j+1] - G[i][j]; 
			} else {
				mtg[i][j] = min((mtg[i+1][j] - G[i][j]), (mtg[i][j+1] - G[i][j]));
			}
		}

		printGrid(mtg, N); 
		cout << endl; 
	}

	return mtg[0][0]; 
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