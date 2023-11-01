// =======================================================
//
// メイン処理(main.h)
// author KOMURO HIROMU
//
// =======================================================
// 二重インクルード防止
#ifndef _MAIN_H_
#define _MAIN_H_

#include<windows.h>
#include"d3dx9.h"				//描画処理に必要

//ライブラリのリンク
#pragma comment(lib,"d3d9.lib")			//描画処理に必要
#pragma comment(lib,"d3dx9.lib")		//[d3d9.lib]の拡張ライブラリ
#pragma comment(lib,"dxguid.lib")		//DirectXコンポーネント（部品）使用に必要

//マクロ定義
#define SCREEN_WIDTH	(1280)			//ウインドウの幅
#define SCREEN_HEIGHT	(720)			//ウインドウの高さ
#define FVF_VERTEX_2D	(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)	//頂点フォーマット
#define FVF_VERTEX_3D	(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1)		//頂点フォーマット

#define MAX_OBJ	(1600)	// 最大のオブジェクト

//頂点情報[2D]の構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;	//頂点座標
	float rhw;			//座標変換用係数(1.0fで固定)
	D3DCOLOR col;		//頂点カラー
	D3DXVECTOR2 tex;	//テクスチャ座標
}VERTEX_2D;

//頂点情報[3D]の構造体の定義
typedef struct
{
	D3DXVECTOR3 pos;	//頂点座標
	D3DXVECTOR3 nor;	//法線ベクトル
	D3DCOLOR col;		//頂点カラー
	D3DXVECTOR2 tex;	//テクスチャ座標
}VERTEX_3D;

// 前方宣言
class CRenderer;
class CObject;

// プロトタイプ宣言
#endif // MAIN_H_

