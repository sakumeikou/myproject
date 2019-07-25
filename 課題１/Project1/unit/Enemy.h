#pragma once
#include <tuple>
#include <vector>
#include<list>
#include <memory>
#include "Obj.h"

enum class ENM_DATA
{
	POS,
	TYPE,
	SIZE,
	TARGTPOS,
	ENEMNUM,
	ENEMCNT,
	MAX
};

enum class ENM_TYPE
{
	A,
	B,
	C,
	MAX
};

enum class MOVE_TYPE
{
	SIGMOID,
	SPIRAL,
	LR,
	MAX
};

using EnemyData = std::tuple<Vector2Dbl, ENM_TYPE, Vector2,Vector2Dbl,int,int>;
using MoveType = std::tuple<Vector2Dbl, MOVE_TYPE>;

class Enemy :
	public Obj
{
public:
	Enemy();
	Enemy(EnemyData& data);
	~Enemy();

	// overrideと書くことによってオーバーライドし忘れによるバグを防止する
	void Draw(void) override;	
	UNIT GetUnit(void) override;
	void SetMove();
private:
	bool Init(void);

	// シグモイド曲線で動く
	void MoveSigmoid(void);		
	// 回転
	void MoveSpiral(void);
	// 最後の目標地点に向かう
	void MoveLastTraget(void);
	// 左右移動
	void MoveLR(void);		
	// 敵の編隊のwait関数
	void MoveWait(void);		

	void (Enemy::*move)(void);	// メンバ関数ポインタ
	ENM_TYPE _type;				// 種類
	Vector2Dbl _targetPos;		// 並ぶ場所
	double speed;
	bool firstFlag;
	int waitCnt;
	int _enemCnt;

	Vector2Dbl _posOld;
	static int animCnt;
	static bool enemGather;
	int enemCounter;
	std::vector<MoveType> moveData;
	Vector2Dbl _vel;
	double step;


	//-----------------
	double X;
	Vector2Dbl debgPos;
	std::list<Vector2Dbl> drawPixel;
	//-----------------
};
