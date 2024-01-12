#pragma once
#include "Vector2.h"
#include "Player.h"
class Enemy {

private:

	//座標
	Vector2 pos_;
	//移動方向
	float direction_;
	//大きさ
	float radius_;
	//移動速度
	float speed_;

	//生存しているかを表すフラグ(静的メンバ変数)
	static int isAlive;

public:

	//コンストラクタ
	Enemy(Vector2 pos, float speed);
	//デストラクタ
	~Enemy();

	//更新処理
	void Update(Player* player);
	//描画処理
	void Draw();

	//移動処理
	void Move();
	//接触判定処理
	void Collision(Player* player);
};