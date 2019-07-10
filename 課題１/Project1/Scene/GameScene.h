#pragma once
#include <vector>
#include "BaseScene.h"
#include "../unit/Obj.h"

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	Unique_Base UpDate(Unique_Base own) override;
	SCN_ID GetScnID(void) override;		// 自身のシーンの種類を返す
	void Draw(void);
protected:
	void Init(void)override;
private:
	std::vector<Shared_Obj> _objList;
	int _ghGameScreen;
};

