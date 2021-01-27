#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
	int z;
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


	void Display(int raw) {				// raw - z
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				cout << a[x][y][raw] << " ";
			}
			cout << endl;
		}
	}


	char& GetPos(int x, int y, int z) {
		char* point = new char;
		point = &a[x][y][z];
		return a[x][y][z];
	}


	char& GetPos(Point point) {
		return GetPos(point.x, point.y, point.z);
	}


	~World() {
		delete[] a;
	}

};

int main()
{
	World world; World world2(7);

	world.CreateWorld(50);
	world.GetPos(2, 2, 1) = 81;
	world.Display(1);
	while (true);
}
