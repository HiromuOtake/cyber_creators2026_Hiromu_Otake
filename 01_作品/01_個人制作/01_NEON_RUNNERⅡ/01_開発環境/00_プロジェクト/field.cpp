//==============================================
//
// 3Dスクロールアクション[field.h]
// Author: hiromu otake
//
//==============================================

#include "field.h"

// 静的メンバ初期化
LPDIRECT3DTEXTURE9 CField::m_pTextureTemp = nullptr;

//======================================================
// コンストラクタ
//======================================================
CField::CField(int nPriority) : CObject3D(nPriority)
{

}

//======================================================
// デストラクタ
//======================================================
CField::~CField()
{

}

//======================================================
// 初期設定
//======================================================
HRESULT CField::Init()
{
	CObject3D::Init();

	CField::Load();

	return S_OK;
}

//======================================================
// 終了処理
//======================================================
void CField::Uninit()
{
	CObject3D::Uninit();
}

//======================================================
// 更新処理
//======================================================
void CField::Update()
{
	CObject3D::Update();
}

//======================================================
// 描画処理
//======================================================
void CField::Draw()
{
	CObject3D::Draw();
}

//=====================================================
// フィールドの生成
//=====================================================
CField* CField::Create(D3DXVECTOR3 pos)
{
	CField* pField = new CField;

	if (pField != nullptr)
	{
		pField->SetType(TYPE_FIELD);
		pField->Init();
		pField->SetPos(pos);
		pField->BindTexture(m_pTextureTemp);
	}
	return  pField;
}

//======================================================
// テクスチャの設定
//======================================================
HRESULT CField::Load()
{
	if (m_pTextureTemp == nullptr)
	{
		LPDIRECT3DDEVICE9 pDevice;		//デバイスへのポインタ

		CRenderer* pRenderer = CManager::GetRenderere();

		//デバイスの取得
		pDevice = pRenderer->GetDevice();

		//テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,
			"data\\Texture\\sss.jpg",
			&m_pTextureTemp);
	}
	return S_OK;
}

//======================================================
// テクスチャの破棄
//======================================================
void CField::Unload()
{
	//テクスチャを破棄
	if (m_pTextureTemp != NULL)
	{
		m_pTextureTemp->Release();
		m_pTextureTemp = NULL;
	}
}

//======================================================
// 位置の取得
//======================================================
D3DXVECTOR3& CField::GetPos()
{
	return m_pos;
}

//=========================================
// 死亡フラグ設定処理
//=========================================
void CField::SetDeath()
{
	CObject::SetDeath();
}
