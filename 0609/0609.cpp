#include <iostream>
#include <assert.h>

class Weapon
{
public:
	void Use() {}
};

class Player
{
	Weapon* weapon = nullptr;
public:
	Player(std::shared_ptr<Weapon> weapon)
	{
	}
	
	void Attack()
	{
		assert(weapon != nullptr);
		weapon->Use();
	}
};

int main()
{
	auto weapon = std::make_shared<Weapon>();
	Player player(weapon);
	std::cout << weapon.use_count() << std::endl;
}