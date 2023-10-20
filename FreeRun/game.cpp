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

	/*CObject3D *p = CObject3D::Create();
	p->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	p->SetSize(1000.0f, 0.0f, 1000.0f);*/

	//カメラの初期化処理
	pCamera->Init();

	m_pMap = CMap::Create();

	////フィールドの生成(x = 35000.0f 約30秒) 
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(1400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(2100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(2800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(3500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(4200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(4900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(5600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(6300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(7000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(7700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(8400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(9100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(9800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(10500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(11200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(11900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(12600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(13300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(14000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(14700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(15400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(16100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(16800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(17500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(18200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(18900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(19600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(20300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(21000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(21700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(22400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(23100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(23800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(24500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(25200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(25900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(26600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(27300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(28000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(28700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(29400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(30100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(30800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(31500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(32200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(32900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(33600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(34300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(35000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(35700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(36400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(37100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(37800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(38500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(39200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(39900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(40600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(41300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(42000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(42700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(43400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(44100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(44800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(45500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(46200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(46900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(47600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(48300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(49000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(49700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(50400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(51100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(51800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(52500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(53200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(53900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(54600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(55300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(56000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(56700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(57400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(58100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(58800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(59500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(60200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(60900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(61600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(62300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(63000.0f, 0.0f, 0.0f));

	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(63700.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(64400.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(65100.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(65800.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(66500.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(67200.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(67900.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(68600.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(69300.0f, 0.0f, 0.0f));
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(70000.0f, 0.0f, 0.0f));

	//CModel::Create(D3DXVECTOR3(0.0f, -101.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground00.x");
	//CModel::Create(D3DXVECTOR3(100.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground00.x");

	//CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f),"data\\MODEL\\Ground01.x");
	//CModel::Create(D3DXVECTOR3(200.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground01.x");

	//CModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground02.x");
	//CModel::Create(D3DXVECTOR3(400.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground02.x");

	//CModel::Create(D3DXVECTOR3(0.0f, -801.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground03.x");
	//CModel::Create(D3DXVECTOR3(800.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), "data\\MODEL\\Ground03.x");

	CWall::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//プレイヤーの生成
	m_pPlayerModel = CPlayerModel::Create(D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//スコアの生成
	m_pScore = CScore::Create(D3DXVECTOR3(800.0f, 50.0f, 0.0f));
	m_pScore->Set(START_SCORE);

	// タイムの生成
	m_pTime = CTime::Create(D3DXVECTOR3(550.0f, 50.0f, 0.0f));
	m_pTime->Set(START_TIME);

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


	// タイム
	if (m_pTime != NULL)
	{
		m_pTime->Uninit();
		delete m_pTime;	// メモリの開放
		m_pTime = NULL;	// 使用していない状態にする
	}

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

	

	if (m_pTime != NULL)
	{// タイム
		m_pTime->Update();
		if (m_pTime->GetNum() <= 0)
		{// 時間切れ
			CManager::Get()->GetFade()->Set(CScene::MODE_RESULT);
		}
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
}

//==============================================================
//タイトル画面の描画処理
//==============================================================
void CGame::Draw(void)
{

}