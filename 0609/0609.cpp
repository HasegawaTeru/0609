#include <iostream>
#include <assert.h>

class Weapon
{
public:
	void Use() {}
};

class Sword : public Weapon
{
};

class Player
{
	std::shared_ptr<Weapon> weapon;
public:
	Player(std::shared_ptr<Weapon> weapon1) : weapon(weapon1)
	{
	}
	void Attack()
	{
		weapon->Use();
	}
};

int main()
{
	auto sword = std::make_shared<Sword>();

	std::cout << sword.use_count() << std::endl;
	//　所有権を渡す
	Player p1(std::move(sword));

	std::cout << sword.use_count() << std::endl;
}