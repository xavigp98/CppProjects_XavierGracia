#include <iostream>
#include <string>
#include <ctime>

class Zombie;

enum class Weapon {FISTS,GUN,SHOTGUN,REVOLVER,SNIPER,MACHINE_GUN,MAX};



class Player {
public:

	float precision;
	int life;
	Weapon weapon;
	Player::Player() : weapon { static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX) )}, precision { 0.f+((static_cast<float>(rand() % 10)/10)) }, life{ rand() % 100 }{	
			
	}

	bool isAlive() {
		return life > 0;
	}
	void attack(Zombie &a);
};

class Zombie {
public:
	int distanceToPlayer;
	float speed;
	float damage;
	int life;
	Zombie::Zombie() :distanceToPlayer{ 20 + (rand() % 180) }, speed{ static_cast<float>(rand() % 20) + ((static_cast<float>(rand() % 10) / 10)) }, damage{ static_cast<float>(rand() % 20) + ((static_cast<float>(rand() % 10) / 10)) }, life{ rand() % 100 }
	{
		
	}

	void attack(Player &b) {
		if (distanceToPlayer <= 0) {
			b.life -= damage;
		}
		else {
			distanceToPlayer = distanceToPlayer - 1;
		}
	}

	bool isAlive() {
		return life > 0;
	}
};
void Player::attack(Zombie &a) {
	a.life = a.life - static_cast<int>(Player::weapon) * Player::precision;
}



int main() {
	const int NUMERO_ZOMBIES = 10;
	srand(time(nullptr));
	Player player;
	Zombie zombies[NUMERO_ZOMBIES];
	bool zombiesAreAlive;

	do
	{
		zombiesAreAlive = false;
		std::cout << "Player\n" << "		life: " << player.life << ", weapon: ";
		switch (player.weapon) {
		case Weapon::FISTS:	std::cout << "Fists";break;
		case Weapon::GUN:	std::cout << "Gun";break;
		case Weapon::MACHINE_GUN:	std::cout << "Machine Gun";break;
		case Weapon::REVOLVER:	std::cout << "Revolver";break;
		case Weapon::SHOTGUN:	std::cout << "Shotgun";break;
		case Weapon::SNIPER:	std::cout << "Sniper";break;
		}
		std::cout << ", precision: " << player.precision << std::endl;
		for (int i = 0; i < 10; i++) {
			if (zombies[i].isAlive() == true) {
				zombiesAreAlive = true;
				player.attack(zombies[i]);
				zombies[i].attack(player);
				std::cout << "Zombie[" << i << "]" << std::endl << "		life: " << zombies[i].life << ", distance: " << zombies[i].distanceToPlayer << ", speed: " << zombies[i].speed << ", damage: " << zombies[i].damage << std::endl;
			}
		}

		std::cout << std::endl << std::endl;
		
	} while (player.isAlive() == true && zombiesAreAlive);

	if (zombiesAreAlive)
		std::cout << "Los zombies han ganado" << std::endl << std::endl;
	else
		std::cout << "Game Over: has matado a todos los zombies" << std::endl << std::endl;

	return 0;
}
