// ===========================================================
//		StringListクラス
//
//				2003.02.12 Ver.1.0 ささい		初期作成
// ===========================================================


#if !defined( StrintListH_)
#define StrintListH


// ===========================================
//		インクルード・ファイル
// ===========================================
#include <Afxtempl.h>
#include <afxcoll.h>


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
class TStringList : public CStringList															// 2003.02.10 Y.Sasai Ver.0.90 文字列リストクラス
{
private:
// 内部使用関数
	int IdentIndex( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 Ident位置取得処理
	CString BeforeEqual( const CString );														// 2003.02.10 Y.Sasai Ver.0.90 イコール文字より前の文字列取得処理
	CString AfterEqual( const CString );														// 2003.02.10 Y.Sasai Ver.0.90 イコール文字よりあとの文字列取得処理
	bool LineGet( CString&, CString& );															// 2003.02.13 Y.Sasai Ver.0.90 １行取得処理
protected:
public:
// 外部使用可能関数
	virtual void Assign( TStringList* );														// 2003.02.10 Y.Sasai Ver.0.90 内容コピー処理
	bool KeyExists( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 キー名存在チェック処理
	bool IdentExists( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 Ident名存在チェック処理
	void DeleteValue( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 値削除処理
	virtual int Add( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ追加処理
	void Delete( const int );																	// 2003.02.10 Y.Sasai Ver.0.90 削除処理
	void Clear( void );																			// 2003.02.10 Y.Sasai Ver.0.90 全消去処理
	bool LoadFromFile( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 ファイルから読み込み処理
	bool SaveToFile( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 ファイルに書き込み処理
// プロパティ使用関数
	CString ItemsGet( const int );																// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ取得処理
	CString operator[]( int a1 ) {																// 2002.12.11 Y.Sasai Ver.1.0.1.10 オペレータ
		return ( Items[a1] );
	}
	void ItemsSet( const int, const CString );													// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ設定処理
	CString IdentGet( const int );																// 2003.02.10 Y.Sasai Ver.0.90 Ident名取得処理
	void IdentSet( const int, const CString );													// 2003.02.10 Y.Sasai Ver.0.90 Ident名設定処理
	CString ValueGet( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 値取得処理
	void ValueSet( const CString, const CString );												// 2003.02.10 Y.Sasai Ver.0.90 値設定処理
	int CountGet( void );																		// 2003.02.10 Y.Sasai Ver.0.90 要素数取得処理
	CString TextGet( void );																	// 2003.02.13 Y.Sasai Ver.0.90 テキスト取得処理
	void TextSet( CString );																	// 2003.02.13 Y.Sasai Ver.0.90 テキスト設定処理

// 外部使用可能プロパティ
	__declspec( property( get = ItemsGet, put = ItemsSet ) ) CString Items[];					// 2003.02.10 Y.Sasai Ver.0.90 アイテムズ
	__declspec( property( get = IdentGet, put = IdentSet ) ) CString Key[];						// 2003.02.10 Y.Sasai Ver.0.90 キー名
	__declspec( property( get = IdentGet, put = IdentSet ) ) CString Ident[];					// 2003.02.10 Y.Sasai Ver.0.90 Ident名
	__declspec( property( get = ValueGet, put = ValueSet ) ) CString Value[];					// 2003.02.10 Y.Sasai Ver.0.90 値
	__declspec( property( get = CountGet ) ) int Count;											// 2003.02.10 Y.Sasai Ver.0.90 要素数
	__declspec( property( get = TextGet, put = TextSet ) ) CString Text;						// 2003.02.13 Y.Sasai Ver.0.90 テキスト
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
