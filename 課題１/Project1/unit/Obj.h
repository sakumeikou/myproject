#pragma once
#include <memory>
#include <vector>
#include <map>
#include "../common/Vector2.h"

enum class ANIM	// アニメーションタイプ
{
	NORMAL,		// 通常
	EX,			// 特殊
	DEATH,		// 爆破
	MAX
};

enum class UNIT
{
	PLAYER,		// プレイヤーユニット
	ENEMY,		// 敵
	MAX
};

class Obj;
using Shared_Obj = std::shared_ptr<Obj>;
using AnimVector = std::vector<std::pair<int, int>>;	// 


class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Draw(void);
	void Draw(int id);
	virtual UNIT GetUnit(void) = 0;
	virtual void SetMove();

	// _animkeyを取得
	const ANIM AnimKey()const;		

	// _animKeyにアニメーションタイプをセットする
	bool AnimKey(const ANIM animkey);	

	// pos情報取得
	const Vector2 Pos()const;

	bool IsAnimEnd();
	bool Active();

	// posセット
	void Pos(const Vector2 &pos);

	// 生存確認
	const bool IsAlive() { return _alive; };
	const bool IsDeath() { return _death; };
protected:

	// アニメーション情報をセットする
	bool SetAnim(const ANIM key, AnimVector &data);	
	Vector2 _pos;		// 座標
	Vector2 _size;		// キャラの大きさ
	bool _alive;		// 生きているか	true...生存　false...死亡
	bool _death;	
	float _angle;
	int _animCnt;		// アニメーションカウンター
private:
	ANIM _animKey;		// アニメーションタイプ
	int _animFram;		// アニメーションのフレーム数
	
	


	std::map<ANIM, const AnimVector> _animMap;		// アニメーション情報を格納しているmap
};

