//==============================================================
//
//プレイヤー処理[player.cpp]
//Author:佐久間優香
//
//==============================================================
#include"playermodel.h"
#include"renderer.h"
#include"manager.h"
#include"input.h"
#include"sound.h"
#include"model.h"
#include"motion.h"
#include"camera.h"
#include"objectX.h"
#include"modelHierarchy.h"
#include <stdio.h>
#include"debugproc.h"
#include"particle.h"
#include"life.h"
#include"game.h"
#include"score.h"

//マクロ定義
#define WIDTH (50.0f)	//横幅
#define HEIGHT (80.0f)	//高さ
#define LIFE (1)		//体力
#define SPEED (2.0f)		//素早さ
#define PLAYER_JUMP (80.0f)
#define PLAYER_GRAVITY (-4.0f)

//静的メンバ変数
char *CPlayerModel::m_apFileName[15] =
{
	"data\\MODEL\\player\\00_waist.x",
	"data\\MODEL\\player\\01_chest.x",
	"data\\MODEL\\player\\02_head.x",
	"data\\MODEL\\player\\03_UParm_L.x",
	"data\\MODEL\\player\\04_FOarm_L.x",
	"data\\MODEL\\player\\05_hand_L.x",
	"data\\MODEL\\player\\06_UParm_R.x",
	"data\\MODEL\\player\\07_FOarm_R.x",
	"data\\MODEL\\player\\08_hand_R.x",
	"data\\MODEL\\player\\09_thigh_L.x",
	"data\\MODEL\\player\\10_legs_L.x",
	"data\\MODEL\\player\\11_foot_L.x",
	"data\\MODEL\\player\\12_thigh_R.x",
	"data\\MODEL\\player\\13_legs_R.x",
	"data\\MODEL\\player\\14_foot_R.x",
};

//==============================================================
//コンストラクタ
//==============================================================
CPlayerModel::CPlayerModel()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//位置
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//前回の位置
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//移動量
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//向き
	m_max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//モデルの最大値
	m_min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//モデルの最小値
	m_Wpos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//マップの座標

	m_nCntDamage = 0;		//ダメージカウンター

	m_state = CObjectX::STATE_NONE;		//通常状態にする

	for (int nCntPlayer = 0; nCntPlayer < 15; nCntPlayer++)
	{
		m_apModel[nCntPlayer] = NULL;		//プレイヤー(パーツ)へのポインタ
	}

	m_nNumModel = 0;		//プレイヤー(パーツ)の総数
	m_bJump = false;		//ジャンプしたか
	m_pMotion = NULL;
	m_bMove = false;		//歩いてるか
	m_bLand = true;			//着地した
	m_fRotDest = 0.0f;		//目標
	m_fRotDiff = 0.0f;		//差分

	m_nLife = LIFE;

	m_nCntStart = 100;
	m_nCntScore = 0;

	m_bAutoMove = false;
	m_bSecondJump = false;
}

//==============================================================
//コンストラクタ(オーバーロード)
//==============================================================
CPlayerModel::CPlayerModel(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	m_pos = pos;		//位置
	m_rot = rot;		//向き
	m_posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//前回の位置
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//移動量
	m_max = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//モデルの最大値
	m_min = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//モデルの最小値
	m_Wpos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_nCntDamage = 0;		//ダメージカウンター

	m_state = CObjectX::STATE_NONE;		//通常状態にする


	for (int nCntPlayer = 0; nCntPlayer < 15; nCntPlayer++)
	{
		m_apModel[nCntPlayer] = NULL;		//プレイヤー(パーツ)へのポインタ
	}

	m_nNumModel = 0;		//プレイヤー(パーツ)の総数
	m_bJump = false;		//ジャンプしたか
	m_pMotion = NULL;
	m_bMove = false;		//歩いてるか
	m_bLand = true;			//着地した
	m_fRotDest = 0.0f;		//目標
	m_fRotDiff = 0.0f;		//差分
	
	m_nLife = LIFE;

	m_nCntStart = 100;
	m_nCntScore = 0;

	m_bAutoMove = false;
	m_bSecondJump = false;
	m_bHit = false;
}

//==============================================================
//デストラクタ
//==============================================================
CPlayerModel::~CPlayerModel()
{

}

//==============================================================
//プレイヤーモデルの生成処理
//==============================================================
CPlayerModel *CPlayerModel::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CPlayerModel *pPlayerModel = NULL;

	if (pPlayerModel == NULL)
	{//メモリが使用されてなかったら

	 //プレイヤーの生成
		pPlayerModel = new CPlayerModel(pos, rot);
	}

	//初期化処理
	pPlayerModel->Init();

	//種類の設定
	pPlayerModel->SetType(CObject::TYPE_PLAYER);

	return pPlayerModel;
}

