#include <DxLib.h>
#include "SceneMng.h"
#include "unit/Enemy.h"
#include "unit/Player.h"
#include "_DebugConOut.h"
#include "common/ImageMng.h"
#include "Scene/GameScene.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

void SceneMng::Run(void)
{
	

	
	ImageMng::GetInstance().GetID("キャラ", "image/char.png", { 10,10 }, { 30,30 });

	_DebugConOut::GetInstance();

	_activeScene = std::make_unique<GameScene>();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();
		_activeScene = _activeScene->UpDate(std::move(_activeScene));
		ScreenFlip();
	}

}

bool SceneMng::Init(void)
{
	SetGraphMode(800, 600, 16);		// 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);				// true:window　false:ﾌﾙｽｸﾘｰﾝ
	SetWindowText("ギャラガ");
	if (DxLib_Init() == -1) return false;	// DXﾗｲﾌﾞﾗﾘ初期化処理
	TRASCE("DXLIB初期化完了\n");
	SetDrawScreen(DX_SCREEN_BACK);		// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	return false;
}

SceneMng::SceneMng()
{
	Init();
}


SceneMng::~SceneMng()
{
}
