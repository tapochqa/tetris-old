
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <ctime>


using namespace std;



int main() {



	char field[20][14];
	int score = 0;
	int high_score;
	int gameover = 0;

	ifstream F;
	F.open("Text.txt", ios::in);


	cout << "WARNING!" << endl;
	cout << "This Tetris by Suckovich'n'Yurka may " << endl;
	cout << "cause agression and anger. Please don't," << endl;
	cout << "Thanx. v.0.1" << endl;

	cin.get();

	cout << "You're predicted." << endl;
		cin.get();


	int i, k;
	for (i = 19; i >= 0; i--) {
		for (k = 0; k < 14; k++) {
			field[i][k] = ' ';

		}

	}
	int del = 100;
	int i2, k2, i3, k3, i4, k4, f_flag = 0, f_rand, check_clean = 0;
	int clf = 0;
	int v, p;
	int figure_flag = 0;
	int fpos[7];
	int x_checker = 0;
	int count = 0;
	int spd = 1;
	do {

		F.open("Text.txt", ios::in);
		F >> high_score;
		system("cls");


			if (count % spd == 0) {
				for (i = 19; i >= 0; i--) {
					for (k = 0; k < 14; k++) {
						if (field[i][k] == 'o') {
							f_flag = 1;
						}
					}
				}
				if (f_flag == 1) {
					f_flag = 0;
					for (i = 19; i >= 0; i--) {
						for (k = 0; k < 14; k++) {
							if (field[i][k] == 'o'&& i == 19) {
								for (i2 = 19; i2 >= 0; i2--) {
									for (k2 = 0; k2 < 14; k2++) {
										if (field[i2][k2] == 'o') { field[i2][k2] = 'x'; }
									}
								}
							}
							if (field[i][k] == 'o'&&i != 19 && field[i + 1][k] == 'x') {
								for (i2 = 19; i2 >= 0; i2--) {
									for (k2 = 0; k2 < 14; k2++) {
										if (field[i2][k2] == 'o') { field[i2][k2] = 'x'; }
									}
								}
							}
							if (field[i][k] == 'o'&&i != 19 && field[i + 1][k] == ' ') {
								x_checker = 0;
								for (i2 = 19; i2 >= 0; i2--) {
									for (k2 = 0; k2 < 14; k2++) {
										if (field[i2][k2] == 'o'&& field[i2 + 1][k2] == 'x') {
											x_checker = 1;
											i2 = -1;
											k2 = 14;
										}
									}
								}
								if (x_checker == 1) {

									for (i2 = 19; i2 >= 0; i2--) {
										for (k2 = 0; k2 < 14; k2++) {
											if (field[i2][k2] == 'o') { field[i2][k2] = 'x'; }
										}
									}
									x_checker = 0;
								}
								if (x_checker == 0 && k != 19) {
									for (i2 = 19; i2 >= 0; i2--) {
										for (k2 = 0; k2 < 14; k2++) {
											if (field[i2][k2] == 'o') {
												field[i2][k2] = ' ';
												field[i2 + 1][k2] = 'o';
											}
										}
									}
								}
							}
						}
					}

				}


				//figure random
				else {

					srand(time(0));
					f_rand = rand() % 7;
					switch (f_rand) {
					case 0:
						field[0][4] = 'o';
						field[0][5] = 'o';
						field[0][6] = 'o';
						field[0][7] = 'o';

						break;
						//****
						//
					case 1:
						field[0][4] = 'o';
						field[1][4] = 'o';
						field[1][5] = 'o';
						field[1][6] = 'o';

						break;
						//*
						//***
					case 2:
						field[0][4] = 'o';
						field[0][5] = 'o';
						field[0][6] = 'o';
						field[1][4] = 'o';

						break;
						//***
						//*
					case 3:
						field[0][4] = 'o';
						field[0][5] = 'o';
						field[1][4] = 'o';
						field[1][5] = 'o';

						break;
						//**
						//**
					case 4:
						field[0][4] = 'o';
						field[0][5] = 'o';
						field[1][4] = 'o';
						field[1][3] = 'o';

						break;
						// **
						//**
					case 5:
						field[0][4] = 'o';
						field[0][3] = 'o';
						field[1][4] = 'o';
						field[1][5] = 'o';

						break;
						//**
						// **
					case 6:
						field[0][4] = 'o';
						field[1][3] = 'o';
						field[1][4] = 'o';
						field[1][5] = 'o';

						break;
						// *
						//***
					}

				}
			}

		//pushing buttons
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			check_clean = 0;

			for (i = 0; i < 20; i++) {
				for (k = 0; k < 14; k++) {
					if (field[i][k] == 'o' && (field[i][k - 1] == 'x' || k == 0)) {
						check_clean = 1;
					}
				}
			}
			if (check_clean == 0) {
				for (i = 19; i >= 0; i--) {
					for (k = 0; k < 14; k++) {
						if (field[i][k] == 'o') {
							field[i][k] = ' ';
							field[i][k - 1] = 'o';
						}
					}
				}
			}
		}

		if (GetAsyncKeyState(VK_DOWN) != 0) {
			del = 1;
		}

		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			check_clean = 0;

			for (i = 0; i < 20; i++) {
				for (k = 13; k >= 0; k--) {
					if (field[i][k] == 'o' && (field[i][k + 1] == 'x' || k == 13)) {
						check_clean = 1;
					}
				}
			}
			if (check_clean == 0) {
				for (i = 19; i >= 0; i--) {
					for (k = 13; k >= 0; k--) {
						if (field[i][k] == 'o') {
							field[i][k] = ' ';
							field[i][k + 1] = 'o';
						}
					}
				}
			}
		}

		//rolling

		if (GetAsyncKeyState(VK_UP) != 0) {
			//from pos 0 to pos 1
			for (i = 0; i < 20; i++) {
				for (k = 0; k < 14; k++) {
					if (f_rand == 0) {


							if (field[i][k] == 'o'&&field[i][k + 1] == 'o'&&field[i][k + 2] == 'o' &&field[i][k + 3] == 'o' && field[i + 1][k] == ' '&&field[i + 2][k] == ' '&&field[i + 3][k] == ' ')
							{
								field[i][k + 1] = ' ';
								field[i][k + 2] = ' ';
								field[i][k + 3] = ' ';
								field[i + 1][k] = 'o';
								field[i + 2][k] = 'o';
								field[i + 3][k] = 'o';

								Sleep(10);
							}



						/*	if (field[i][k] == 'o'&&field[i + 1][k] == 'o'&&field[i + 2][k] == 'o' &&field[i + 3][k] == 'o' && field[i][k + 1] == ' '&&field[i][k + 2] == ' '&&field[i][k + 3] == ' ')
							{
								field[i + 1][k] = ' ';
								field[i + 2][k] = ' ';
								field[i + 3][k] = ' ';
								field[i][k + 1] = 'o';
								field[i][k + 2] = 'o';
								field[i][k + 3] = 'o';


							}*/
						}
					if (f_rand == 1) {
						if (field[i][k]=='o'&&field[i+1][k] == 'o'&&field[i+1][k+1] == 'o'&&field[i+1][k+2] == 'o'&&field[i][k+1] == ' '&&field[i+2][k] == ' ')
						{

							field[i+1][k+1] = ' ';
							field[i+1][k+2] = ' ';
							field[i][k+1] = 'o';
							field[i+2][k] = 'o';

						}
					}
					if (f_rand == 2){
						if (field[i][k] == 'o'&&field[i][k + 1] == 'o'&&field[i][k + 2] == 'o'&&field[i + 1][k] == 'o'&&field[i + 2][k] == ' '&&field[i][k - 1] == ' ')
						{
							field[i][k + 1] = ' ';
							field[i][k + 2] = ' ';
							field[i + 2][k] = 'o';
							field[i][k - 1] = 'o';
						}
					}
					if (f_rand == 4) {
						if (field[i][k] == 'o'&&field[i-1][k] == 'o'&&field[i][k-1] == 'o'&&field[i-1][k+1] == 'o'&&field[i-1][k-1] == ' '&&field[i+1][k] == ' ') {
							field[i - 1][k - 1] = 'o';
							field[i + 1][k] = 'o';
							field[i - 1][k] = ' ';
							field[i - 1][k + 1] = ' ';

						}
					}
					if (f_rand == 5) {
					if (field[i][k]=='o'&&field[i][k+1] == 'o'&&field[i+1][k+1] == 'o'&&field[i+1][k+2] == 'o'&&field[i-1][k+1] == ' '&&field[i+1][k] == ' ')
					{
						field[i - 1][k + 1] = 'o';
						field[i + 1][k] = 'o';
						field[i+1][k+1] = ' ';
						field[i+1][k+2] = ' ';
					}
					}
					if (f_rand == 6) {
						if (field[i][k]=='o'&&field[i][k-1] == 'o'&&field[i][k+1] == 'o'&&field[i-1][k] == 'o'&&field[i+1][k] == ' ')
						{
							field[i][k - 1] = ' ';
							field[i + 1][k] = 'o';

						}
					}
					}


				}
			}

		if (GetAsyncKeyState(VK_UP) != 0) {
			//from pos 1 to pos 0 (2-pose figures)
			//from pos 1 to pos 2 (4-pose)
			for (i = 0; i < 20; i++) {
				for (k = 0; k < 14; k++) {
					//2-pose
					if (f_rand == 0){
					if (field[i][k]=='o'&&field[i+1][k] == 'o'&&field[i+2][k] == 'o'&&field[i+3][k] == 'o'&&field[i][k+1] == ' '&&field[i][k+2] == ' '&&field[i][k+3] == ' ')
					{
						field[i + 2][k] = ' ';
						field[i + 3][k] = ' ';
						field[i + 1][k] = ' ';
						field[i][k + 1] = 'o';
						field[i][k + 2] = 'o';
						field[i][k + 3] = 'o';
						Sleep(10);
					}
					}
					if (f_rand == 4){
						if (field[i][k] == 'o'&&field[i][k + 1] == 'o'&&field[i + 1][k + 1] == 'o'&&field[i - 1][k] == 'o'&&field[i - 1][k + 1] == ' '&&field[i - 1][k + 2] == ' ')
						{
							field[i - 1][k] = ' ';
							field[i + 1][k + 1] = ' ';
							field[i - 1][k + 1] = 'o';
							field[i - 1][k + 2] = 'o';
						}

					}
					if (f_rand == 5){
					if (field[i][k]=='o'&&field[i][k+1] == 'o'&&field[i-1][k+1] == 'o'&&field[i+1][k] == 'o'&&field[i-1][k] == ' '&&field[i-1][k-1] == ' ')
					{
						field[i - 1][k + 1] = ' ';
						field[i + 1][k] = ' ';
						field[i - 1][k] = 'o';
						field[i - 1][k - 1] = 'o';
					}
					}
					//4-pose
					if (f_rand == 1) {
						if (field[i][k] == 'o'&&field[i][k + 1] == 'o'&&field[i + 1][k] == 'o'&&field[i + 2][k] == 'o'&&field[i][k + 2] == ' '&&field[i + 1][k + 2] == ' ')
						{
							field[i+1][k] = ' ';
							field[i+2][k] = ' ';
							field[i][k+2] = 'o';
							field[i+1][k+2] = 'o';

						}
					}
					if (f_rand == 2) {
					if (field[i][k] == 'o'&&field[i][k+1] == 'o'&&field[i+1][k+1] == 'o'&&field[i+2][k+1] == 'o'&&field[i][k+2] == ' '&&field[i-1][k+2] == ' ')
					{
						field[i + 1][k + 1] = ' ';
						field[i + 2][k + 1] = ' ';
						field[i][k + 2] = 'o';
						field[i - 1][k + 2] = 'o';
					}
					}
					if (f_rand == 6) {
						if (field[i][k] == 'o'&&field[i - 1][k] == 'o'&&field[i + 1][k] == 'o'&&field[i][k + 1] == 'o'&&field[i][k - 1] == ' ') {
							field[i-1][k] = ' ';
							field[i][k - 1] = 'o';

						}
					}
				}
			}
		}
		if (GetAsyncKeyState(VK_UP) != 0) {
			//from pos 2 to pos 3
			for (i = 0; i < 20; i++) {
				for (k = 0; k < 14; k++) {
				if (f_rand == 1) {
					if (field[i][k] == 'o'&&field[i][k - 1] == 'o'&&field[i + 1][k] == 'o'&&field[i][k - 2] == 'o'&&field[i + 2][k] == ' '&&field[i + 2][k - 1] == ' ')
					{
						field[i][k - 1] = ' ';
						field[i][k - 2] = ' ';
						field[i + 2][k] = 'o';
						field[i + 2][k - 1] = 'o';
					}
				}
				if (f_rand == 2) {
					if (field[i][k] == 'o'&&field[i][k+1] == 'o'&&field[i][k-1] == 'o'&&field[i-1][k+1] == 'o'&&field[i-1][k] == ' '&&field[i-2][k] == ' ') {
						field[i][k - 1] = ' ';
						field[i - 1][k + 1] = ' ';
						field[i - 1][k] = ' ';
						field[i - 2][k] = ' ';

					}
				}
				if (f_rand == 6) {
					if (field[i][k] == 'o'&&field[i][k + 1] == 'o'&&field[i][k - 1] == 'o'&&field[i + 1][k] == 'o'&&field[i - 1][k] == ' ') {
						field[i][k + 1] = ' ';
						field[i - 1][k] = 'o';

					}
				}

				}
			}
		}

		if (GetAsyncKeyState(VK_UP) != 0) {
			//from pos 3 back home:3
			for (i = 0; i < 20; i++) {
				for (k = 0; k < 14; k++) {
					if (f_rand == 1) {
						if (field[i][k] == 'o'&&field[i][k + 1] == 'o'&&field[i - 1][k + 1] == 'o'&&field[i - 2][k + 1] == 'o'&&field[i - 1][k] == ' '&&field[i][k + 2] == ' ')
						{
							field[i - 1][k + 1] = ' ';
							field[i - 2][k + 2] = ' ';
							field[i - 1][k] = 'o';
							field[i][k + 1] = 'o';
							field[i][k + 2] = 'o';
						}
					}
					if (f_rand == 2) {
						if (field[i][k] == 'o'&&field[i][k] == 'o'&&field[i - 1][k] == 'o'&&field[i - 2][k] == 'o'&&field[i][k + 1] == 'o'&&field[i - 1][k + 1] == ' '&&field[i - 1][k + 2] == ' ')
						{
							field[i - 2][k] = ' ';
							field[i][k + 1] = ' ';
							field[i - 1][k + 1] = 'o';
							field[i - 1][k + 2] = 'o';
						}
					}
					if (f_rand == 6) {
						if (field[i][k] == 'o'&&field[i][k - 1] == 'o'&&field[i + 1][k] == 'o'&&field[i - 1][k] == 'o'&&field[i][k + 1] == ' ') {
							field[i + 1][k] = ' ';
							field[i][k + 1] = 'o';
						}
					}
				}
			}
		}
			//check filled lines

			for (k = 0; k < 20; k++) {
				if (clf != 0) { clf = 0; }
				for (i = 0; i < 14; i++)
				{
					if (field[k][i] != 'x') { clf = 1; }
				}
				if (clf == 0) {
					score++;
					for (i2 = 0; i2 < 14; i2++) { field[k][i2] = ' '; }
					for (v = k; v >= 0; v--) {
						for (p = 0; p < 14; p++) {
							if (field[v][p] == 'x') {
								field[v][p] = 'o';
								f_rand = 8;
							}
						}
					}

				}
			}




			//drawing field

			for (i = 0; i < 20; i++) {
				for (k = 0; k < 14; k++) {

					cout << field[i][k] << " ";
				}
				cout << rand()%2 << endl;
			}
			cout << "-----------------------------" << endl;
			cout << "score " << score << endl;
			cout << "rand " << f_rand<< endl;
			cout << "high score " << high_score << endl;
			//pause

			Sleep(del);
			del = 200;
			count++;
			spd = 5;
			//check gameover
			if (field[0][4] == 'x') {
				gameover = 1;
				//check score
				ofstream K;
				if (score > high_score) {
					high_score = score;
					F.close();
					K.open("Text.txt", ios::out);
					K << high_score;
					K.close();
				}
			}

		}
	 while (gameover == 0);
		cout << "Game Over" << endl;
		cin.get();
	}