//==============================================================
//プレイヤーモデルの初期化処理
//==============================================================
HRESULT CPlayerModel::Init(void)
{
	//CLife *pLife = CGame::GetLife();

	//プレイヤーの生成（全パーツ分）
	for (int nCntModel = 0; nCntModel < 15; nCntModel++)
	{
		m_apModel[nCntModel] = m_apModel[nCntModel]->Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_apFileName[nCntModel]);
	}

	//モデルのファイル読み込み
	CPlayerModel::SetModel("data\\TXT\\player.txt");

	m_pMotion = NULL;

	if (m_pMotion == NULL)
	{
		m_pMotion = m_pMotion->Create();

		if (m_pMotion != NULL)
		{
			//モーションの初期化・生成
			m_pMotion->SetModel(&m_apModel[0], 15);
			m_pMotion->Init("data\\TXT\\player.txt",15);
		}
	}

	//最大値・最小値代入
	for (int nCntPlayer = 0; nCntPlayer < 15; nCntPlayer++)
	{
		//最大値Y
		if ((nCntPlayer <= 0 && nCntPlayer <= 1) ||
			(nCntPlayer <= 11 && nCntPlayer <= 13))
		{
			m_max.y += m_apModel[nCntPlayer]->GetSizeMax().y;		//最大値加算
		}

		//最大値入れ替え
		if (m_max.x < m_apModel[nCntPlayer]->GetSizeMax().x)
		{
			m_max.x = m_apModel[nCntPlayer]->GetSizeMax().x;		//最小値X
		}
		if (m_max.z < m_apModel[nCntPlayer]->GetSizeMax().z)
		{
			m_max.z = m_apModel[nCntPlayer]->GetSizeMax().z;		//最小値Z

		}

		//最小値入れ替え
		if (m_min.x > m_apModel[nCntPlayer]->GetSizeMin().x)
		{
			m_min.x = m_apModel[nCntPlayer]->GetSizeMin().x;		//最小値X
		}
		if (m_min.y > m_apModel[nCntPlayer]->GetSizeMin().y)
		{
			m_min.y = m_apModel[nCntPlayer]->GetSizeMin().y;		//最小値Y
		}
		if (m_min.z > m_apModel[nCntPlayer]->GetSizeMin().z)
		{
			m_min.z = m_apModel[nCntPlayer]->GetSizeMin().z;		//最小値Z

		}
	}

	CObject::SetType(CObject::TYPE_PLAYER);

	m_max.y += 10.0f;

	//if (CManager::GetMode() == CScene::MODE_GAME)
	//{
	//	//寿命設定
	//	pLife->SetMax(LIFE);
	//}

	return S_OK;
}

//==============================================================
//プレイヤーモデルの終了処理
//==============================================================
void CPlayerModel::Uninit(void)
{
	for (int nCntPlayer = 0; nCntPlayer < 15; nCntPlayer++)
	{
		if (m_apModel[nCntPlayer] != NULL)
		{//使用されてるとき

		 //終了処理
			m_apModel[nCntPlayer]->Uninit();
			m_apModel[nCntPlayer] = NULL;
		}
	}

	if (m_pMotion != NULL)
	{//使用されてるとき

	 //モーションの破棄
		delete m_pMotion;
		m_pMotion = NULL;
	}

	//オブジェクト（自分自身の破棄）
	CObject::Release();
}

