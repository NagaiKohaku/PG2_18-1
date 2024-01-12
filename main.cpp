#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

const char kWindowTitle[] = "LC1B_16_ナガイ_コハク_PG2_18-1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//プレイヤーのインスタンス作成
	Player* player = new Player();
	
	//エネミーのインスタンス作成
	Enemy* enemy1 = new Enemy({ 640.0f,360.0f }, 5.0f);
	Enemy* enemy2 = new Enemy({ 540.0f,260.0f }, 6.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//プレイヤーの更新処理
		player->Update(keys);

		//エネミーの更新処理
		enemy1->Update(player);
		enemy2->Update(player);

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	//メモリの開放
	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
