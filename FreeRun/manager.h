//==============================================================
//
//�}�l�[�W���w�b�_�[[manager.h]
//Author:���v�ԗD��
//
//==============================================================
#ifndef _MANAGER_H_						//���̃}�N������`����Ă��Ȃ�������
#define _MANAGER_H_						//2�d�C���N���[�h�h�~�̃}�N�����`����

#include"input.h"
#include"sound.h"
#include"camera.h"
#include"light.h"
#include"renderer.h"
#include"texture.h"
#include"debugproc.h"

//�O���錾
class CPlayerModel;
class CMaterial;

class CTitle;			//�^�C�g�����
class CTutorial;		//�`���[�g���A�����
class CGame;			//�Q�[�����
class CResult;			//���U���g���
class CRanking;			//�����L���O���
class CFade;			//�t�F�[�h

class CEdit;

//==============================================================
//�V�[���N���X
//==============================================================
class CScene : public CObject
{
public:

	//���[�h�̎��
	typedef enum
	{
		MODE_TITLE = 0,		//�^�C�g��
		MODE_TUTORIAL,		//�`���[�g���A��
		MODE_GAME,			//�Q�[��
		MODE_RESULT,		//���U���g
		MODE_RANKING,
		MODE_MAX,
	}MODE;

	CScene();				//�R���X�g���N�^
	CScene(MODE mode);		//�R���X�g���N�^(�I�[�o�[���[�h)
	~CScene();				//�f�X�g���N�^

	static CScene *Create(MODE mode);	//�V�[���̐���

	virtual	HRESULT Init(void);		//����������
	virtual void Uninit(void);		//�I������
	virtual void Update(void);		//�X�V����
	virtual	void Draw(void);		//�`�揈��

	MODE GetMode(void) { return m_mode; }			//���[�h�擾
	void SetMode(MODE mode) { m_mode = mode; }

private:

	MODE m_mode;	//���[�h
	
	//static CTitle *m_pTitle;			//�^�C�g����ʂ̏��
	//static CTutorial *m_pTutorial;		//�`���[�g���A�����
	//static CGame *m_pGame;				//�Q�[����ʂ̏��
	//static CResult *m_pResult;			//���U���g��ʂ̏��
	//static CRanking *m_pRanking;		//�����L���O��ʂ̏��

};

//==============================================================
//�}�l�[�W���N���X
//==============================================================
class CManager
{
public:
	CManager();			//�R���X�g���N�^
	~CManager();		//�f�X�g���N�^

	HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL hWindow);	//�}�l�[�W���̏���������
	void Uninit(void);											//�}�l�[�W���̏I������
	void Update(void);											//�}�l�[�W���̍X�V����
	void Draw(void);											//�}�l�[�W���̕`�揈��

	static CRenderer * GetRenderer(void);			//�����_���[�̎擾
	static CInputKeyboard *GetInputKeybard(void);	//�L�[�{�[�h�̎擾
	static CPlayerModel * GetPlayerModel(void);		//�v���C���[�̎擾
	static CCamera * GetCamera(void);				//�J�����̎擾
	static CLight * GetLight(void);					//���C�g�̎擾
	static CTexture * GetTexturet(void);			//�e�N�X�`���̎擾
	static CMaterial *GetMaterial(void) { return m_pMaterial; }		//�}�e���A���̎擾
	static CDebugProc *GetDebugProc(void);			//�f�o�b�O�v���b�N�̎擾
	static CFade *GetFade(void);

	static CEdit *GetEdit(void) { return m_pEdit; }

	static void SetMode(CScene::MODE mode);			//���[�h�̐ݒ�
	static CScene::MODE GetMode(void);				//���[�h�̎擾

	void LoadAll(void);		//�e�N�X�`���̓ǂݍ���
	void UnloadAll(void);	//�e�N�X�`���̔j��
	void CreateAll(void);	//��������
	void ResetMap(void);	//�Đ���

private:
	static CRenderer *m_pRenderer;					//�����_���[�̃|�C���^
	static CInputKeyboard *m_pInputKeyboard;		//�L�[�{�[�h�̃|�C���^
	static CPlayerModel * m_pPlayerModel;			//�v���C���[�̃|�C���^
	static CSound * m_pSound;						//�T�E���h�̃|�C���^
	static CCamera * m_pCamera;						//�J�����̃|�C���^
	static CLight * m_pLight;						//�J�����̃|�C���^
	static CTexture * m_pTexture;					//�e�N�X�`���̃|�C���^
	static CMaterial *m_pMaterial;		//�}�e���A���̏��
	static CDebugProc *m_pDebugProc;				//�f�o�b�O�v���b�N�̃|�C���^

	static CEdit *m_pEdit;

	static CScene *m_pScene;	//�V�[���̃|�C���^
	static CFade *m_pFade;
};

#endif // !_MANAGER_H_

