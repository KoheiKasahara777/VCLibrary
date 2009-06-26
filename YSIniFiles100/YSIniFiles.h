// ===========================================================
//		YSIniFilesクラス
//
//				2003.02.10 Ver.1.0 ささい		初期作成
// ===========================================================


#if !defined( YSIniFilesH_)
#define YSIniFilesH


// ===========================================
//		インクルード・ファイル
// ===========================================
#include <Afxtempl.h>
#include <Afxwin.h>
#include <afxcoll.h>
#include "StringList.h"


// ===========================================
//		マクロ定義
// ===========================================
#define	XIdent			"__X"																	// 2003.02.12 Y.Sasai Ver.0.90 ｘ座標用Ident名
#define	YIdent			"__Y"																	// 2003.02.12 Y.Sasai Ver.0.90 ｙ座標用Ident名
#define	LeftIdent		"Left"																	// 2003.02.12 Y.Sasai Ver.0.90 左座標用Ident名
#define	TopIdent		"Top"																	// 2003.02.12 Y.Sasai Ver.0.90 上座標用Ident名
#define	RightIdent		"Right"																	// 2003.02.12 Y.Sasai Ver.0.90 右座標用Ident名
#define	BottomIdent		"Bottom"																// 2003.02.12 Y.Sasai Ver.0.90 下座標用Ident名
#define	WidthIdent		"Width"																	// 2003.02.12 Y.Sasai Ver.0.90 横幅用Ident名
#define	HeightIdent		"Height"																// 2003.02.12 Y.Sasai Ver.0.90 高さ用Ident名


// ===========================================
//		数値定義
// ===========================================


// ===========================================
//		構造体宣言
// ===========================================


