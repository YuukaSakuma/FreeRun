//==============================================================
//
//爆発処理[explosion.cpp]
//Author:佐久間優香
//
//==============================================================
#include"renderer.h"
#include"map.h"
#include"input.h"
#include"playermodel.h"
#include"manager.h"
#include"blockX.h"
#include"field.h"

//==============================================================
//コンストラクタ
//==============================================================
CMap::CMap()
{

}

//==============================================================
//デストラクタ
//==============================================================
CMap::~CMap()
{

}

//===========================================================================================
// 生成
//===========================================================================================
CMap *CMap::Create(void)
{
	CMap *pMap = nullptr;

	pMap = new CMap;

	if (pMap != nullptr)
	{
		pMap->Init();

		return pMap;
	}

	return pMap;
}

//==============================================================
//タイトル画面の初期化処理
//==============================================================
HRESULT CMap::Init(void)
{
	//Set();

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(-700.0f, 0.0f, 0.0f));

	return E_NOTIMPL;
}

//==============================================================
//タイトル画面の終了処理
//==============================================================
void CMap::Uninit(void)
{
	//オブジェクト（自分自身の破棄）
	//CObject::Release();
}

//===========================================================================================
// オブジェクトの読み込み
//===========================================================================================
void CMap::ObjectSet(FILE *pFile)
{
	D3DXVECTOR3 pos = {};
	D3DXVECTOR3 rot = {};
	int nType = 0;
	char not[128];

	while (strcmp("END_OBJECTSET", &not[0]) != 0)
	{
		fscanf(pFile, "%s", &not[0]);	//文字を読み込む

		if (strcmp("TYPE", &not[0]) == 0)
		{
			fscanf(pFile, "%s", &not[0]);						//文字を読み込む
			fscanf(pFile, "%s", &not[0]);						//=を読み込む
			fscanf(pFile, "%d", &nType);						//種類
		}
		if (strcmp("POS", &not[0]) == 0)
		{
			fscanf(pFile, "%s", &not[0]);	//=を読み込む
			fscanf(pFile, "%f", &pos.x);	//位置x
			fscanf(pFile, "%f", &pos.y);	//位置y
			fscanf(pFile, "%f", &pos.z);	//位置z
		}
		if (strcmp("ROT", &not[0]) == 0)
		{
			fscanf(pFile, "%s", &not[0]);						//=を読み込む
			fscanf(pFile, "%f", &rot.x);				//向きx
			fscanf(pFile, "%f", &rot.y);				//向きy
			fscanf(pFile, "%f", &rot.z);				//向きz
		}
	}

	if (strcmp("END_OBJECTSET", &not[0]) == 0)
	{//文字が読み込まれたら
	 //敵の設置
		CBlockX::Create( D3DXVECTOR3(pos.x, pos.y, pos.z), D3DXVECTOR3(rot.x, rot.y, rot.z));
	}
}

//===========================================================================================
// 読み込み
//===========================================================================================
void CMap::Set(void)
{
	//変数宣言
	bool bLoad = false;
	char not[128];

	FILE *pFile;			//ファイルポインタを宣言

	//ファイルを開く
	pFile = fopen("data\\TXT\\map.txt", "r");

	if (pFile != NULL)
	{//ファイルが開けた場合
		while (1)
		{
			fscanf(pFile, "%s", &not[0]);			//文字列を読み込む

			if (strcmp("SCRIPT", &not[0]) == 0)
			{//SCRIPTが読み込めたら
				bLoad = true;			//読み込みを開始
			}

			if (bLoad == true)
			{
				while (strcmp("END_SCRIPT", &not[0]) != 0)
				{
					fscanf(pFile, "%s", &not[0]);				//文字列を読み込む
	
					if (strcmp("SET_OBJECT", &not[0]) == 0)
					{
						ObjectSet(pFile);
					}
				}
			}

			if (strcmp("END_SCRIPT", &not[0]) == 0)
			{//SCRIPTが読み込めなかった場合
				bLoad = false;			//読み込みを終了
				break;			//処理を抜ける
			}
		}
	}
}