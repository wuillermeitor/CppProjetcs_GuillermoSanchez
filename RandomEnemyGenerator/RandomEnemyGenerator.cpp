#include <iostream>
#include <string>
#include <ctime>

enum class EnemyType {
	ZOMBIE,
	VAMPIRE,
	GHOST,
	WITCH,
	MAX
};

struct Enemy {
	EnemyType type;
	std::string name;
	int health;
	
	std::string getEnemyTypeString() {
		switch (type) {
		case EnemyType::ZOMBIE: return "zombie";
		case EnemyType::VAMPIRE: return "vampire";
		case EnemyType::GHOST: return "ghost";
		case EnemyType::WITCH: return "witch";
		default: return " ";
		}
	}
};

bool operator == (const Enemy &a, const Enemy &b) {
	return a.name == b.name && a.type == b.type;
}

static Enemy CreateRAndomEnemy() {
	static const int MAX_LIFE{ 500 };
	static const std::string NAMES[]{
		"Gertrudis",
		"Pancracia",
		"Anacleto",
		"Hipolito",
		"Eustaquio",
		"Fulgencia"
	};

	return Enemy{
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX)),
		NAMES[rand() % (sizeof NAMES / sizeof std::string)],
		rand() % MAX_LIFE
	};
}

int main() {
	srand(static_cast<unsigned>(time(nullptr)));
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];
}