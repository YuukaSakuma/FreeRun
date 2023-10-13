//==============================================================
//
//マネージャヘッダー[manager.h]
//Author:佐久間優香
//
//==============================================================
#ifndef _MANAGER_H_						//このマクロが定義されていなかったら
#define _MANAGER_H_						//2重インクルード防止のマクロを定義する

#include"input.h"
#include"sound.h"
#include"camera.h"
#include"light.h"
#include"renderer.h"
#include"texture.h"
#include"debugproc.h"

//前方宣言
class CPlayerModel;
class CMaterial;

class CTitle;			//タイトル画面
class CTutorial;		//チュートリアル画面
class CGame;			//ゲーム画面
class CResult;			//リザルト画面
class CRanking;			//ランキング画面
class CFade;			//フェード

class CEdit;

//==============================================================
//シーンクラス
//==============================================================
class CScene : public CObject
{
public:

	//モードの種類
	typedef enum
	{
		MODE_TITLE = 0,		//タイトル
		MODE_TUTORIAL,		//チュートリアル
		MODE_GAME,			//ゲーム
		MODE_RESULT,		//リザルト
		MODE_RANKING,
		MODE_MAX,
	}MODE;

	CScene();				//コンストラクタ
	CScene(MODE mode);		//コンストラクタ(オーバーロード)
	~CScene();				//デストラクタ

	static CScene *Create(MODE mode);	//シーンの生成

	virtual	HRESULT Init(void);		//初期化処理
	virtual void Uninit(void);		//終了処理
	virtual void Update(void);		//更新処理
	virtual	void Draw(void);		//描画処理

	MODE GetMode(void) { return m_mode; }			//モード取得
	void SetMode(MODE mode) { m_mode = mode; }

private:

	MODE m_mode;	//モード
	
	//static CTitle *m_pTitle;			//タイトル画面の情報
	//static CTutorial *m_pTutorial;		//チュートリアル画面
	//static CGame *m_pGame;				//ゲーム画面の情報
	//static CResult *m_pResult;			//リザルト画面の情報
	//static CRanking *m_pRanking;		//ランキング画面の情報

};

//==============================================================
//マネージャクラス
//==============================================================
class CManager
{
public:
	CManager();			//コンストラクタ
	~CManager();		//デストラクタ

	HRESULT Init(HINSTANCE hInstance,HWND hWnd,BOOL hWindow);	//マネージャの初期化処理
	void Uninit(void);											//マネージャの終了処理
	void Update(void);											//マネージャの更新処理
	void Draw(void);											//マネージャの描画処理

	static CRenderer * GetRenderer(void);			//レンダラーの取得
	static CInputKeyboard *GetInputKeybard(void);	//キーボードの取得
	static CPlayerModel * GetPlayerModel(void);		//プレイヤーの取得
	static CCamera * GetCamera(void);				//カメラの取得
	static CLight * GetLight(void);					//ライトの取得
	static CTexture * GetTexturet(void);			//テクスチャの取得
	static CMaterial *GetMaterial(void) { return m_pMaterial; }		//マテリアルの取得
	static CDebugProc *GetDebugProc(void);			//デバッグプロックの取得
	static CFade *GetFade(void);

	static CEdit *GetEdit(void) { return m_pEdit; }

	static void SetMode(CScene::MODE mode);			//モードの設定
	static CScene::MODE GetMode(void);				//モードの取得

	void LoadAll(void);		//テクスチャの読み込み
	void UnloadAll(void);	//テクスチャの破棄
	void CreateAll(void);	//生成処理
	void ResetMap(void);	//再生成

private:
	static CRenderer *m_pRenderer;					//レンダラーのポインタ
	static CInputKeyboard *m_pInputKeyboard;		//キーボードのポインタ
	static CPlayerModel * m_pPlayerModel;			//プレイヤーのポインタ
	static CSound * m_pSound;						//サウンドのポインタ
	static CCamera * m_pCamera;						//カメラのポインタ
	static CLight * m_pLight;						//カメラのポインタ
	static CTexture * m_pTexture;					//テクスチャのポインタ
	static CMaterial *m_pMaterial;		//マテリアルの情報
	static CDebugProc *m_pDebugProc;				//デバッグプロックのポインタ

	static CEdit *m_pEdit;

	static CScene *m_pScene;	//シーンのポインタ
	static CFade *m_pFade;
};

#endif // !_MANAGER_H_

