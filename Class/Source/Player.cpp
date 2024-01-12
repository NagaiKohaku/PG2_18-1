#include "./Class/Hedder/Player.h"
#include <Novice.h>

//コンストラクタ
Player::Player() {

	//座標
	pos_ = { 640.0f,500.0f };
	//大きさ
	radius_ = 30.0f;
	//移動速度
	speed_ = 5.0f;

	for (int i = 0; i < 30; i++) {
		//弾のインスタンスを作成
		bullet_[i] = new Bullet();
	}

	//弾発射のクールタイム
	coolTime_ = 0;
	//弾発射の間隔
	coolDown_ = 10;
}

//デストラクタ
Player::~Player() {

	for (int i = 0; i < 30; i++) {

		//メモリ開放
		delete bullet_[i];
	}
}

//更新処理
void Player::Update(char keys[]) {

	//移動処理
	Move(keys);
	//弾発射処理
	Shoot(keys);

	//弾の更新処理
	for (int i = 0; i < 30; i++) {
		if (bullet_[i]->GetFlag()) {
			bullet_[i]->Update();
		}
	}

	//描画処理
	Draw();

	//弾の描画処理
	for (int i = 0; i < 30; i++) {
		if (bullet_[i]->GetFlag()) {
			bullet_[i]->Draw();
		}
	}

}

//描画処理
void Player::Draw() {
	
	//緑色の円で描画
	Novice::DrawEllipse(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		GREEN,
		kFillModeSolid
	);
}

//移動処理
void Player::Move(char keys[]) {

	//各キーが押されたら応じた方向に移動する
	//Wキーが押されたら上方向に移動する
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}

	//Sキーが押されたら下方向に移動する
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}

	//Aキーが押されたら左方向に移動する
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}

	//Dキーが押されたら右方向に移動する
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}
}

//弾発射処理
void Player::Shoot(char keys[]) {

	//クールタイムのインクリメント
	coolTime_++;

	if (keys[DIK_SPACE]) {

		//クールダウンを終えていないと弾を撃てない
		if (coolTime_ >= coolDown_) {

			for (int i = 0; i < 30; i++) {

				//弾が発射されていなかったらフラグと座標を設定する
				if (!bullet_[i]->GetFlag()) {

					//フラグをtrueにする
					bullet_[i]->SetFlag(true);
					//座標をプレイヤーの中心座標に設定する
					bullet_[i]->SetPos(pos_);

					//クールタイムをリセットする
					coolTime_ = 0;

					return;
				}
			}
		}
	}
}

//弾の座標のゲッター
Vector2 Player::GetBulletPos(int num) {
	return bullet_[num]->GetPos();
}

//弾の大きさのゲッター
float Player::GetBulletRadius() {
	return bullet_[0]->GetRadius();
}

//弾のフラグのゲッター
bool Player::GetBulletFlag(int num) {
	return bullet_[num]->GetFlag();
}