#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Queue.h"

using namespace std;

int main() {
	srand(time(NULL));

	Queue QU1(10);
	Queue QU2(10);
	Queue QU3(10);
	Queue QU4(10);
	Queue QU5(10);
	
	for(int i = 0; i < 2; i++)
		for (int i = 0; i < 5; i++) 
			QU1.Add(i);
	for (int i = 0; i < 2; i++)
		for (int i = 0; i < 5; i++)
			QU2.Add((i * 3) % 5);
	for (int i = 0; i < 2; i++)
		for (int i = 0; i < 5; i++)
			QU3.Add((i * 2) % 5);
	for (int i = 0; i < 2; i++)
		for (int i = 0; i < 5; i++)
			QU4.Add((i * 4) % 5);
	for (int i = 0; i < 2; i++)
		for (int i = 0; i < 5; i++)
			QU5.Add((i * 7)  % 5);

	while (true) {
		int arr[3][5];
		cout << "\n\n\tPRESS SPACE TO CONTINUE";
		while (true) {

			if (GetKeyState(VK_SPACE) & 0x8000) {
				while (GetKeyState(VK_SPACE) & 0x8000);
				system("cls");
				for (int i = 0; i = (rand() + 10) % 25; i++)
					QU1.Extract();
				for (int i = 0; i = (rand() + 10) % 25; i++)
					QU2.Extract();
				for (int i = 0; i = (rand() + 10) % 25; i++)
					QU3.Extract();
				for (int i = 0; i = (rand() + 10) % 25; i++)
					QU4.Extract();
				for (int i = 0; i = (rand() + 10) % 25; i++)
					QU5.Extract();
				for (int i = 0; i < 3; i++) {
					arr[i][0] = QU1.GetNum();
					arr[i][1] = QU2.GetNum();
					arr[i][2] = QU3.GetNum();
					arr[i][3] = QU4.GetNum();
					arr[i][4] = QU5.GetNum();
				}
				cout << "\n\t#####################";
				cout << "\n\t" << "# "  << arr[0][0] << " # " << arr[0][1] << " # " << arr[0][2] << " # " << arr[0][3] << " # " << arr[0][4] << " # ";
				cout << "\n\t" << "# " << arr[1][0] << " # " << arr[1][1] << " # " << arr[1][2] << " # " << arr[1][3] << " # " << arr[1][4] << " # ";
				cout << "\n\t" << "# " << arr[2][0] << " # " << arr[2][1] << " # " << arr[2][2] << " # " << arr[2][3] << " # " << arr[2][4] << " # ";
				cout << "\n\t#####################";
				break;
			}
		}
	}
	return 0;
}