// ===========================================
//		クラス宣言
// ===========================================
class TYSIniSection : public TStringList														// 2003.02.10 Y.Sasai Ver.0.90 Iniセクションクラス
{
private:
// プロパティ使用変数
	CString FName;																				// 2003.02.10 Y.Sasai Ver.0.90 セクション名
protected:
public:
// 外部使用可能関数
	virtual void Assign( TYSIniSection* );														// 2003.02.10 Y.Sasai Ver.0.90 内容コピー処理
	virtual int Add( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ追加処理
// プロパティ使用関数
	CString NameGet( void );																	// 2003.02.10 Y.Sasai Ver.0.90 セクション名取得処理
	void NameSet( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 セクション名設定処理

// 外部使用可能プロパティ
	__declspec( property( get = NameGet, put = NameSet ) ) CString Name;						// 2003.02.10 Y.Sasai Ver.0.90 セクション名
};


class TYSIniFile : public CObList																// 2003.02.10 Y.Sasai Ver.0.90 Iniファイルクラス
{
private:
// プロパティ使用変数
	CString FFileName;																			// 2003.02.10 Y.Sasai Ver.0.90 ファイル名

// 内部使用関数
	bool SectionCheck( CString );																// 2003.02.10 Y.Sasai Ver.0.90 セクションチェック処理
	CString SectionNameGet( const CString );													// 2003.02.10 Y.Sasai Ver.0.90 セクション名取得処理
	void WriteSub( TStringList*, TYSIniSection* );												// 2003.02.10 Y.Sasai Ver.0.90 書き込みサブ処理
// プロパティ使用関数
	CString NumberGet( const int );																// 2003.02.13 Y.Sasai Ver.0.90 数値文字列取得処理

// 内部使用プロパティ
	__declspec( property( get = NumberGet ) ) CString Number[];									// 2003.02.13 Y.Sasai Ver.0.90 数値文字列
protected:
public:
// 外部使用可能関数
	TYSIniFile( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 コンストラクタ関数
	virtual ~TYSIniFile( void );																// 2003.02.10 Y.Sasai Ver.0.90 デストラクタ関数
	bool Read( void );																			// 2003.02.10 Y.Sasai Ver.0.90 読み込み処理
	bool Write( void );																			// 2003.02.10 Y.Sasai Ver.0.90 書き込み処理
	TYSIniSection* Add( void );																	// 2003.02.10 Y.Sasai Ver.0.90 追加処理
	void Delete( const int );																	// 2003.02.10 Y.Sasai Ver.0.90 削除処理
	void Assign( TYSIniFile* );																	// 2003.02.10 Y.Sasai Ver.0.90 内容コピー処理
	void Clear( void );																			// 2003.02.10 Y.Sasai Ver.0.90 全データ初期化処理
	void DeleteKey( const CString, const CString );												// 2003.02.10 Y.Sasai Ver.0.90 キー削除処理
	void EraseSection( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 セクション削除処理
	bool ReadBool( const CString, const CString, const bool );									// 2003.02.10 Y.Sasai Ver.0.90 bool値読み込み処理
	double ReadFloat( const CString, const CString, const double );								// 2003.02.10 Y.Sasai Ver.0.90 double値読み込み処理
	int ReadInteger( const CString, const CString, const int );									// 2003.02.10 Y.Sasai Ver.0.90 int値読み込み処理
	CPoint ReadPoint( const CString, const CString, const CPoint* point = NULL );				// 2003.02.12 Y.Sasai Ver.0.90 座標構造体読み込み処理
	CRect ReadRect( const CString, const CString, const CRect* rect = NULL );					// 2003.02.12 Y.Sasai Ver.0.90 四角形構造体読み込み処理
	CString ReadString( const CString, const CString, const CString );							// 2003.02.10 Y.Sasai Ver.0.90 文字列値読み込み処理
	int ReadStringList( const CString, const CString, TStringList& );							// 2003.02.13 Y.Sasai Ver.0.90 文字列リスト読み込み処理
	int SectionIndex( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 セクション位置取得処理
	bool SectionExists( const CString );														// 2003.02.10 Y.Sasai Ver.0.90 セクション存在チェック処理
	bool UpdateFile( void );																	// 2003.02.10 Y.Sasai Ver.0.90 データ書き込み処理
	bool ValueExists( const CString, const CString );											// 2003.02.10 Y.Sasai Ver.0.90 キー存在チェック
	void WriteBool( const CString, const CString, const bool );									// 2003.02.10 Y.Sasai Ver.0.90 bool値書き込み処理
	void WriteFloat( const CString, const CString, const double );								// 2003.02.10 Y.Sasai Ver.0.90 double値書き込み処理
	void WriteInteger( const CString, const CString, const int );								// 2003.02.10 Y.Sasai Ver.0.90 int値書き込み処理
	void WritePoint( const CString, const CString, const CPoint& );								// 2003.02.12 Y.Sasai Ver.0.90 座標構造体書き込み処理
	void WriteRect( const CString, const CString, const CRect& );								// 2003.02.12 Y.Sasai Ver.0.90 四角形構造体書き込み処理
	void WriteString( const CString, const CString, const CString );							// 2003.02.10 Y.Sasai Ver.0.90 文字列値書き込み処理
	void WriteStringList( const CString, const CString, TStringList& );							// 2003.02.13 Y.Sasai Ver.0.90 文字列リスト書き込み処理
// プロパティ使用関数
	CString FileNameGet( void );																// 2003.02.10 Y.Sasai Ver.0.90 ファイル名取得処理
	void FileNameSet( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 ファイル名設定処理
	TYSIniSection* ItemsGet( const int );														// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ取得処理
	TYSIniSection* operator[]( int a1 ) {														// 2002.12.11 Y.Sasai Ver.1.0.1.10 オペレータ
		return ( Items[a1] );
	}
	void ItemsSet( const int, TYSIniSection* );													// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ設定処理

// 外部使用可能プロパティ
	__declspec( property( get = FileNameGet, put = FileNameSet ) ) CString FileName;			// 2003.02.10 Y.Sasai Ver.0.90 ファイル名
	__declspec( property( get = ItemsGet, put = ItemsSet ) ) TYSIniSection* Items[];			// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ
	__declspec( property( get = GetCount ) ) int Count;											// 2003.02.10 Y.Sasai Ver.0.90 要素数
};


// ===========================================
//		変数定義
// ===========================================


// ===========================================
//		関数定義
// ===========================================


// ===========================================
//		関数定義終了
// ===========================================
#endif
