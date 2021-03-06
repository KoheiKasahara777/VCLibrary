// ===========================================================
//		テストアプリケーション
//
//				2003.02.13 Ver.1.0 ささい		初期作成
// ===========================================================


// ===========================================
//		インクルード・ファイル
// ===========================================
#include "stdafx.h"
#include "YSIniFiles.h"


// ===========================================
//		マクロ定義
// ===========================================


// ===========================================
//		数値定義
// ===========================================


// ===========================================
//		構造体宣言
// ===========================================


// ===========================================
//		クラス宣言
// ===========================================


// ===========================================
//		変数定義
// ===========================================


// ===========================================
//		関数定義
// ===========================================


/*=============================================================================
*NAME		:main
			:
*MODULE		:Test.cpp
			:
*FUNCTION	:メイン処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.00 初期作成
*/
int main( int argc, char* argv[] )
{
	TStringList slist;																			// 2003.02.13 Y.Sasai Ver.0.00 StringList.cpp読み込み用
	TStringList ysini;																			// 2003.02.13 Y.Sasai Ver.0.00 YSIniFiles.cpp読み込み用
	TYSIniFile ifile( "test.ini" );																// 2003.02.13 Y.Sasai Ver.0.00 Iniファイルクラス

	slist.LoadFromFile( "q:\\VCTest\\StringList.cpp" );											// 2003.02.13 Y.Sasai Ver.0.00 読み込み
	ysini.LoadFromFile( "q:\\VCTest\\YSIniFiles.cpp" );											// 2003.02.13 Y.Sasai Ver.0.00 読み込み
	ifile.WriteStringList( "StringList.cpp", "Source", slist );									// 2003.02.13 Y.Sasai Ver.0.00 書き込みだ
	ifile.WriteStringList( "YSIniFiles.cpp", "Source", ysini );									// 2003.02.13 Y.Sasai Ver.0.00 書き込みだ
	ifile.UpdateFile();

	return 0;
}


// ===========================================
//		関数定義終了
// ===========================================
