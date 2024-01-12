#include "./Class/Hedder/Enemy.h"
#include <Novice.h>
#include <math.h>

//静的メンバ変数の宣言
int Enemy::isAlive;

//コンストラクタ
Enemy::Enemy(Vector2 pos, float speed) {

	//座標
	pos_ = pos;
	//移動方向
	direction_ = 1.0f;
	//大きさ
	radius_ = 30.0f;
	//移動速度
	speed_ = speed;

	//生存しているかを表すフラグ(静的メンバ変数)
	isAlive = true;
}

//デストラクタ
Enemy::~Enemy() {
}

//更新処理
void Enemy::Update(Player* player) {

	if (isAlive) {

		//移動処理
		Move();

		//接触判定処理
		Collision(player);

		//描画処理
		Draw();
	}
}

//描画処理
void Enemy::Draw() {

	//赤色の円で描画
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		RED,
		kFillModeSolid
	);
}

//移動処理
void Enemy::Move() {

	//X軸方向に移動する
	pos_.x += speed_ * direction_;

	//左右の画面縁に接したら移動方向を反転させる
	if (pos_.x >= 1280.0f - radius_ || pos_.x <= 0.0f + radius_) {
		direction_ *= -1.0f;
	}
}

//接触判定処理
void Enemy::Collision(Player* player) {

	for (int i = 0; i < 30; i++) {

		//発射フラグがtrueになっている弾のみ接触判定をとる
		if (player->GetBulletFlag(i)) {

			//弾とエネミーの距離の計算
			float x = player->GetBulletPos(i).x - pos_.x;
			float y = player->GetBulletPos(i).y - pos_.y;
			float distance = sqrtf(x * x + y * y);

			//弾とエネミーが接していたらエネミーのフラグをfalseにする
			if (distance <= player->GetBulletRadius() + radius_) {
				isAlive = false;
			}
		}
	}
}