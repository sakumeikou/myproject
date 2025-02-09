#pragma once
#include <memory>
#include "Obj.h"
#include "../Input/InputState.h"


class Player :
	public Obj
{
public:
	Player();
	Player(const Vector2Dbl& pos, const Vector2Dbl& size);
	~Player();
	void Draw(void) override;
	UNIT GetUnit(void) override;
	void SetMove(void);
	std::vector<Shared_Obj> GetShotData() override;
private:
	bool Init(void);

	// 自機弾の生成と削除処理
	bool Shooting(void);

	std::unique_ptr<InputState> inputState;		// 入力状態取得
	std::vector<Shared_Obj> _shotObj;
};
