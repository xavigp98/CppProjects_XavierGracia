#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum class EnemyType { zombie, vampire, ghost, witch};

string nombres[5]{ "Hipolito", "Fulgencia", "Pancracia", "Eustaquio", "Joan" };

struct Enemy {
	EnemyType type;
	string name;
	int health;
};

bool operator==(Enemy uno, Enemy dos) {
	if (uno.name == dos.name && uno.type == dos.type)
		return true;
	else
		return false;
}

Enemy CreateRandomEnemy() {
	Enemy enemigo;
	enemigo.type;
	enemigo.name;
	enemigo.health;

	

	int a = rand() % 4;

	switch (a)
	{
	case (0):
		enemigo.type = EnemyType::zombie;
		break;
	case(1):
		enemigo.type = EnemyType::vampire;
		break;
	case(2):
		enemigo.type = EnemyType::ghost;
		break;
	case(3):
		enemigo.type = EnemyType::witch;
		break;
	default:
		break;
	}

	int b = rand() % 5;

	enemigo.name = nombres[b];

	enemigo.health = rand() % 100;

	return enemigo;
}


int main() {

	srand(time(NULL));
	Enemy arr[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = CreateRandomEnemy();
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i] == arr[j]) {
				arr[j].type = (EnemyType)((((int)arr[j].type + 1) % 4));
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << "Nombre: " << arr[i].name << ". Tipo: ";

		switch (arr[i].type)
		{
		case(EnemyType::zombie):
			cout << "zombie" << endl;
			break;
		case(EnemyType::vampire):
			cout << "vampire" << endl;
			break;
		case(EnemyType::ghost):
			cout << "ghost" << endl;
			break;
		case(EnemyType::witch):
			cout << "witch" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}