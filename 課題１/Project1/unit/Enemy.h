#pragma once
#include <tuple>
#include "Obj.h"

enum class ENM_DATA
{
	POS,
	TYPE,
	SIZE,
	TARGTPOS
};

enum class ENM_TYPE
{
	A,
	B,
	C
};

using EnemyData = std::tuple<Vector2Dbl, ENM_TYPE, Vector2,Vector2Dbl>;

class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(EnemyData data);
	~Enemy();

	// overrideと書くことによってオーバーライドし忘れによるバグを防止する
	void Draw(void) override;	
	UNIT GetUnit(void) override;
	void SetMove();
private:
	bool Init(void);
	ENM_TYPE _type;				// 敵の種類
	Vector2Dbl _targetPos;			// 敵が並ぶ場所
	Vector2Dbl _firstTarget;		// 敵が最初に向かう場所
	int speed;
	bool firstFlag;
	int waitCnt;
	Vector2Dbl _posOld;
	static int animCnt;
	//-----------------
	float _floatPosX;
	float _floatPosY;
	//-----------------
};
