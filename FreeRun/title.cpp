//==============================================================
//
//��������[explosion.cpp]
//Author:���v�ԗD��
//
//==============================================================
#include"renderer.h"
#include"title.h"
#include"input.h"
#include"titleTex.h"
#include"fade.h"

#define AUTOMOVE_RANKING	(420)						// �^�C�g�������J�ڃ^�C�}�[

//�ÓI�����o�ϐ�
CModel *CTitle::m_pModel = NULL;
bool CTitle::m_bReset = true;

//==============================================================
//�R���X�g���N�^
//==============================================================
CTitle::CTitle()
{
	m_nTimer = 0;
}

//==============================================================
//�f�X�g���N�^
//==============================================================
CTitle::~CTitle()
{

}

//==============================================================
//�^�C�g����ʂ̏���������
//==============================================================
HRESULT CTitle::Init(void)
{
	CCamera *pCamera = CManager::GetCamera();		//�J�����̏��擾

	//�I�u�W�F�N�g2D�̐���
	CObject2D *pObject2D = CObject2D::Create();

	pObject2D->BindTexture(CManager::GetTexturet()->Regist("data\\TEXTURE\\bg.jpg"));
	pObject2D->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	pObject2D->SetVtx(0.0f, 0.0f);

	CTitleTex::Create();


	////�J�����̏���������
	//pCamera->Init();

	//CEnemyModel::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CEnemyModel::ENEMYTYPE_BIRD_FIRST);


	return S_OK;
}

//==============================================================
//�^�C�g����ʂ̏I������
//==============================================================
void CTitle::Uninit(void)
{
	//�I�u�W�F�N�g�i�������g�̔j���j
	CObject::Release();
}

//==============================================================
//�^�C�g����ʂ̍X�V����
//==============================================================
void CTitle::Update(void)
{
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	CInputKeyboard *pInputKeyboard = CManager::GetInputKeybard();		//�L�[�{�[�h�̏��擾

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true )
	{//ENTER�L�[��������

	 //�`���[�g���A�����
		CManager::GetFade()->Set(CScene::MODE_TUTORIAL);
	}

	CScene::Update();

	pDebugProc->Print("\n�^�C�g��\n");

	CScene::Update();

	if (CManager::GetFade()->GetState() == CFade::STATE_NONE)
	{
		m_nTimer++;

		if (m_nTimer >= AUTOMOVE_RANKING)
		{// �^�C�g�������J�ڋK��l
			CManager::GetFade()->Set(CScene::MODE_RANKING);
		}
	}

}

//==============================================================
//�^�C�g����ʂ̕`�揈��
//==============================================================
void CTitle::Draw(void)
{
	CScene::Draw();
}