//==============================================================
//プレイヤーモデルの更新処理
//==============================================================
void CPlayerModel::Update(void)
{
	CDebugProc *pDebugProc = CManager::Get()->GetDebugProc();

	//位置の取得
	m_pos = GetPosition();

	//前回の位置に代入
	m_posOld = m_pos;

	//プレイヤーの操作
	CPlayerModel::Control();

	//重力
	m_move.y += PLAYER_GRAVITY;

	//移動量を更新
	m_move.x += (0.0f - m_move.x) * 0.1f;
	m_move.z += (0.0f - m_move.z) * 0.1f;
	m_move.y += (0.0f - m_move.y) * 0.1f;

	//位置を更新
	m_pos.x += m_move.x;
	m_pos.y += m_move.y;
	m_pos.z += m_move.z;

	//当たり判定
	if (CObjectX::Collision(&m_pos, &m_posOld, &m_move, m_min, m_max) == true)
	{
		m_bJump = false;	//ジャンプしてない状態にする
		m_bSecondJump = false;
		m_bLand = true;		//着地した状態にする
	}

	//スコア増加
	if (m_nCntStart == 0 && m_bHit == false && m_pos.x <= 70000.0f && m_pos.y >= -100.0f)
	{
		if (m_nCntScore == 0)
		{
			CScore::Add(3);
			m_nCntScore = 0;
		}
		else
		{
			m_nCntScore--;
			CScore::Add(12);
		}
	}

	//画面制限
	CPlayerModel::Screen();

 	SetState();

	//モーションの更新処理
	m_pMotion->Update();

	pDebugProc->Print("プレイヤーの位置 : [%f %f %f] \n", m_pos.x, m_pos.y, m_pos.z);

	pDebugProc->Print("体力 : [%d] \n", m_nLife);
	pDebugProc->Print("開始まで : [%d] \n", m_nCntStart);
	pDebugProc->Print("スコアアップ時間 : [%d] \n", m_nCntScore);
}

//==============================================================
////プレイヤーモデルの描画処理
//==============================================================
void CPlayerModel::Draw(void)
{
	D3DXMATRIX mtxRot, mtxTrans;						//計算用マトリックス

	LPDIRECT3DDEVICE9 pDevice;
	CRenderer *pRenderer = CManager::Get()->GetRenderer();

	//デバイスの取得
	pDevice = pRenderer->GetDevice();

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mxtWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);

	D3DXMatrixMultiply(&m_mxtWorld, &m_mxtWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);

	D3DXMatrixMultiply(&m_mxtWorld, &m_mxtWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mxtWorld);

	for (int nCntMat = 0; nCntMat < 15; nCntMat++)
	{
		m_apModel[nCntMat]->Draw();
	}
}

//==============================================================
//プレイヤーモデルの操作
//==============================================================
void CPlayerModel::Control(void)
{
	CInputKeyboard *pInputKeyboard = CManager::Get()->GetInputKeybard();
	CCamera *pCmamera = CManager::Get()->GetCamera();
	D3DXVECTOR3 CameraRot = pCmamera->GetRotation();


	/*if (m_pos.y >= 0.0f)
	{
		pCmamera->SetPositionVY(m_pos.y + 200.0f + sinf(m_rot.x) * 3000.0f);
		pCmamera->SetPositionRY(m_pos.y + 200.0f + sinf(m_rot.x) * 3000.0f);
	}*/

	m_fRotMove = m_rot.y;
	m_fRotDest = m_rot.y;

	//プレイヤーの移動(歩き)
	Walk();

	if ((m_move.x <= 0.8f && m_move.x >= -0.8f) && (m_move.y <= 0.8f && m_move.y >= -0.8f) && (m_move.z <= 0.8f && m_move.z >= -0.8f))
	{//動いていないとき

		m_bMove = false;		//動いていない状態にする
	}

	if (pInputKeyboard->GetTrigger(DIK_SPACE) == true && m_bJump == false)
	{

		//ジャンプする
		m_move.y = PLAYER_JUMP;

		//ジャンプした状態にする
		m_bJump = true;
		m_state = STATE_F_JUMP;
		m_bLand = false;
	}

	//差分を求める
	m_fRotDiff = m_fRotDest - m_fRotMove;

	//向きの補正処理
	RotCorrection();

	//モーションの設定
	SetMotion();
}

//==============================================================
//プレイヤーモデルの画面制限
//==============================================================
void CPlayerModel::Screen(void)
{
	if (m_pos.y <= -500.0f)
	{//画面下に出たら
		//if (m_bJump == true)
		//{//ジャンプしてたら

		// //着地
		//	m_pMotion->Set(m_pMotion->MOTION_LAND);
		//}

		//if (m_pMotion->IsFinish() == true)
		//{//終了したら

			m_bLand = true;		//着地した
		//}

		m_pos.y = -500.0f;
		m_move.y = -500.0f;

		m_bJump = false;
		m_bSecondJump = false;
	}

}

//==============================================================
//プレイヤーモデルのモーションの設定
//==============================================================
void CPlayerModel::SetMotion(void)
{
	if (m_bMove == true && m_pMotion->GetType() == m_pMotion->MOTION_NEUTRAL)
	{//歩いてる && 待機状態

	 //歩かせる
		m_pMotion->Set(m_pMotion->MOTION_WALK);
	}
	else if ((m_pMotion->GetType() != m_pMotion->MOTION_NEUTRAL&& m_pMotion->IsFinish() == true) ||
		(m_pMotion->GetType() != m_pMotion->MOTION_NEUTRAL && m_bMove == false && m_bJump == false && m_bLand == true))
	{//モーションが終了したら

	 //待機状態に戻す
		m_pMotion->Set(m_pMotion->MOTION_NEUTRAL);
	}
}

