// ===========================================================
//		YSライブラリ
//
//				2003.02.12 Ver.1.0 ささい		初期作成
// ===========================================================


#if !defined( YSLibH_)
#define YSLibH


// ===========================================
//		インクルード・ファイル
// ===========================================
#include <afxcoll.h>
#include <Afxtempl.h>


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
bool DirectoryExists( const CString );															// 2003.02.13 Y.Sasai Ver.0.00 ディレクトリ存在チェック処理
bool FileExists( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 ファイル存在チェック処理
CString FloatToStr( const double );																// 2003.02.10 Y.Sasai Ver.0.90 double→文字列変換処理
CString IntToStr( const int );																	// 2003.02.10 Y.Sasai Ver.0.90 int→文字列変換処理
double StrToFloat( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 文字列→double変換処理
int StrToInt( const CString );																	// 2003.02.10 Y.Sasai Ver.0.90 文字列→int変換処理
CString ExeNameGet( void );																		// 2003.02.19 Y.Sasai Ver.0.90 アプリケーションフルパス取得処理
int ApplicationYearGet( void );																	// 2003.02.19 Y.Sasai Ver.0.90 アプリケーション年取得処理
CString CopyrightStringGet( const int );														// 2003.02.19 Y.Sasai Ver.0.90 著作権文字列取得処理
void MinMaxCheck( const int, int&, const int );													// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const short, short&, const short );											// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const char, char&, const char );												// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const unsigned int, unsigned int&, const unsigned int );						// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const unsigned short, unsigned short&, const unsigned short );				// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const unsigned char, unsigned char&, const unsigned char );					// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const __int64, __int64&, const __int64 );										// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const double, double&, const double );										// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const float, float&, const float );											// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理
void MinMaxCheck( const long double, long double&, const long double );							// 2003.02.19 Y.Sasai Ver.0.90 最小値・最大値チェック処理


// ===========================================
//		関数定義終了
// ===========================================
#endif
