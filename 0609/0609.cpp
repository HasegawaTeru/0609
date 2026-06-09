#include <iostream>
#include <assert.h>

//　武器クラス
class Weapon
{
public:
	//　使う
	void Use() {}
};

//　プレイヤークラス
class Player
{
	//　武器のポインタ（何も持っていない）
	Weapon* weapon = nullptr;
public:
	//　プレイヤークラスのコンストラクタ
	Player(std::shared_ptr<Weapon> weapon)
	{
	}
	//　攻撃する
	void Attack()
	{
		//　武器を持っている状態なら武器を使う
		if(weapon) weapon->Use();
	}
};

int main()
{
	//　武器を作る
	auto weapon = std::make_shared<Weapon>();
	//　プレイヤークラスのコンストラクタに武器を渡す
	Player player(weapon);
	std::cout << weapon.use_count() << std::endl;
}