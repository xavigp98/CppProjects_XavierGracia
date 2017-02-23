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
	Player::Player() : weapon { (Weapon)(rand() % (int)Weapon::MAX) }, precision { (rand() / 1.f) }, life{ rand() % 100 }{	
			
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
	Zombie::Zombie() :distanceToPlayer{ 20 + (rand() % 180) }, speed{ (rand() / 20.f) }, damage{ (rand() / 21.f) }, life{ rand() % 100 }
	{
		
	}

	void attack(Player &b) {
		if (distanceToPlayer <= 0) {
			b.life = b.life - damage;
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
	a.life -= static_cast<float>(Player::weapon) * Player::precision;
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
		case Weapon::FISTS:	std::cout << "Fists";
		case Weapon::GUN:	std::cout << "Gun";
		case Weapon::MACHINE_GUN:	std::cout << "Machine Gun";
		case Weapon::REVOLVER:	std::cout << "Revolver";
		case Weapon::SHOTGUN:	std::cout << "Shotgun";
		case Weapon::SNIPER:	std::cout << "Sniper";
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
		if (zombiesAreAlive)
			std::cout << "Los zombies siguen vivos" << std::endl;
		else
			std::cout << "Game Over: has matado a todos los zombies" << std::endl;
	} while (player.isAlive() == true && zombiesAreAlive);

	return 0;
}