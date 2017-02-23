#include <iostream>
#include <string>
#include <ctime>



enum class EnemyType { zombie, vampire, ghost, witch, max}; //Fuertemente tipado

struct Enemy {
	EnemyType type;
	std::string name; //siempre que usemos cout, cin, string mejor usar std:: que poner el using namespace std; al principio
	int health;
	int max; // se utiliza para saber la medida de la struct... empieza por cero

	std::string getEnemyTypeStrig() {
		switch (type)
		{
		case EnemyType::zombie: return "zombie"; //para tilizar valores de tipo enum class hemos de especificar el enum del que vienen con por ejemplo EnmeyT
		case EnemyType::vampire: return "vampire";
		case EnemyType::ghost: return "ghost";
		case EnemyType::witch: return "witch";
		default: return "";
		}
	}
};

bool operator==(const Enemy &a, const Enemy &b) { //los usamos por referencia pero con const para usar directamente ssu valor sin crear una copia dentro de la fncion pero ponemos el const para decir claramente que no lo modificaremos
	return a.name == b.name && a.type == b.type; //Si los dos enemy tienen el mismo nombre y el mismo tipo, el operator == devuelve true
}

Enemy CreateRandomEnemy() {
	static const int MAX_LIFE{ 500 }; // Vida maxima
	static const std::string NAMES[]{ //Lista de nombres posibles para cada enemigo , no hacia falta hacerlo en una array al principio. Con hacerlo dentro de la funcion ya me vale
		"Hipolito", "Marcel", "Pancracia", "XaviO", "Joan"

	};
	Enemy enemigo;
	enemigo.type;
	enemigo.name;
	enemigo.health;

	

	return Enemy{ //devolvemos una struct de manera mas elegante. Separados por coma estan los valores de cada elemento interno del struct
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::max)),
		NAMES[rand() % (sizeof NAMES / sizeof std::string)], //para saber cual es el numero maximo de strings que tengo, divido el tamaño de toda la array de strings entre el tamaño de una string
		rand() % MAX_LIFE
	};
}

int main() {

	srand(time(nullptr));
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];

	{
		int i{ 0 };
		while (i < MAX_ENEMIES) {
			enemies[i] = CreateRandomEnemy();
			int j{ i - 1 };
			while (j >= 0) {
				if (enemies[i] == enemies[j]) {
					--i;
					break;
				};
				j--;
			};
			++i;
		}
	}

	//Print the array of enemies 
	std::cout << "List of enemies:\n";
	for (auto &enemy : enemies) {
		std::cout << enemy.name <<
			" is a " << enemy.getEnemyTypeStrig() <<
			" whose life is " << enemy.health << std::endl;
	}

	return 0;
	
}