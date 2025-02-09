#pragma once
#include <memory>

// ｼｰﾝ用ID
// ｸﾗｽ名で何かわかるようにし変数名は短めにする
enum class SCN_ID
{
	TITLE,	// 
	GAME,	// ｹﾞｰﾑｼｰﾝ
	MAX
};

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
class BaseScene;

// using宣言
using shared_Base = std::shared_ptr<BaseScene>;			// ｼｪｱｰﾄﾞﾎﾟｲﾝﾀｰ

class BaseScene
{
public:
	BaseScene() {};
	virtual ~BaseScene() {};

	virtual shared_Base UpDate(shared_Base own) = 0;	// 状態遷移
	virtual SCN_ID GetScnID(void) = 0;					// 自分のｼｰﾝのIDを返す(純粋仮想関数)
};

