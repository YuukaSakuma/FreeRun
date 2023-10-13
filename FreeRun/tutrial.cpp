//==============================================================
//
//��������[explosion.cpp]
//Author:���v�ԗD��
//
//==============================================================
#include"renderer.h"
#include"tutorial.h"
#include"input.h"
#include"playermodel.h"
#include"manager.h"
#include"object2D.h"

//�ÓI�����o�ϐ�
CPlayerModel *CTutorial::m_pPlayerModel = NULL;	//�v���C���[�̏��
bool CTutorial::m_bReset = true;					//���Z�b�g�������ǂ���

//==============================================================
//�R���X�g���N�^
//==============================================================
CTutorial::CTutorial()
{

}

//==============================================================
//�f�X�g���N�^
//==============================================================
CTutorial::~CTutorial()
{

}

//==============================================================
//�^�C�g����ʂ̏���������
//==============================================================
HRESULT CTutorial::Init(void)
{
	//�I�u�W�F�N�g2D�̐���
	CObject2D *pObject2D = CObject2D::Create();

	pObject2D->BindTexture(CManager::GetTexturet()->Regist("data\\TEXTURE\\tutrial000.png"));
	pObject2D->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
	pObject2D->SetVtx(0.0f, 0.0f);



	return S_OK;
}

//==============================================================
//�^�C�g����ʂ̏I������
//==============================================================
void CTutorial::Uninit(void)
{
	//�I�u�W�F�N�g�i�������g�̔j���j
	CObject::Release();
}

//==============================================================
//�^�C�g����ʂ̍X�V����
//==============================================================
void CTutorial::Update(void)
{
	CDebugProc *pDebugProc = CManager::GetDebugProc();

	CInputKeyboard *pInputKeyboard = CManager::GetInputKeybard();		//�L�[�{�[�h�̏��擾

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true )
	{//ENTER�L�[��������

	 //�`���[�g���A�����
		CManager::SetMode(CScene::MODE_GAME);
	}

	pDebugProc->Print("\n�`���[�g���A��\n");
}

//==============================================================
//�^�C�g����ʂ̕`�揈��
//==============================================================
void CTutorial::Draw(void)
{

}