//==============================================================
//プレイヤーモデルの移動(歩き)
//==============================================================
void CPlayerModel::Walk(void)
{
	CDebugProc *pDebugProc = CManager::Get()->GetDebugProc();
	CInputKeyboard *pInputKeyboard = CManager::Get()->GetInputKeybard();
	CCamera *pCmamera = CManager::Get()->GetCamera();
	D3DXVECTOR3 CameraRot = pCmamera->GetRotation();


	if (pInputKeyboard->GetTrigger(DIK_F3) == true)
	{//F3キーが押されたら

	 //投影切り替え
		m_bAutoMove = m_bAutoMove ? false : true;
	}


	if (m_bAutoMove == false)
	{
		m_nCntStart--;

		if (m_nCntStart <= 0)
		{
			m_move.x += cosf(CameraRot.y + D3DX_PI * 0.5f) * SPEED;
			m_move.z += sinf(CameraRot.y + D3DX_PI * 0.5f) * SPEED;

			m_fRotDest = -CameraRot.y + D3DX_PI * 1.0f;

			m_bMove = true;			//歩いてるかの判定

			m_nCntStart = 0;

		}
		pDebugProc->Print("自動移動状態 \n");
	}
	else if (m_bAutoMove == true)
	{
		//キーが押されたとき
		if (pInputKeyboard->GetPress(DIK_A) == true)
		{//Aキーが押された
			m_move.x += cosf(CameraRot.y + -D3DX_PI * 0.5f) * SPEED;
			m_move.z += sinf(CameraRot.y + -D3DX_PI * 0.5f) * SPEED;

			m_fRotDest = -CameraRot.y + D3DX_PI * 0.0f;

			m_bMove = true;			//歩いてるかの判定
		}
		else if (pInputKeyboard->GetPress(DIK_D) == true)
		{//Dキーが押された
			m_move.x += cosf(CameraRot.y + D3DX_PI * 0.5f) * SPEED;
			m_move.z += sinf(CameraRot.y + D3DX_PI * 0.5f) * SPEED;

			m_fRotDest = -CameraRot.y + D3DX_PI * 1.0f;

			m_bMove = true;			//歩いてるかの判定
		}

		pDebugProc->Print("通常移動状態 \n");
		m_nCntStart = 100;
	}
}

//==============================================================
//プレイヤーモデルのヒット処理
//==============================================================
void CPlayerModel::Hit(void)
{
	m_nLife--;

	if (m_nLife > 0)
	{
		//m_state = CObject::STATE_DAMAGE;

		for (int nCntEnemy = 0; nCntEnemy < 15; nCntEnemy++)
		{
			//m_apModel[nCntEnemy]->SetState(m_state);		//ダメージ状態にする
		}

		//m_nCntDamage = 5;
	}
	else if (m_nLife <= 0)
	{
		
		m_bHit = true;
		//パーティクル生成
		CParticle::Create(m_pos, D3DXCOLOR(0.1f, 0.4f, 0.5f, 1.0f), TYPE_PLAYER, 30, 40);

		////終了処理
		//Uninit();

	}
}

//==============================================================
//状態設定
//==============================================================
void CPlayerModel::SetState(void)
{
	CInputKeyboard *pInputKeyboard = CManager::Get()->GetInputKeybard();

	switch (m_state)
	{
	case STATE_NONE:		//通常状態

		break;

	case STATE_ATTACK:		//攻撃状態

		break;

	case STATE_DAMAGE:		//ダメージ状態

		m_nCntDamage--;

		if (m_nCntDamage <= 0)
		{
			m_state = STATE_NONE;

			//状態設定
			for (int nCntEnemy = 0; nCntEnemy < 15; nCntEnemy++)
			{
				m_apModel[nCntEnemy]->SetState(m_state);		//通常状態にする
			}
		}
		break;

	case STATE_F_JUMP :		//1回目のジャンプ状態



		//	//ジャンプする
		//	m_move.y = 24.0f;

			//ジャンプした状態にする
			m_state = STATE_S_JUMP;

		//	m_bLand = false;

			//状態設定
			for (int nCntEnemy = 0; nCntEnemy < 15; nCntEnemy++)
			{
				m_apModel[nCntEnemy]->SetState(m_state);		//通常状態にする
			}
		break;

	case STATE_S_JUMP:		//2回目のジャンプ状態

		if (pInputKeyboard->GetTrigger(DIK_SPACE) == true && m_bSecondJump  == false)
		{

			//ジャンプする
			m_move.y = PLAYER_JUMP;

			//ジャンプした状態にする
			m_bSecondJump  = true;
			m_state = STATE_NONE;
			m_bLand = false;
		}


		/*	m_state = STATE_NONE;

			m_bJump = true;*/

			//状態設定
			for (int nCntEnemy = 0; nCntEnemy < 15; nCntEnemy++)
			{
				m_apModel[nCntEnemy]->SetState(m_state);		//通常状態にする
			}

		break;
	}
}

