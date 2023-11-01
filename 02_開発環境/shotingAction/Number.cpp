// =======================================================
//
// ナンバー処理(Number.cpp)
// author KOMURO HIROMU
//
// =======================================================
#include "Number.h"
#include"main.h"
#include"renderer.h"
#include"Manager.h"
#include"input.h"
#include"Texture.h"

//====================================
// コンストラクタ
//====================================
CNumber::CNumber()
{
	// パラメーター初期化
	m_pVtxBuff = NULL;
	m_pos = D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_col = D3DCOLOR_RGBA(255, 255, 255, 255);
	m_fHeight = 0.0f;
	m_fWidth = 0.0f;
	m_nIdxTexture = 0;
}
//====================================
// デストラクタ
//====================================
CNumber::~CNumber()
{
}
//====================================
// 初期化処理
//====================================
HRESULT CNumber::Init(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	CTexture*pTexture = CManager::GetCTexture();

	// テクスチャの読み込み
	m_nIdxTexture = pTexture->Regist("data\\TEXTURE\\number002.png");

	//頂点バッファの読み込み
	if (FAILED(pRenderer->GetDevice()
		->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
			D3DUSAGE_WRITEONLY,
			FVF_VERTEX_2D,
			D3DPOOL_MANAGED,
			&m_pVtxBuff,
			NULL)))
	{
		return E_FAIL;
	}

	VERTEX_2D*pVtx;				//頂点情報へ

	// 対角線の長さを算出する
	float fLength = sqrtf(m_fWidth * m_fWidth + m_fHeight * m_fHeight);

	// 対角線の角度を算出する
	float fAngle = atan2f(m_fWidth, m_fHeight);

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点座標の座標の設定
	pVtx[0].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + (D3DX_PI + fAngle)) * fLength, m_pos.y + cosf(m_rot.z + (D3DX_PI + fAngle)) * fLength, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + (D3DX_PI - fAngle)) * fLength, m_pos.y + cosf(m_rot.z + (D3DX_PI - fAngle)) * fLength, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z - fAngle) * fLength, m_pos.y + cosf(m_rot.z - fAngle) * fLength, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + fAngle) * fLength, m_pos.y + cosf(m_rot.z + fAngle) * fLength, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラー設定
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	//テクスチャ標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}
//======================================
// 終了処理
//=====================================
void CNumber::Uninit(void)
{
	//頂点バッファの破棄
	if (m_pVtxBuff != NULL)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = NULL;
	}
	CObject::Relese();
}
//======================================
// 更新処理
//======================================
void CNumber::Update(void)
{
	VERTEX_2D*pVtx;				//頂点情報へ

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 対角線の長さを算出する
	float fLength = sqrtf(m_fWidth * m_fWidth + m_fHeight * m_fHeight);

	// 対角線の角度を算出する
	float fAngle = atan2f(m_fWidth, m_fHeight);

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// 頂点座標の座標の設定
	pVtx[0].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + (D3DX_PI + fAngle)) * fLength, m_pos.y + cosf(m_rot.z + (D3DX_PI + fAngle)) * fLength, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + (D3DX_PI - fAngle)) * fLength, m_pos.y + cosf(m_rot.z + (D3DX_PI - fAngle)) * fLength, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z - fAngle) * fLength, m_pos.y + cosf(m_rot.z - fAngle) * fLength, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + sinf(m_rot.z + fAngle) * fLength, m_pos.y + cosf(m_rot.z + fAngle) * fLength, 0.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}
//======================================
// 描画処理
//======================================
void CNumber::Draw(void)
{
	CRenderer *pRenderer = CManager::GetRenderer();
	CTexture*pTexture = CManager::GetCTexture();

	//頂点フォーマット
	pRenderer->GetDevice()->SetFVF(FVF_VERTEX_2D);

	//頂点バッファのデータストリームに設定
	pRenderer->GetDevice()->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_2D));

	//テクスチャの設定
	pRenderer->GetDevice()->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//ポリゴンの描画
	pRenderer->GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP,
		0,
		2);

}
//======================================
// 色の設定
//======================================
void CNumber::SetCol(const D3DCOLOR col)
{
	m_col = col;
	VERTEX_2D*pVtx;				//頂点情報へ

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//頂点カラー設定
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

}
//======================================
// テクスチャの設定
//======================================
void CNumber::SetAnimeTex(float Max_Conter, int m_nAnimeCounter)
{
	VERTEX_2D*pVtx;				//頂点情報へ

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャ標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f + (m_nAnimeCounter * (1.0f / Max_Conter)), 0.0f);
	pVtx[1].tex = D3DXVECTOR2((1.0f / Max_Conter) + (m_nAnimeCounter * (1.0f / Max_Conter)), 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f + (m_nAnimeCounter * (1.0f / Max_Conter)), 1.0f);
	pVtx[3].tex = D3DXVECTOR2((1.0f / Max_Conter) + (m_nAnimeCounter * (1.0f / Max_Conter)), 1.0f);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}
//======================================
// テクスチャの加算処理
//======================================
void CNumber::SetAddTex(float fTex)
{
	VERTEX_2D*pVtx;				//頂点情報へ

	// 頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//テクスチャ座標の更新
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f + fTex);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f + fTex);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f + fTex);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f + fTex);

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}
//======================================
// 大きさの設定
//======================================
void CNumber::SetScale(float fHeight, float fWidth)
{ 
	// 代入
	m_fHeight = fHeight;
	m_fWidth = fWidth;

	// 更新処理
	CNumber::Update();
}