#include <iostream>
#include <assert.h>

class Weapon
{
public:
	void Use() {}
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
	auto a = std::make_shared<Player>(std::make_shared<Weapon>());

	std::cout << "a: " << a.use_count() << std::endl;

	auto b = a;

	std::cout << "a: " << a.use_count() << std::endl;
	std::cout << "b: " << b.use_count() << std::endl;

	auto c = std::move(a);

	std::cout << "a: " << a.use_count() << std::endl;
	std::cout << "b: " << b.use_count() << std::endl;
	std::cout << "c: " << c.use_count() << std::endl;

	assert(a != nullptr);
	a->Attack();
}