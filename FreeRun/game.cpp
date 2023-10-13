//==============================================================
//
//��������[explosion.cpp]
//Author:���v�ԗD��
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

#define START_TIME (180)		//�J�n����
#define START_SCORE (0)			//�J�n�X�R�A

//�ÓI�����o�ϐ�
CPlayerModel *CGame::m_pPlayerModel = NULL;	//�v���C���[�̏��
CScore *CGame::m_pScore = NULL;
CTime *CGame::m_pTime = NULL;
CEdit *CGame::m_pEdit = NULL;
CMap *CGame::m_pMap = NULL;
//CLife *CGame::m_pLife = NULL;

bool CGame::m_bReset = true;					//���Z�b�g�������ǂ���

//==============================================================
//�R���X�g���N�^
//==============================================================
CGame::CGame()
{

}

//==============================================================
//�f�X�g���N�^
//==============================================================
CGame::~CGame()
{

}

//==============================================================
//�Q�[����ʂ̏���������
//==============================================================
HRESULT CGame::Init(void)
{
	CCamera *pCamera = CManager::GetCamera();		//�J�����̏��擾

	/*CObject3D *p = CObject3D::Create();
	p->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	p->SetSize(1000.0f, 0.0f, 1000.0f);*/

	//�J�����̏���������
	pCamera->Init();

	m_pMap = CMap::Create();

	////�t�B�[���h�̐���
	CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	//CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(-700.0f, 0.0f, 0.0f));
	//CField::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(700.0f, 0.0f, 0.0f));

	//CWall::Create(CObject3D::TYPE_NONE, D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//�v���C���[�̐���
	m_pPlayerModel = CPlayerModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//�X�R�A�̐���
	m_pScore = CScore::Create(D3DXVECTOR3(800.0f, 50.0f, 0.0f));
	m_pScore->Set(START_SCORE);

	// �^�C���̐���
	m_pTime = CTime::Create(D3DXVECTOR3(550.0f, 50.0f, 0.0f));
	m_pTime->Set(START_TIME);

	CSound::Play(CSound::SOUND_LABEL_BGM001);

	return S_OK;
}

//==============================================================
//�^�C�g����ʂ̏I������
//==============================================================
void CGame::Uninit(void)
{
	CSound::Stop();

	

	//�v���C���[�̔j��
	if (m_pPlayerModel != NULL)
	{
		m_pPlayerModel->Uninit();
		//delete m_pPlayerModel;	// �������̊J��
		//m_pPlayerModel = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	

	// �X�R�A
	if (m_pScore != NULL)
	{
		CResult::SetScore(m_pScore->Get());
		m_pScore->Uninit();
		delete m_pScore;	// �������̊J��
		m_pScore = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}


	// �^�C��
	if (m_pTime != NULL)
	{
		m_pTime->Uninit();
		delete m_pTime;	// �������̊J��
		m_pTime = NULL;	// �g�p���Ă��Ȃ���Ԃɂ���
	}

	if (m_pMap != nullptr)
	{
		m_pMap->Uninit();
		delete m_pMap;
		m_pMap = nullptr;
	}


	//�I�u�W�F�N�g�i�������g�̔j���j
	CObject::Release();
}

//==============================================================
//�^�C�g����ʂ̍X�V����
//==============================================================
void CGame::Update(void)
{
	CDebugProc *pDebugProc = CManager::GetDebugProc();
	CInputKeyboard *pInputKeyboard = CManager::GetInputKeybard();		//�L�[�{�[�h�̏��擾
						
	D3DXVECTOR3 pos = m_pPlayerModel->GetPosition();

	

	if (m_pTime != NULL)
	{// �^�C��
		m_pTime->Update();
		if (m_pTime->GetNum() <= 0)
		{// ���Ԑ؂�
			CManager::GetFade()->Set(CScene::MODE_RESULT);
		}
	}

	

	if (m_pPlayerModel != NULL)
	{
		if (m_pPlayerModel->GetLife() <= 0)
		{//�̗͂��Ȃ��Ȃ���
			CManager::GetFade()->Set(MODE_RESULT);
		}
	}


	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{//ENTER�L�[��������
		CManager::GetFade()->Set(MODE_RESULT);
		//CManager::SetMode(CScene::MODE_RESULT);
	}

	pDebugProc->Print("\n�Q�[��\n");
}

//==============================================================
//�^�C�g����ʂ̕`�揈��
//==============================================================
void CGame::Draw(void)
{

}