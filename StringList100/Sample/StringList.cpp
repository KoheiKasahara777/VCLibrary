// ===========================================================
//		StringListクラス
//
//				2003.02.12 Ver.1.0 ささい		初期作成
// ===========================================================


// ===========================================
//		インクルード・ファイル
// ===========================================
#include <io.h>
#include "stdafx.h"
#include "StringList.h"


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
*NAME		:TStringList::Assign
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:内容コピー処理関数です
			:
*PROCESS	:・内容コピー処理です。
			:
*INPUT		:const TStringList source	:コピーもとクラス
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::Assign( TStringList* source )
{
	int tempi;

	Clear();																					// 2003.02.10 Y.Sasai Ver.0.90 全消去
	for ( tempi = 0; tempi < source->Count; tempi++ ) {
		Add( source->Items[tempi] );															// 2003.02.10 Y.Sasai Ver.0.90 追加だ
	}
}


/*=============================================================================
*NAME		:TStringList::KeyExists
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:キー名存在チェック処理関数です
			:
*PROCESS	:・キー名存在チェック処理です。
			:
*INPUT		:const CString key	:キー名
			:
*RETURN		: true = 正常終了
			:false = エラー終了
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TStringList::KeyExists( const CString key )
{
	return ( IdentExists( key ) );																// 2003.02.10 Y.Sasai Ver.0.90 なかみはIdentExistsなんだよ
}


/*=============================================================================
*NAME		:TStringList::IdentExists
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:Ident名存在チェック処理関数です
			:
*PROCESS	:・Ident名存在チェック処理です。
			:
*INPUT		:const CString iname
			:
*RETURN		: true = 存在するよ
			:false = 存在しないよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TStringList::IdentExists( const CString iname )
{
	return ( IdentIndex( iname ) >= 0 );														// 2003.02.10 Y.Sasai Ver.0.90 あればtrue
}


/*=============================================================================
*NAME		:TStringList::IdentIndex
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:Ident位置取得処理関数です
			:
*PROCESS	:・Ident位置取得処理です。
			:
*INPUT		:const CString iname	:ident名
			:
*RETURN		:位置
			:-1 = みつからなかった
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
int TStringList::IdentIndex( const CString iname )
{
	int tempi;

	for ( tempi = 0; tempi < Count; tempi++ ) {
		if ( iname.CompareNoCase( Ident[tempi] ) == 0 ) {										// 2003.02.10 Y.Sasai Ver.0.90 同じなら…
			return ( tempi );																	// 2003.02.10 Y.Sasai Ver.0.90 これだ
		}
	}

	return ( -1 );																				// 2003.02.10 Y.Sasai Ver.0.90 みつからなかったよ
}


/*=============================================================================
*NAME		:TStringList::DeleteValue
			:
*MODULE		:StringList.cpp
			:
*FUNCTION   :値削除処理関数です
            :
*PROCESS    :・値削除処理です。
			:
*INPUT		:const CString iname	:Ident名
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::DeleteValue( const CString iname )
{
	const int ipos = IdentIndex( iname );														// 2003.02.10 Y.Sasai Ver.0.90 Ident名位置取得

	if ( ipos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		return;																					// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	}
	Delete( ipos );																				// 2003.02.10 Y.Sasai Ver.0.90 削除だ
}


/*=============================================================================
*NAME		:TStringList::Add
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:アイテムズ追加処理関数です
			:
*PROCESS	:・アイテムズ追加処理です。
			:
*INPUT		:const CString txt	:追加文字列
			:
*RETURN		:追加した要素位置
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
int TStringList::Add( const CString txt )
{
	AddTail( txt );																				// 2003.02.10 Y.Sasai Ver.0.90 追加だ
	return ( Count );
}


/*=============================================================================
*NAME		:TStringList::Delete
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:削除処理関数です
			:
*PROCESS	:・指定位置の文字列を削除します。
			:
*INPUT		:const int index	:インデックス番号
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::Delete( const int index )
{
	RemoveAt( FindIndex( index ) );																// 2003.02.10 Y.Sasai Ver.0.90 削除だ
}


/*=============================================================================
*NAME		:TStringList::Clear
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:全データ削除処理関数です
			:
*PROCESS	:・全データ削除します。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::Clear( void )
{
	RemoveAll();																				// 2003.02.10 Y.Sasai Ver.0.90 全データ削除だ
}


/*=============================================================================
*NAME		:TStringList::LoadFromFile
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:ファイルから読み込み処理関数です
			:
*PROCESS	:・ファイルから読み込み処理です。
			:
*INPUT		:const CString fname	:ファイル名
			:
*RETURN		: true = 正常終了
			:false = エラー終了
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TStringList::LoadFromFile( const CString fname )
{
	FILE* fp = fopen( fname, "rt" );															// 2003.02.10 Y.Sasai Ver.0.90 テキスト読み込みモード
	char txt[1024+1];
	bool result = true;
	int tempi;

	if ( fp == NULL ) {																			// 2003.02.10 Y.Sasai Ver.0.90 NULLなら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 よめまへん
	}
	Clear();																					// 2003.02.12 Y.Sasai Ver.0.90 全初期化
	while ( true ) {
		if ( fgets( txt,  sizeof( txt ) - 1, fp ) == NULL ) {									// 2003.02.10 Y.Sasai Ver.0.90 １行読み込みおわりなら…
			if ( feof( fp ) == 0 ) {															// 2003.02.10 Y.Sasai Ver.0.90 終端でないなら…
				result = false;																	// 2003.02.10 Y.Sasai Ver.0.90 エラーだ
			}
			break;																				// 2003.02.10 Y.Sasai Ver.0.90 ぬけるぞ
		}
		for ( tempi = strlen( txt ) - 1; tempi >= 0; tempi-- ) {
			if ( txt[tempi] < ' ' ) {															// 2003.02.12 Y.Sasai Ver.0.90 制御文字なら…
				txt[tempi] = 0;																	// 2003.02.12 Y.Sasai Ver.0.90 ヌルにする
			} else {																			// 2003.02.13 Y.Sasai Ver.0.90 通常文字なら…
				break;
			}
		}
		Add( txt );																				// 2003.02.12 Y.Sasai Ver.0.90 追加だ
	}
	if ( fclose( fp ) != 0 ) {																	// 2003.02.10 Y.Sasai Ver.0.90 クローズエラーなら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 エラーだ
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 まあいいでしょ
}


/*=============================================================================
*NAME		:TStringList::SaveToFile
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:ファイルに書き込み処理関数です
			:
*PROCESS	:・ファイルに書き込み処理です。
			:
*INPUT		:const CString fname	:ファイル名
			:
*RETURN		: true = 正常終了
			:false = エラー終了
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TStringList::SaveToFile( const CString fname )
{
	FILE* fp = fopen( fname, "wt" );															// 2003.02.10 Y.Sasai Ver.0.90 テキスト書き込みモード
	int tempi;
	bool result = true;
	CString txt;

	if ( fp == NULL ) {																			// 2003.02.10 Y.Sasai Ver.0.90 オープンできなかったら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 エラーだ
	}
	for ( tempi = 0; tempi < Count; tempi++ ) {
		txt = Items[tempi] + "\n";																// 2003.02.12 Y.Sasai Ver.0.90 改行コードを追加する
		if ( fputs( txt, fp ) < 0 ) {															// 2003.02.10 Y.Sasai Ver.0.90 １行書き込みエラーなら…
			result = false;																		// 2003.02.10 Y.Sasai Ver.0.90 エラーだ
			break;																				// 2003.02.10 Y.Sasai Ver.0.90 ぬけるぞ
		}
	}
	if ( fclose( fp ) != 0 ) {																	// 2003.02.10 Y.Sasai Ver.0.90 クローズエラーなら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 エラーだ
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniSection::ItemsGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:アイテムズ取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TStringList::ItemsGet( const int a1 )
{
	return ( GetAt( FindIndex( a1 ) ) );
}


/*=============================================================================
*NAME		:TStringList::ItemsSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:アイテムズ設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::ItemsSet( const int a1, const CString p1 )
{
	SetAt( FindIndex( a1 ), p1 );
}


/*=============================================================================
*NAME		:TStringList::IdentGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:Ident名取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TStringList::IdentGet( const int a1 )
{
	return ( BeforeEqual( Items[a1] ) );
}


/*=============================================================================
*NAME		:TStringList::IdentSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:Ident名設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::IdentSet( const int a1, const CString p1 )
{
	CString vtxt = AfterEqual( Items[a1] );														// 2003.02.10 Y.Sasai Ver.0.90 Value文字列取得
	Items[a1] = p1 + "=" + vtxt;																// 2003.02.10 Y.Sasai Ver.0.90 新しい文字列設定
}


/*=============================================================================
*NAME		:TStringList::ValueGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:値取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TStringList::ValueGet( const CString a1 )
{
	const int ipos = IdentIndex( a1 );															// 2003.02.10 Y.Sasai Ver.0.90 Index番号取得

	if ( ipos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		return ( "" );																			// 2003.02.10 Y.Sasai Ver.0.90 空欄だ
	}

	return ( AfterEqual( Items[ipos] ) );														// 2003.02.10 Y.Sasai Ver.0.90 Value文字列を返す
}


/*=============================================================================
*NAME		:TStringList::ValueSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:値設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::ValueSet( const CString a1, const CString p1 )
{
	const int ipos = IdentIndex( a1 );															// 2003.02.10 Y.Sasai Ver.0.90 Index番号取得

	if ( ipos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		Add( a1 + "=" + p1 );																	// 2003.02.10 Y.Sasai Ver.0.90 追加だ
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		Items[ipos] = Ident[ipos] + "=" + p1;													// 2003.02.10 Y.Sasai Ver.0.90 設定だ
	}
}


/*=============================================================================
*NAME		:TStringList::CountGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:要素数取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
int TStringList::CountGet( void )
{
	return ( GetCount() );
}


/*=============================================================================
*NAME		:TStringList::BeforeEqual
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:イコール文字より前の文字列取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TStringList::BeforeEqual( const CString txt )
{
	const int epos = txt.Find( '=' );															// 2003.02.10 Y.Sasai Ver.0.90 イコール文字列検索
	CString result;

	if ( epos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		result = txt.Left( epos );																// 2003.02.10 Y.Sasai Ver.0.90 前の文字列を返す
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		result = txt;																			// 2003.02.10 Y.Sasai Ver.0.90 そのまま返す
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TStringList::AfterEqual
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:イコール文字よりあとの文字列取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TStringList::AfterEqual( const CString txt )
{
	const int epos = txt.Find( '=' );															// 2003.02.10 Y.Sasai Ver.0.90 イコール文字列検索
	CString result;

	if ( epos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		result = txt.Mid( epos + 1 );															// 2003.02.10 Y.Sasai Ver.0.90 うしろの文字列を返す
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		result = "";																			// 2003.02.10 Y.Sasai Ver.0.90 空欄だ
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TStringList::TextGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:テキスト取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 初期作成
*/
CString TStringList::TextGet( void )
{
	CString result = "";																		// 2003.02.13 Y.Sasai Ver.0.90 初期化だ
	int tempi;

	for ( tempi = 0; tempi < Count; tempi++ ) {
		result = result + Items[tempi] + "\n";													// 2003.02.13 Y.Sasai Ver.0.90 すべての文字列を追加していく
	}

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 これだ
}


