#include <DxLib.h>
#include "SceneMng.h"
#include "unit/Enemy.h"
#include "unit/Player.h"
#include "_DebugConOut.h"
#include "common/ImageMng.h"
#include "Scene/GameScene.h"
#include "_DebugDispOut.h"

std::unique_ptr<SceneMng, SceneMng::SceneMngDeleter> SceneMng::s_Instance(new SceneMng);

SceneMng::SceneMng() :screenSize{ 800,600 }, gameScreenSize{ 500,390 }, gameScreenPos{ (800 - 500) / 2,(600 - 390) / 2 }
{

}


SceneMng::~SceneMng()
{
}

void SceneMng::Run(void)
{
	Init();
	
	ImageMng::GetInstance().GetID("キャラ", "image/char.png", { 10,10 }, { 30,32 });
	ImageMng::GetInstance().GetID("爆破", "image/en_blast.png", { 5,1 }, { 64,64 });
	ImageMng::GetInstance().GetID("PL爆破", "image/pl_blast.png", { 4,1 }, { 64,64 });
	ImageMng::GetInstance().GetID("ショット", "image/shot.png", { 2,1 }, { 3,8 });

	_DebugConOut::GetInstance();

	_activeScene = std::make_unique<GameScene>();
	
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//WaitTimer(240);
		_DbgStartDraw;
		drawList.clear();
		_activeScene = _activeScene->UpDate(std::move(_activeScene));
		AddDrawQue({ IMAGE_ID("枠")[0],0,0 });
		Draw();
		frame++;
	}

}

bool SceneMng::AddDrawQue(DrawQueT dQue)
{
	if (std::get<static_cast<int>(DRAW_QUE::IMAGE)>(dQue) == -1)	// std::get<0>(dQue)と書くことによってtupleの0番目の要素を見ることができる
	{
		return false;
	}
	drawList.emplace_back(dQue);
	return true;
}


bool SceneMng::Init(void)
{
	SetGraphMode(screenSize.x, screenSize.y, 16);		// 65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);				// true:window　false:ﾌﾙｽｸﾘｰﾝ
	SetWindowText("ギャラガ");
	if (DxLib_Init() == -1) return false;	// DXﾗｲﾌﾞﾗﾘ初期化処理
	TRACE("DXLIB初期化完了\n");
	SetDrawScreen(DX_SCREEN_BACK);		// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	SET_IMAGE_ID("枠", "image/frame.png");
	_DbgSetUp(200);
	frame = 0;
	return true;
}

void SceneMng::Draw(void)
{
	_DbgAddDraw;
	auto debug = GetDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);		// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
	debug = GetDrawScreen();
	ClsDrawScreen();
	
	for (auto _dQue : drawList)
	{
		DrawGraph(std::get<static_cast<int>(DRAW_QUE::X)>(_dQue),
				  std::get<static_cast<int>(DRAW_QUE::Y)>(_dQue),
				  std::get<static_cast<int>(DRAW_QUE::IMAGE)>(_dQue), true);
	}
	
	ScreenFlip();
	
}


