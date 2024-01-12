#include "./Class/Hedder/Bullet.h"
#include <Novice.h>

//コンストラクタ
Bullet::Bullet() {

	//座標
	pos_ = { 0.0f,0.0f };
	//大きさ
	radius_ = 20.0f;
	//移動速度
	speed_ = 10.0f;
	//発射されているかを表すフラグ
	isShoot_ = false;
}

//デストラクタ
Bullet::~Bullet() {
}

//更新処理
void Bullet::Update() {

	//移動処理
	Move();
}

//描画処理
void Bullet::Draw() {

	if (isShoot_) {

		//白色の円で描画
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			WHITE,
			kFillModeSolid
		);
	}
}

//移動処理
void Bullet::Move() {

	//上方向に移動させる
	pos_.y -= speed_;

	//画面外に出たらフラグをfalseにする
	if (pos_.y <= 0.0f - radius_) {

		isShoot_ = false;
	}
}

//座標のセッター
void Bullet::SetFlag(bool flag) {
	isShoot_ = flag;
}

//フラグのセッター
void Bullet::SetPos(Vector2 pos) {
	pos_ = pos;
}

//座標のゲッター
bool Bullet::GetFlag() {
	return isShoot_;
}

//大きさのゲッター
float Bullet::GetRadius() {
	return radius_;
}

//フラグのゲッター
Vector2 Bullet::GetPos() {
	return pos_;
}