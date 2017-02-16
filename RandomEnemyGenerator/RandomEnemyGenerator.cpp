#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum EnemyType { zombie, vampire, ghost, witch };

string nombres[5] = { "joan", "xaviO", "xaviG", "loko", "lamierda" };

struct Enemy {
	EnemyType type;
	string name;
	int health;
};

Enemy CreateRandomEnemy() {
	Enemy enemigo;
	enemigo.type;
	enemigo.name;
	enemigo.health;

	int a = rand() % 4;

	switch (a)
	{
	case (0):
		enemigo.type = zombie;
	case(1):
		enemigo.type = vampire;
	case(2):
		enemigo.type = ghost;
	case(3):
		enemigo.type = witch;
	case(4):
		enemigo.type = witch;
	default:
		break;
	}


}


int main() {

	srand(time(NULL));
	Enemy arr[5];
	return 0;
}