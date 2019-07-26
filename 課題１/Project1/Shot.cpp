#include "Shot.h"
#include "common/ImageMng.h"
#include "_DebugDispOut.h"
#include "_DebugConOut.h"


Shot::Shot()
{
}

Shot::Shot(Vector2Dbl& pos)
{
	_pos = pos;
	Init();
}


Shot::~Shot()
{
}


void Shot::Init(void)
{
	AnimVector data;

	data.reserve(1);
	data.emplace_back(IMAGE_ID("�V���b�g")[0], 120);
	SetAnim(ANIM::NORMAL, data);
}

void Shot::SetMove()
{

	TRACE("%d\n",_pos.x);
	

	if (_pos.y + _size.y / 2 < 0)
	{
		_death = true;
	}

	_pos.y -= 3.0;
}

UNIT Shot::GetUnit(void)
{
	return UNIT::SHOT;
}