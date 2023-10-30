//==============================================================
//
//爆発処理[explosion.cpp]
//Author:佐久間優香
//
//==============================================================
#include"renderer.h"
#include"game.h"
#include"playermodel.h"
#include"blockX.h"
#include"field.h"
#include"score.h"
#include"fade.h"
#include"time.h"
#include"edit.h"
#include"wall.h"
#include"map.h"
#include"result.h"
#include"life.h"
#include"itemX.h"

#define START_TIME (180)		//開始時間
#define START_SCORE (0)			//開始スコア

//静的メンバ変数
CPlayerModel *CGame::m_pPlayerModel = NULL;	//プレイヤーの情報
CScore *CGame::m_pScore = NULL;
CTime *CGame::m_pTime = NULL;
CEdit *CGame::m_pEdit = NULL;
CMap *CGame::m_pMap = NULL;
//CLife *CGame::m_pLife = NULL;

bool CGame::m_bReset = true;					//リセットしたかどうか

//==============================================================
//コンストラクタ
//==============================================================
CGame::CGame()
{
	nData = 0;
}

//==============================================================
//デストラクタ
//==============================================================
CGame::~CGame()
{

}

//==============================================================
//ゲーム画面の初期化処理
//==============================================================
HRESULT CGame::Init(void)
{
	CCamera *pCamera = CManager::Get()->GetCamera();		//カメラの情報取得

	//カメラの初期化処理
	pCamera->Init();

	m_pMap = CMap::Create();

	CItemX::Create(D3DXVECTOR3(6600.0f, 1200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CItemX::Create(D3DXVECTOR3(20100.0f, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CItemX::Create(D3DXVECTOR3(27800.0f, 1200.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CItemX::Create(D3DXVECTOR3(36500.0f, 1400.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CItemX::Create(D3DXVECTOR3(53600.0f, 1800.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CItemX::Create(D3DXVECTOR3(61800.0f, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//プレイヤーの生成
	m_pPlayerModel = CPlayerModel::Create(D3DXVECTOR3(/*600*/00.0f, /*80*/0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//スコアの生成
	m_pScore = CScore::Create(D3DXVECTOR3(800.0f, 50.0f, 0.0f));
	m_pScore->Set(START_SCORE);

	//// タイムの生成
	//m_pTime = CTime::Create(D3DXVECTOR3(550.0f, 50.0f, 0.0f));
	//m_pTime->Set(START_TIME);

	CSound::Play(CSound::SOUND_LABEL_BGM001);

	return S_OK;
}

//==============================================================
//タイトル画面の終了処理
//==============================================================
void CGame::Uninit(void)
{
	CSound::Stop();

	//プレイヤーの破棄
	if (m_pPlayerModel != NULL)
	{
		m_pPlayerModel->Uninit();
		//delete m_pPlayerModel;	// メモリの開放
		//m_pPlayerModel = NULL;	// 使用していない状態にする
	}

	// スコア
	if (m_pScore != NULL)
	{
		CResult::SetScore(m_pScore->Get());
		m_pScore->Uninit();
		delete m_pScore;	// メモリの開放
		m_pScore = NULL;	// 使用していない状態にする
	}


	//// タイム
	//if (m_pTime != NULL)
	//{
	//	m_pTime->Uninit();
	//	delete m_pTime;	// メモリの開放
	//	m_pTime = NULL;	// 使用していない状態にする
	//}

	if (m_pMap != NULL)
	{
		m_pMap->Uninit();
		delete m_pMap;
		m_pMap = NULL;
	}


	//オブジェクト（自分自身の破棄）
	CObject::Release();
}

//==============================================================
//タイトル画面の更新処理
//==============================================================
void CGame::Update(void)
{
	CDebugProc *pDebugProc = CManager::Get()->GetDebugProc();
	CInputKeyboard *pInputKeyboard = CManager::Get()->GetInputKeybard();		//キーボードの情報取得
						
	D3DXVECTOR3 pos = m_pPlayerModel->GetPosition();
	

	if (pInputKeyboard->GetTrigger(DIK_F2) == true)
	{//ENTERキー押したら
		CItemX::Create(D3DXVECTOR3(0.0f, 100.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}

	if (pos.x >= 70000.0f)
	{
		nData++;

		if (nData == 100)
		{
			m_pScore->Add(10000);
		}
		if (nData >= 100)
		{
			CManager::Get()->GetFade()->Set(MODE_RESULT);
		}
	}

	
	//if (m_pTime != NULL)
	//{// タイム
	//	m_pTime->Update();
	//	//if (m_pTime->GetNum() <= 0)
	//	//{// 時間切れ
	//	//	CManager::Get()->GetFade()->Set(CScene::MODE_RESULT);
	//	//}
	//}
	if (pos.y <= -100.0f)
	{
		CManager::Get()->GetFade()->Set(MODE_RESULT);
	} 
	

	if (m_pPlayerModel != NULL)
	{
		if (m_pPlayerModel->GetLife() <= 0)
		{//体力がなくなった
			CManager::Get()->GetFade()->Set(MODE_RESULT);
		}
	}


	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{//ENTERキー押したら
		CManager::Get()->GetFade()->Set(MODE_RESULT);
		//CManager::SetMode(CScene::MODE_RESULT);
	}

	pDebugProc->Print("\nゲーム\n");
	pDebugProc->Print("画面遷移まで : %d\n",nData);
}

//==============================================================
//タイトル画面の描画処理
//==============================================================
void CGame::Draw(void)
{

}