/*=============================================================================
*NAME		:TStringList::TextSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:テキスト設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 初期作成
*/
void TStringList::TextSet( CString p1 )
{
	CString txt;
	int tempi = 0;
	bool lstat = true;

	Clear();																					// 2003.02.13 Y.Sasai Ver.0.90 全初期化だ
	while ( true ) {
		lstat = LineGet( p1, txt );																// 2003.02.13 Y.Sasai Ver.0.90 １行取得
		if ( lstat == false ) {																	// 2003.02.13 Y.Sasai Ver.0.90 おわりなら…
			if ( txt != "" ) {																	// 2003.02.13 Y.Sasai Ver.0.90 空行でないなら…
				Add( txt );																		// 2003.02.13 Y.Sasai Ver.0.90 追加だ
			}
			break;																				// 2003.02.13 Y.Sasai Ver.0.90 ぬけるぞ
		}
		Add( txt );																				// 2003.02.13 Y.Sasai Ver.0.90 追加だ
	}
}


/*=============================================================================
*NAME		:TStringList::LineGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:１行取得処理関数です
			:
*PROCESS	:・１行取得処理です。
			:
*INPUT		:CString& source	:元文字列
*INPUT		:CString& txt		:取得文字列
			:
*RETURN		: true = まだ続きがあるよ
			:false = 最後までいったよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 初期作成
*/
bool TStringList::LineGet( CString& source, CString& txt )
{
	const CString cr = "\n";																	// 2003.02.13 Y.Sasai Ver.0.90 改行文字
	const int crpos = source.Find( cr );														// 2003.02.13 Y.Sasai Ver.0.90 改行文字を検索
	const int crlen = cr.GetLength();															// 2003.02.13 Y.Sasai Ver.0.90 改行文字列長
	const bool result = ( crpos >= 0 );															// 2003.02.13 Y.Sasai Ver.0.90 改行文字があったらtrue

	if ( result == true ) {																		// 2003.02.13 Y.Sasai Ver.0.90 改行文字があったら…
		txt = source.Left( crpos );																// 2003.02.13 Y.Sasai Ver.0.90 文字列取得
		source = source.Mid( crpos + crlen );													// 2003.02.13 Y.Sasai Ver.0.90 改行文字以降の文字列を取得
	} else {																					// 2003.02.13 Y.Sasai Ver.0.90 改行文字がなかったら…
		txt = source;																			// 2003.02.13 Y.Sasai Ver.0.90 そのままコピー
		source = "";																			// 2003.02.13 Y.Sasai Ver.0.90 空行にする
	}

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 おわりだ
}


// ===========================================
//		関数定義終了
// ===========================================
