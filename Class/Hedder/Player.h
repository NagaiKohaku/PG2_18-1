#pragma once
#include "Vector2.h"
#include "./Class/Hedder/Bullet.h"

class Player {

private:

	//座標
	Vector2 pos_;
	//大きさ
	float radius_;
	//移動速度
	float speed_;
	//弾
	Bullet* bullet_[30];
	//弾発射のクールタイム
	int coolTime_;
	//弾発射の間隔
	int coolDown_;

public:

	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//更新処理
	void Update(char keys[]);
	//描画処理
	void Draw();

	//移動処理
	void Move(char keys[]);
	//弾発射処理
	void Shoot(char keys[]);

	//弾の座標のゲッター
	Vector2 GetBulletPos(int num);
	//弾の大きさのゲッター
	float GetBulletRadius();
	//弾のフラグのゲッター
	bool GetBulletFlag(int num);
};