//==============================================================
//
//タイトルヘッダー[title.h]
//Author:佐久間優香
//
//==============================================================
#ifndef _MAP_H_						//このマクロが定義されていなかったら
#define _MAP_H_						//2重インクルード防止のマクロを定義する

#include <stdio.h>
#include "main.h"
#include "object.h"

//前方宣言

//==============================================================
//タイトルクラス
//==============================================================
class CMap
{
	enum STAGE
	{
		STAGE_00 = 0,
		STAGE_01,
		STAGE_02,
		STAGE_03,
		STAGE_04,
		STAGE_05,
		STAGE_MAX
	};

public:

	CMap();								//コンストラクタ
	~CMap();								//デストラクタ

	static CMap *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Set(void);
	
private:

	void ObjectSet(FILE *pFile);
};
#endif // !_PLAYER_H_


