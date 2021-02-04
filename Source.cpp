#include <iostream>
#include <conio.h>

using namespace std;

#ifdef _WIN32
#include <Windows.h>
#endif



void clearScreen() {
#ifdef _WIN32
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
#endif
#ifndef _WIN32
	cout << "\033[2J\033[1;1H";
#endif
}


struct Vector3D {
	int x;
	int y;
	int z;
};


struct Vector2D {
	int x;
	int y;
};


class World {
private:
	char*** a;
	short size;
public:
	World(short n) {
		CreateWorld(n);
	}

	World() {
		NULL;
	}


	void CreateWorld(short n) {
		size = n;
		a = new char** [n];
		for (int x = 0; x < n; x++) {
			a[x] = new char* [n];
			for (int y = 0; y < n; y++) {
				a[x][y] = new char[n];
				for (int z = 0; z < n; z++) {
					a[x][y][z] = 48;
				}
			}
		}
	}


	void Display (int raw) {				// raw - z
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				cout << a[x][y][raw] << " ";
			}
			cout << endl;
		}
	}


	char& GetPos (int x, int y, int z) {
		return a[x][y][z];
	}


	char& GetPos (Vector3D point) {
		return GetPos(point.x, point.y, point.z);
	}


	~World() {
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				delete[] a[x][y];
			}
			delete[] a[x];
		}
		delete[] a;
	}

};


int main()
{
	World world; World world2(7);

	world.CreateWorld(50);
	world.GetPos(2, 2, 1) = 70;
	world.Display(1);

	auto extended = _getch();
	if (extended == 48) {
		clearScreen();
	}
	while (true);
}