//==============================================================
//向きの補正処理
//==============================================================
void CPlayerModel::RotCorrection(void)
{
	if (m_fRotDiff > D3DX_PI)
	{
		m_fRotDiff += -D3DX_PI * 2;
	}
	else if (m_fRotDiff < -D3DX_PI)
	{
		m_fRotDiff += D3DX_PI * 2;
	}

	m_rot.y += m_fRotDiff * 0.2f;

	if (m_rot.y > D3DX_PI)
	{
		m_rot.y += -D3DX_PI * 2;
	}
	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}
}

//=============================================================
//モデルの読み込み
//=============================================================
void CPlayerModel::SetModel(const char * c_FileName)
{
	FILE *pFile;				//ファイルポインタ
	char aString[126];		//文字読み込み
	int nIndex = 0, nParent = 0;	//パーツNo.,親番号
	D3DXVECTOR3 pos, rot;

	//ファイル開く
	pFile = fopen(c_FileName, "r");

	if (pFile != NULL)
	{//ファイルが開けた場合

		while (strcmp(&aString[0], "CHARACTERSET") != 0)
		{//[CHARACTERSET]するまでの間

			fscanf(pFile, "%s", &aString[0]);		//文字読み込み
		}

		if (strcmp(&aString[0], "CHARACTERSET") == 0)
		{//[CHARACTERSET]が来たら

			while (strcmp(&aString[0], "END_CHARACTERSET") != 0)
			{//[END_CHARACTERSET]がくるまでの間

				fscanf(pFile, "%s", &aString[0]);		//文字読み込み

				if (strcmp(&aString[0], "PARTSSET") == 0)
				{//[PARTSSET]が来たら

					while (strcmp(&aString[0], "END_PARTSSET") != 0)
					{//[END_PARTSSET]がくるまでの間

						fscanf(pFile, "%s", &aString[0]);		//文字読み込み

						if (strcmp(&aString[0], "INDEX") == 0)
						{//パーツNo.

							fscanf(pFile, "%s", &aString[0]);		//文字読み込み
							fscanf(pFile, "%d", &nIndex);			//パーツNo.読み込み

						}
						else if (strcmp(&aString[0], "PARENT") == 0)
						{//親情報

							fscanf(pFile, "%s", &aString[0]);		//文字読み込み
							fscanf(pFile, "%d", &nParent);			//親番号読み込み

							if (nParent == -1)
							{//親がいなかったら

								m_apModel[nIndex]->SetParent(NULL);		//NULLを入れる
							}
							else
							{//親がいたら

								m_apModel[nIndex]->SetParent(m_apModel[nParent]);		//親番号入れる
							}
						}
						else if (strcmp(&aString[0], "POS") == 0)
						{//位置情報

							fscanf(pFile, "%s", &aString[0]);	//文字読み込み

							fscanf(pFile, "%f", &pos.x);		//位置読み込み
							fscanf(pFile, "%f", &pos.y);		//位置読み込み
							fscanf(pFile, "%f", &pos.z);		//位置読み込み

							m_apModel[nIndex]->SetPosition(pos);		//位置設定
							m_apModel[nIndex]->SetDefaultPosition(pos);	//初期位置設定

						}
						else if (strcmp(&aString[0], "ROT") == 0)
						{//向き情報

							fscanf(pFile, "%s", &aString[0]);	//文字読み込み

							fscanf(pFile, "%f", &rot.x);		//向き読み込み
							fscanf(pFile, "%f", &rot.y);		//向き読み込み
							fscanf(pFile, "%f", &rot.z);		//向き読み込み

							m_apModel[nIndex]->SetRotation(rot);		//向き設定
							m_apModel[nIndex]->SetDefaultRotation(rot);	//初期向き設定
						}
					}
				}
			}
		}

		//ファイル閉じる
		fclose(pFile);
	}
}