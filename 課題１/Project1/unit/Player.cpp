#include <DxLib.h>
#include <algorithm>
#include "Player.h"
#include "../common/ImageMng.h"
#include "../_DebugConOut.h"
#include "../_DebugDispOut.h"
#include "../Input/KeyState.h"
#include "../Shot.h"

Player::Player()
{
	Init();
}

Player::Player(const Vector2Dbl& pos, const Vector2Dbl& size)
{
	Init();
	_pos = pos;
	_size = size;

	_angle = 0.0f;
	_shotObj.reserve(2);
	
	//TRACE("%d",_pos.x);
}


Player::~Player()
{
}

void Player::Draw(void)
{
	for (auto &data : _shotObj)
	{
		data->Draw();
	}
	//DrawGraph(static_cast<int>(_pos.x), static_cast<int>(_pos.y), ImageMng::GetInstance().GetID("L")[0], true);
}

UNIT Player::GetUnit(void)
{
	return UNIT::PLAYER;
}

void Player::SetMove(void)
{
	if (DeathProc())
	{
		return;
	}

	/*if (rand() % 10 == 0)
	{
		_alive = false;
		AnimKey(ANIM::DEATH);
	}*/
	Shooting();

	for (auto &data : _shotObj)
	{
		data->SetMove();
	}


	inputState->Update();
	if (inputState->state(INPUT_ID::LEFT).first)
	{
		_pos.x -= 2;
	}
	if (inputState->state(INPUT_ID::RIGHT).first)
	{
		_pos.x += 2;
	}
	if (inputState->state(INPUT_ID::UP).first)
	{
		_pos.y -= 2;
	}
	if (inputState->state(INPUT_ID::DOWN).first)
	{
		_pos.y += 2;
	}

	_DbgDrawFormatString(0, 0, 0xff00ff, "playerPos:%d,%d", _pos.x,_pos.y);
}

std::vector<Shared_Obj> Player::GetShotData()
{
	return _shotObj;
}

bool Player::Init(void)
{
	AnimVector data;

	data.reserve(2);

	// ãLÌpush_backÆ¯¶
	data.emplace_back(IMAGE_ID("L")[0], 30);
	data.emplace_back(IMAGE_ID("L")[1], 60);

	SetAnim(ANIM::NORMAL, data);

	data.reserve(1);
	data.emplace_back(IMAGE_ID("L")[2], 60);
	SetAnim(ANIM::EX,data);

	data.reserve(4);
	data.emplace_back(IMAGE_ID("PLj")[0],  5);
	data.emplace_back(IMAGE_ID("PLj")[1], 15);
	data.emplace_back(IMAGE_ID("PLj")[2], 25);
	data.emplace_back(IMAGE_ID("PLj")[3], 35);
	data.emplace_back(-1, 50);

	SetAnim(ANIM::DEATH, data);

	inputState = std::make_unique<KeyState>();

	return true;
}

bool Player::Shooting(void)
{
	// eÌí
	auto deth_itr = std::remove_if(_shotObj.begin(), _shotObj.end(), [](std::shared_ptr<Obj> obj) {return obj->IsDeath(); });
	_shotObj.erase(deth_itr, _shotObj.end());

	if (inputState->state(INPUT_ID::BTN_1).first)
	{
		if (_shotObj.size() < 2)
		{
			_shotObj.emplace_back(std::make_shared<Shot>(_pos));
		}
	}

	return true;
}
