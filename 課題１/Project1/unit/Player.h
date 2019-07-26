#pragma once
#include <memory>
#include "Obj.h"
#include "../Input/InputState.h"


class Player :
	public Obj
{
public:
	Player();
	Player(const Vector2Dbl& pos, const Vector2& size);
	~Player();
	void Draw(void) override;
	UNIT GetUnit(void) override;
	void SetMove(void);
private:
	bool Init(void);
	bool IsShot(void);
	std::unique_ptr<InputState> inputState;		// 入力状態取得
};

