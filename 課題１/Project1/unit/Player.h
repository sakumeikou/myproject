#pragma once
#include <memory>
#include "Obj.h"
#include "../Input/InputState.h"


class Player :
	public Obj
{
public:
	Player();
	Player(const Vector2& pos);
	~Player();
	void Draw(void) override;
	UNIT GetUnit(void) override;
	void SetMove();
private:
	bool Init(void);
	std::unique_ptr<InputState> inputState;		// 入力状態取得
};

