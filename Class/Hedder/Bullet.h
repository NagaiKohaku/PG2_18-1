#pragma once
#include "Vector2.h"

class Bullet {

private:

	//座標
	Vector2 pos_;
	//大きさ
	float radius_;
	//移動速度
	float speed_;
	//発射されているかを表すフラグ
	bool isShoot_;

public:

	//コンストラクタ
	Bullet();
	//デストラクタ
	~Bullet();

	//更新処理
	void Update();
	//描画処理
	void Draw();

	//移動処理
	void Move();

	//座標のセッター
	void SetPos(Vector2 pos);
	//フラグのセッター
	void SetFlag(bool flag);

	//座標のゲッター
	Vector2 GetPos();
	//大きさのゲッター
	float GetRadius();
	//フラグのゲッター
	bool GetFlag();
};