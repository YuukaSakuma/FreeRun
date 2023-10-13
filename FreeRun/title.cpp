//==============================================================
//
//爆発処理[explosion.cpp]
//Author:佐久間優香
//
//==============================================================
#include"renderer.h"
#include"title.h"
#include"input.h"
#include"titleTex.h"
#include"fade.h"

#define AUTOMOVE_RANKING	(420)						// タイトル自動遷移タイマー

//静的メンバ変数
CModel *CTitle::m_pModel = NULL;
bool CTitle::m_bReset = true;

//==============================================================
//コンストラクタ
//==============================================================
CTitle::CTitle()
{
	m_nTimer = 0;
}

//==============================================================
//デストラクタ
//==============================================================
CTitle::~CTitle()
{

}

//==============================================================
//タイトル画面の初期化処理
//==============================================================
HRESULT CTitle::Init(void)
{
	CCamera *pCamera = CManager::GetCamera();		//カメラの情報取得

	//オブジェクト2Dの生成
	CObject2D *pObject2D = CObject2D::Create();

	pObject2D->BindTexture(CManager::GetTexturet()->Regist("data\\TEXTURE\\bg.jpg"));
	pObject2D->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	pObject2D->SetVtx(0.0f, 0.0f);

	CTitleTex::Create();


	////カメラの初期化処理
	//pCamera->Init();

	//CEnemyModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CEnemyModel::ENEMYTYPE_BIRD_FIRST);


	return S_OK;
}

//==============================================================
//タイトル画面の終了処理
//==============================================================
void CTitle::Uninit(void)
{
	//オブジェクト（自分自身の破棄）
	CObject::Release();
}

//==============================================================
//タイトル画面の更新処理
//==============================================================
void CTitle::Update(void)
{
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	CInputKeyboard *pInputKeyboard = CManager::GetInputKeybard();		//キーボードの情報取得

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true )
	{//ENTERキー押したら

	 //チュートリアル画面
		CManager::GetFade()->Set(CScene::MODE_TUTORIAL);
	}

	CScene::Update();

	pDebugProc->Print("\nタイトル\n");

	CScene::Update();

	if (CManager::GetFade()->GetState() == CFade::STATE_NONE)
	{
		m_nTimer++;

		if (m_nTimer >= AUTOMOVE_RANKING)
		{// タイトル自動遷移規定値
			CManager::GetFade()->Set(CScene::MODE_RANKING);
		}
	}

}

//==============================================================
//タイトル画面の描画処理
//==============================================================
void CTitle::Draw(void)
{
	CScene::Draw();
}