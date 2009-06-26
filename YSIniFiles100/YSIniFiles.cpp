// ===========================================================
//		YSIniFilesクラス
//
//				2003.02.10 Ver.1.0 ささい		初期作成
// ===========================================================


// ===========================================
//		インクルード・ファイル
// ===========================================
#include <io.h>
#include "stdafx.h"
#include "YSIniFiles.h"
#include "YSLib.h"


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
*NAME		:TYSIniSection::Assign
			:
*MODULE		:YSIniFiles.cpp
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
void TYSIniSection::Assign( TYSIniSection* source )
{
	FName = source->Name;																		// 2003.02.10 Y.Sasai Ver.0.90 セクション名コピー
	TStringList::Assign( source );
}


/*=============================================================================
*NAME		:TYSIniSection::Add
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:アイテムズ追加処理関数です
			:
*PROCESS	:・アイテムズ追加処理です。
			:
*INPUT		:const CString txt		:追加文字列
			:
*RETURN		:追加した要素位置
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 初期作成
*/
int TYSIniSection::Add( const CString txt )
{
	CString txt2 = txt;
	int result;

	txt2.TrimLeft();
	txt2.TrimRight();
	if ( txt2 != "" ) {																			// 2003.02.12 Y.Sasai Ver.0.90 文字列があるなら…
		result = TStringList::Add( txt );														// 2003.02.12 Y.Sasai Ver.0.90 追加だ
	} else {																					// 2003.02.12 Y.Sasai Ver.0.90 文字列がなかったら…
		result = -1;																			// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
	}

	return ( result );																			// 2003.02.12 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniSection::NameGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:セクション名取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TYSIniSection::NameGet( void )
{
	return ( FName );
}


/*=============================================================================
*NAME		:TStringList::NameSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:セクション名設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniSection::NameSet( const CString txt )
{
	FName = txt;
}


/*=============================================================================
*NAME		:TYSIniFile::TYSIniFile
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:コンストラクタ関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
TYSIniFile::TYSIniFile( const CString fname ) : CObList( 16 )
{
	FFileName = fname;																			// 2003.02.10 Y.Sasai Ver.0.90 ファイル名設定
	Read();																						// 2003.02.10 Y.Sasai Ver.0.90 読み込みだ
}


/*=============================================================================
*NAME		:TYSIniFile::TYSIniFile
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:デストラクタ関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
TYSIniFile::~TYSIniFile( void )
{
	Clear();																					// 2003.02.10 Y.Sasai Ver.0.90 全初期化だ
	CObList::~CObList();																		// 2003.02.12 Y.Sasai Ver.0.90 親クラスの処理だ
}


/*=============================================================================
*NAME		:TYSIniFile::Read
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:読み込み処理関数です
			:
*PROCESS	:・Iniファイル読み込みです。
			:
*RETURN		: true = 正常終了
			:false = エラー終了
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::Read( void )
{
	TStringList slist;																			// 2003.02.10 Y.Sasai Ver.0.90 文字列リスト
	int tempi;
	TYSIniSection* ysection;																	// 2003.02.10 Y.Sasai Ver.0.90 セクションクラス
	CString sitem;

	if ( FileName == "" ) {																		// 2003.02.10 Y.Sasai Ver.0.90 ファイル名未設定なら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわる
	} else if ( FileExists( FileName ) == false ) {												// 2003.02.10 Y.Sasai Ver.0.90 そのファイルがなかったら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	}

	ysection = NULL;																			// 2003.02.10 Y.Sasai Ver.0.90 セクションクラス初期化だ
	if ( slist.LoadFromFile( FileName ) == false ) {											// 2003.02.10 Y.Sasai Ver.0.90 ファイル読み込みエラーなら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 エラーだ
	}
	for ( tempi = 0; tempi < slist.Count; tempi++ ) {
		sitem = slist[tempi];
		if ( sitem == "" ) {																	// 2003.02.10 Y.Sasai Ver.0.90 空行なら…
			continue;																			// 2003.02.10 Y.Sasai Ver.0.90 つぎだ
		}
		if ( SectionCheck( sitem ) == true ) {													// 2003.02.10 Y.Sasai Ver.0.90 セクション名なら…
			ysection = Add();																	// 2003.02.10 Y.Sasai Ver.0.90 セクション追加
			ysection->Name = SectionNameGet( sitem );											// 2003.02.10 Y.Sasai Ver.0.90 セクション名設定
		} else if ( ysection != NULL ) {														// 2003.02.10 Y.Sasai Ver.0.90 セクション設定されているなら…
			ysection->Add( sitem );																// 2003.02.10 Y.Sasai Ver.0.90 セクションに追加
		}
	}

	return ( true );																			// 2003.02.10 Y.Sasai Ver.0.90 まあいいでしょ
}


/*=============================================================================
*NAME		:TYSIniFile::SectionCheck
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:セクションチェック処理関数です
			:
*PROCESS	:・セクションチェック処理です。
			:
*INPUT		:const CString txt	:セクション文字列
			:
*RETURN		: true = あるよ
			:false = ないよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::SectionCheck( CString txt )
{
	txt.TrimLeft();																				// 2003.02.10 Y.Sasai Ver.0.90 前後の空白除去
	txt.TrimRight();
	if ( txt == "" ) {																			// 2003.02.10 Y.Sasai Ver.0.90 空欄なら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	}

	if ( txt[0] != '[' ) {																		// 2003.02.10 Y.Sasai Ver.0.90 セクション開始文字でないなら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	} else if ( txt.Find( ']' ) <= 0 ) {														// 2003.02.10 Y.Sasai Ver.0.90 セクション終了文字がないなら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	}

	return ( true );																			// 2003.02.10 Y.Sasai Ver.0.90 セクション名だ
}


/*=============================================================================
*NAME		:TYSIniFile::SectionNameGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:セクション名取得処理関数です
			:
*PROCESS	:・セクション名取得処理です。
			:
*INPUT		:CString txt	:文字列
			:
*RETURN		:セクション文字列
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TYSIniFile::SectionNameGet( CString txt )
{
	int kpos;
	CString result;

	txt.TrimLeft();																				// 2003.02.10 Y.Sasai Ver.0.90 前後の空白除去
	txt.TrimRight();
	kpos = txt.Find( ']' );																		// 2003.02.10 Y.Sasai Ver.0.90 かっこ文字位置取得
	result = txt.Mid( 1, kpos - 1 );															// 2003.02.10 Y.Sasai Ver.0.90 文字列取得だ

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::Write
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:書き込み処理関数です
			:
*PROCESS	:・Iniファイル書き込み処理です。
			:
*RETURN		: true = 正常終了
			:false = エラー終了
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::Write( void )
{
	TStringList slist;																			// 2003.02.10 Y.Sasai Ver.0.90 文字列リストクラス
	int tempi;																					// 2003.02.10 Y.Sasai Ver.0.90 作業用変数

	if ( FileName == "" ) {																		// 2003.02.10 Y.Sasai Ver.0.90 ファイル名未設定なら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	}
	for ( tempi = 0; tempi < Count; tempi++ ) {
		WriteSub( &slist, Items[tempi] );														// 2003.02.10 Y.Sasai Ver.0.90 書き込み処理だ
		if ( tempi < ( Count - 1 ) ) {															// 2003.02.10 Y.Sasai Ver.0.90 最後でないなら…
			slist.Add( "" );																	// 2003.02.10 Y.Sasai Ver.0.90 空行追加だ
		}
	}
	slist.SaveToFile( FileName );																// 2003.02.10 Y.Sasai Ver.0.90 ファイルに書き込み

	return ( true );
}


/*=============================================================================
*NAME		:TYSIniFile::WriteSub
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:書き込みサブ処理関数です
			:
*PROCESS	:・書き込みサブ処理です。
			:
*INPUT		:TStringList slist			:文字列リストクラス
*INPUT		:TYSIniSection ysection		:セクションクラス
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteSub( TStringList* slist, TYSIniSection* ysection )
{
	int tempi;

	slist->Add( "[" + ysection->Name + "]" );													// 2003.02.10 Y.Sasai Ver.0.90 セクション名設定
	for ( tempi = 0; tempi < ysection->Count; tempi++ ) {
		slist->Add( ysection->Items[tempi] );													// 2003.02.10 Y.Sasai Ver.0.90 追加だ
	}
}


/*=============================================================================
*NAME		:TYSIniFile::Add
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:追加処理関数です
			:
*PROCESS	:・追加処理です。
			:
*RETURN		:追加クラス
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
TYSIniSection* TYSIniFile::Add( void )
{
	TYSIniSection* result = new TYSIniSection();												// 2003.02.10 Y.Sasai Ver.0.90 新規のセクションクラス作成

	AddTail( result );																			// 2003.02.10 Y.Sasai Ver.0.90 追加だ

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::Delete
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:削除処理関数です
			:
*PROCESS	:・削除処理です。
			:
*INPUT		:const int index	:インデックス番号
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::Delete( const int index )
{
	TYSIniSection* ysection = (TYSIniSection*)GetAt( FindIndex( index ) );						// 2003.02.10 Y.Sasai Ver.0.90 iniセクションクラス取得

	delete( ysection );																			// 2003.02.10 Y.Sasai Ver.0.90 破棄だ
	RemoveAt( FindIndex( index ) );																// 2003.02.10 Y.Sasai Ver.0.90 削除だ
}


/*=============================================================================
*NAME		:TYSIniFile::Assign
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:内容コピー処理関数です
			:
*PROCESS	:・内容コピー処理です。
			:
*INPUT		:const TYSIniFile source	:コピーもとクラス
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::Assign( TYSIniFile* source )
{
	int tempi;
	TYSIniSection* ysection;

	Clear();																					// 2003.02.10 Y.Sasai Ver.0.90 初期化だ
	for ( tempi = 0; tempi < source->Count; tempi++ ) {
		ysection = Add();																		// 2003.02.10 Y.Sasai Ver.0.90 追加だ
		ysection->Assign( source->Items[tempi] );												// 2003.02.10 Y.Sasai Ver.0.90 内容コピー
	}
}


/*=============================================================================
*NAME		:TYSIniFile::Clear
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:全データ初期化処理関数です
			:
*PROCESS	:・全データ初期化処理です。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::Clear( void )
{
	int tempi;

	for ( tempi = Count - 1; tempi >= 0; tempi-- ) {
		Delete( tempi );																		// 2003.02.10 Y.Sasai Ver.0.90 すべて削除だ
	}
}


/*=============================================================================
*NAME		:TYSIniFile::DeleteKey
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:キー削除処理関数です
			:
*PROCESS	:・キー削除処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::DeleteKey( const CString section, const CString iname )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 セクション位置取得

	if ( spos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		Items[spos]->DeleteValue( iname );														// 2003.02.10 Y.Sasai Ver.0.90 削除だ
	}
}


/*=============================================================================
*NAME		:TYSIniFile::EraseSection
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:セクション削除処理関数です
			:
*PROCESS	:・セクション削除処理です。
			:
*INPUT		:const CString section		:セクション名
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::EraseSection( const CString section )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 セクション位置取得

	if ( spos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		RemoveAt( FindIndex( spos ) );															// 2003.02.10 Y.Sasai Ver.0.90 削除だ
	}
}


/*=============================================================================
*NAME		:TYSIniFile::ReadBool
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:bool値読み込み処理関数です
			:
*PROCESS	:・bool値読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const bool defvalue		:デフォルト値
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::ReadBool( const CString section, const CString iname, const bool defvalue )
{
	bool result = ( ReadInteger( section, iname, (int)defvalue ) != 0 );						// 2003.02.10 Y.Sasai Ver.0.90 読み込みだ
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::ReadFloat
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:double値読み込み処理関数です
			:
*PROCESS	:・double値読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const double defvalue	:デフォルト値
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
double TYSIniFile::ReadFloat( const CString section, const CString iname, const double defvalue )
{
	double result = StrToFloat( ReadString( section, iname, FloatToStr( defvalue ) ) );
	return ( result );
}


/*=============================================================================
*NAME		:TYSIniFile::ReadInteger
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:int値読み込み処理関数です
			:
*PROCESS	:・int値読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const int defvalue		:デフォルト値
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
int TYSIniFile::ReadInteger( const CString section, const CString iname, const int defvalue )
{
	int result = StrToInt( ReadString( section, iname, IntToStr( defvalue ) ) );
	return ( result );
}


/*=============================================================================
*NAME		:TYSIniFile::ReadPoint
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:座標構造体読み込み処理関数です
			:
*PROCESS	:・座標構造体読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const CPoint* point	:座標構造体ポインタ
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 初期作成
*/
CPoint TYSIniFile::ReadPoint( const CString section, const CString iname, const CPoint* point )
{
	CPoint defpoint;																			// 2003.02.12 Y.Sasai Ver.0.90 初期値
	CPoint result;																				// 2003.02.12 Y.Sasai Ver.0.90 終了値

	if ( point != NULL ) {																		// 2003.02.12 Y.Sasai Ver.0.90 デフォルト設定があるなら…
		defpoint = *point;																		// 2003.02.12 Y.Sasai Ver.0.90 座標設定
	} else {																					// 2003.02.12 Y.Sasai Ver.0.90 デフォルトがないなら…
		defpoint.x = 0;																			// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
		defpoint.y = 0;																			// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
	};
	result.x = ReadInteger( section, iname + XIdent, defpoint.x );								// 2003.02.12 Y.Sasai Ver.0.90 ｘ座標読み込み
	result.y = ReadInteger( section, iname + YIdent, defpoint.y );								// 2003.02.12 Y.Sasai Ver.0.90 ｙ座標読み込み

	return ( result );																			// 2003.02.12 Y.Sasai Ver.0.90 そのまま返す
}


/*=============================================================================
*NAME		:TYSIniFile::ReadRect
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:四角形構造体読み込み処理関数です
			:
*PROCESS	:・四角形構造体読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const CRect* rect		:四角形構造体ポインタ
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 初期作成
*/
CRect TYSIniFile::ReadRect( const CString section, const CString iname, const CRect* rect )
{
	CRect defrect;																				// 2003.02.12 Y.Sasai Ver.0.90 初期値
	CRect result;																				// 2003.02.12 Y.Sasai Ver.0.90 終了値

	if ( rect != NULL ) {																		// 2003.02.12 Y.Sasai Ver.0.90 デフォルト設定があるなら…
		defrect = *rect;																		// 2003.02.12 Y.Sasai Ver.0.90 座標設定
	} else {																					// 2003.02.12 Y.Sasai Ver.0.90 デフォルトがないなら…
		defrect.left = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
		defrect.top = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
		defrect.right = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
		defrect.bottom = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 初期化だ
	}

	result.left = ReadInteger( section, iname + LeftIdent, defrect.left );						// 2003.02.12 Y.Sasai Ver.0.90 左座標読み込み
	result.top = ReadInteger( section, iname + TopIdent, defrect.top );							// 2003.02.12 Y.Sasai Ver.0.90 上座標読み込み
	result.right = ReadInteger( section, iname + RightIdent, defrect.right );					// 2003.02.12 Y.Sasai Ver.0.90 右座標読み込み
	result.bottom = ReadInteger( section, iname + BottomIdent, defrect.bottom );				// 2003.02.12 Y.Sasai Ver.0.90 下座標読み込み
	result.NormalizeRect();																		// 2003.02.12 Y.Sasai Ver.0.90 四角形の正規化

	return ( result );																			// 2003.02.12 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::ReadString
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:文字列値読み込み処理関数です
			:
*PROCESS	:・文字列値読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const CString defvalue	:デフォルト値
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TYSIniFile::ReadString( const CString section, const CString iname, const CString defvalue )
{
	CString result = defvalue;																	// 2003.02.10 Y.Sasai Ver.0.90 終了値
	int spos;
	TYSIniSection* ysection;																	// 2003.02.10 Y.Sasai Ver.0.90 セクションクラス

	spos = SectionIndex( section );																// 2003.02.10 Y.Sasai Ver.0.90 セクション位置取得
	if ( spos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		ysection = Add();																		// 2003.02.10 Y.Sasai Ver.0.90 追加だ
		ysection->Name = section;																// 2003.02.10 Y.Sasai Ver.0.90 セクション名設定
		ysection->Value[iname] = defvalue;														// 2003.02.10 Y.Sasai Ver.0.90 設定だ
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		ysection = Items[spos];																	// 2003.02.10 Y.Sasai Ver.0.90 セクションクラス取得
		if ( ysection->IdentExists( iname ) == true ) {											// 2003.02.10 Y.Sasai Ver.0.90 あったら…
			result = ysection->Value[iname];													// 2003.02.10 Y.Sasai Ver.0.90 これだ
		} else {																				// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
			ysection->Value[iname] = defvalue;													// 2003.02.10 Y.Sasai Ver.0.90 初期値だ
		}
	}

	return ( result );
}


/*=============================================================================
*NAME		:TYSIniFile::ReadStringList
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:文字列リスト読み込み処理関数です
			:
*PROCESS	:・文字列リスト読み込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:TStringList& slist		:設定クラス
			:
*RETURN		:読み込み行数
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 初期作成
*/
int TYSIniFile::ReadStringList( const CString section, const CString iname, TStringList& slist )
{
	int result = 0;																				// 2003.02.13 Y.Sasai Ver.0.90 初期化だ
	CString ident;
	CString txt;

	slist.Clear();																				// 2003.02.13 Y.Sasai Ver.0.90 全消去だ
	while ( true ) {
		ident = iname + Number[result];															// 2003.02.13 Y.Sasai Ver.0.90 Ident名作成
		if ( ValueExists( section, ident ) == false ) {											// 2003.02.13 Y.Sasai Ver.0.90 Ident名がなかったら…
			break;																				// 2003.02.13 Y.Sasai Ver.0.90 ぬけるぞ
		}
		txt = ReadString( section, ident, "" );													// 2003.02.13 Y.Sasai Ver.0.90 文字列読み込み
		slist.Add( txt );																		// 2003.02.13 Y.Sasai Ver.0.90 追加だ
		result++;																				// 2003.02.13 Y.Sasai Ver.0.00 加算だ
	}

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::SectionIndex
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:セクション位置取得処理関数です
			:
*PROCESS	:・セクション位置取得処理です。
			:
*INPUT		:const CString section	:セクション文字列
			:
*RETURN		:位置
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
int TYSIniFile::SectionIndex( const CString section )
{
	int tempi;

	for ( tempi = 0; tempi < Count; tempi++ ) {
		if ( section.CompareNoCase( Items[tempi]->Name ) == 0 ) {								// 2003.02.10 Y.Sasai Ver.0.90 みつかったら…
			return ( tempi );																	// 2003.02.10 Y.Sasai Ver.0.90 これだ
		}
	}

	return ( -1 );																				// 2003.02.10 Y.Sasai Ver.0.90 みつからんかったよ
}


/*=============================================================================
*NAME		:TYSIniFile::SectionExists
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:セクション存在チェック処理関数です
			:
*PROCESS	:・セクション存在チェック処理です。
			:
*INPUT		:const CString section	:セクション文字列
			:
*RETURN		: true = あったよ
			:false = なかったよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::SectionExists( const CString section )
{
	bool result = ( SectionIndex( section ) >= 0 );												// 2003.02.10 Y.Sasai Ver.0.90 インデックスをみつける
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::UpdateFile
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:データ書き込み処理関数です
			:
*PROCESS	:・データ書き込み処理です。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::UpdateFile( void )
{
	bool result = Write();																		// 2003.02.10 Y.Sasai Ver.0.90 ただの書き込みなんだな
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:TYSIniFile::ValueExists
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:キー存在チェック関数です。
			:
*PROCESS	:・キー存在チェックです。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
			:
*RETURN		: true = あったよ
			:false = なかったよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool TYSIniFile::ValueExists( const CString section, const CString iname )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 セクション位置取得

	if ( spos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 なかったよ
	} else if ( Items[spos]->IdentExists( iname ) == false ) {									// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 おわりだ
	}

	return ( true );																			// 2003.02.10 Y.Sasai Ver.0.90 まあいいでしょ
}


/*=============================================================================
*NAME		:TYSIniFile::WriteBool
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:bool値書き込み処理関数です
			:
*PROCESS	:・bool値書き込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const bool ival		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteBool( const CString section, const CString iname, const bool ival )
{
	WriteInteger( section, iname, (int)ival );
}


/*=============================================================================
*NAME		:TYSIniFile::WriteFloat
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:double値書き込み処理関数です
			:
*PROCESS	:・double値書き込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const double ival		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteFloat( const CString section, const CString iname, const double ival )
{
	WriteString( section, iname, FloatToStr( ival ) );
}


/*=============================================================================
*NAME		:TYSIniFile::WriteInteger
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:int値書き込み処理関数です
			:
*PROCESS	:・int値書き込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const int ival			:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteInteger( const CString section, const CString iname, const int ival )
{
	WriteString( section, iname, IntToStr( ival ) );
}


/*=============================================================================
*NAME		:TYSIniFile::WritePoint
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:座標構造体書き込み処理関数です
			:
*PROCESS	:・座標構造体書き込み処理です。
			:
*INPUT		:const CString section		:セクション名
*INPUT		:const CString iname		:Ident名
*INPUT		:const CPoint& point		:座標構造体
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WritePoint( const CString section, const CString iname, const CPoint& point )
{
	WriteInteger( section, iname + XIdent, point.x );											// 2003.02.12 Y.Sasai Ver.0.90 ｘ座標書き込み
	WriteInteger( section, iname + YIdent, point.y );											// 2003.02.12 Y.Sasai Ver.0.90 ｙ座標書き込み
}


/*=============================================================================
*NAME		:TYSIniFile::WriteRect
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:四角形構造体書き込み処理関数です
			:
*PROCESS	:・四角形構造体書き込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const CRect& rect		:座標構造体
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteRect( const CString section, const CString iname, const CRect& rect )
{
	CRect rc = rect;																			// 2003.02.12 Y.Sasai Ver.0.90 四角形取得

	rc.NormalizeRect();																			// 2003.02.12 Y.Sasai Ver.0.90 四角形の正規化
	WriteInteger( section, iname + LeftIdent, rc.left );										// 2003.02.12 Y.Sasai Ver.0.90 左座標書き込み
	WriteInteger( section, iname + TopIdent, rc.top );											// 2003.02.12 Y.Sasai Ver.0.90 上座標書き込み
	WriteInteger( section, iname + RightIdent, rc.right );										// 2003.02.12 Y.Sasai Ver.0.90 右座標書き込み
	WriteInteger( section, iname + BottomIdent, rc.bottom );									// 2003.02.12 Y.Sasai Ver.0.90 下座標書き込み
}


/*=============================================================================
*NAME		:TYSIniFile::WriteString
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:文字列値書き込み処理関数です
			:
*PROCESS	:・文字列値書き込み処理です。
			:
*INPUT		:const CString section	:セクション名
*INPUT		:const CString iname	:Ident名
*INPUT		:const CString ival		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteString( const CString section, const CString iname, const CString ival )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 セクション位置取得
	TYSIniSection* ysection;																	// 2003.02.10 Y.Sasai Ver.0.90 セクションクラス

	if ( spos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 なかったら…
		ysection = Add();																		// 2003.02.10 Y.Sasai Ver.0.90 追加だ
		ysection->Name = section;																// 2003.02.10 Y.Sasai Ver.0.90 セクション名設定
		ysection->Value[iname] = ival;															// 2003.02.10 Y.Sasai Ver.0.90 設定だ
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 あったら…
		ysection = Items[spos];																	// 2003.02.10 Y.Sasai Ver.0.90 セクションクラス取得
		ysection->Value[iname] = ival;															// 2003.02.10 Y.Sasai Ver.0.90 設定だ
	}
}


/*=============================================================================
*NAME		:TYSIniFile::WriteStringList
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:文字列リスト書き込み処理関数です
			:
*PROCESS	:・文字列リストの書き込みです。
			:
*INPUT		:const CString section		:セクション名
*INPUT		:const CString iname		:Ident名
*INPUT		:const TStringList& slist	:内容
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::WriteStringList( const CString section, const CString iname, TStringList& slist )
{
	CString ident;
	int tempi;

	for ( tempi = 0; true; tempi++ ) {
		ident = iname + Number[tempi];															// 2003.02.13 Y.Sasai Ver.0.00 Ident名作成
		if ( tempi < slist.Count ) {															// 2003.02.13 Y.Sasai Ver.0.00 文字列リスト行数内なら…
			WriteString( section, iname + Number[tempi], slist[tempi] );						// 2003.02.13 Y.Sasai Ver.0.90 文字列書き込み
		} else {																				// 2003.02.13 Y.Sasai Ver.0.00 行数を超えたら…
			if ( ValueExists( section, ident ) == false ) {										// 2003.02.13 Y.Sasai Ver.0.90 Ident名がなかったら…
				break;																			// 2003.02.13 Y.Sasai Ver.0.00 ぬけるぞ
			}
			DeleteKey( section, ident );														// 2003.02.13 Y.Sasai Ver.0.00 削除だ
		}
	}
}


/*=============================================================================
*NAME		:TYSIniFile::NumberGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:数値文字列取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 初期作成
*/
CString TYSIniFile::NumberGet( const int a1 )
{
	CString result;
	char nbuf[16];

	sprintf( nbuf, "%05d", a1 );																// 2003.02.13 Y.Sasai Ver.0.90 文字列作成
	result = nbuf;																				// 2003.02.13 Y.Sasai Ver.0.90 内容設定

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 それを返す
}


/*=============================================================================
*NAME		:TYSIniFile::FileNameGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:ファイル名取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString TYSIniFile::FileNameGet( void )
{
	return ( FFileName );
}


/*=============================================================================
*NAME		:TYSIniFile::FileNameSet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:ファイル名設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::FileNameSet( const CString p1 )
{
	FFileName = p1;																				// 2003.02.10 Y.Sasai Ver.0.90 設定だ
}


/*=============================================================================
*NAME		:TYSIniFile::ItemsGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:アイテムズ取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
TYSIniSection* TYSIniFile::ItemsGet( const int a1 )
{
	TYSIniSection* result = (TYSIniSection*)GetAt( FindIndex( a1 ) );							// 2003.02.10 Y.Sasai Ver.0.90 これだ
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 これだ
}


/*=============================================================================
*NAME		:TYSIniFile::ItemsSet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:アイテムズ設定処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
void TYSIniFile::ItemsSet( const int a1, TYSIniSection* p1 )
{
	TYSIniSection* ysection = (TYSIniSection*)GetAt( FindIndex( a1 ) );							// 2003.02.10 Y.Sasai Ver.0.90 これだ

	ysection->Assign( p1 );																		// 2003.02.10 Y.Sasai Ver.0.90 内容コピーだ
}


// ===========================================
//		関数定義終了
// ===========================================
