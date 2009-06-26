// ===========================================================
//		YSライブラリ
//
//				2003.02.12 Ver.1.0 ささい		初期作成
// ===========================================================


// ===========================================
//		インクルード・ファイル
// ===========================================
#include "stdafx.h"
#include "YSLib.h"
#include <io.h>
#include <AFXWIN.H>


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

 *NAME		:DirectoryExists
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:ディレクトリ存在チェック処理関数です
			:
*PROCESS	:・ディレクトリ存在チェック処理です。
			:
*INPUT		:const CString fname	:ディレクトリ名
			:
*RETURN		: true = あるよ
			:false = ないよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool DirectoryExists( const CString dname )
{
	WIN32_FIND_DATA fdata;
	HANDLE hfile = FindFirstFile( dname, &fdata );												// 2002.11.26 Y.Sasai Ver.0.90 ディレクトリ検索
	bool result = true;

	if ( hfile == INVALID_HANDLE_VALUE ) {														// 2002.11.26 Y.Sasai Ver.0.90 みつからなかったら…
		return ( false );																		// 2002.11.26 Y.Sasai Ver.0.90 おわりだ
	}
	result = ( ( fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) != 0 );					// 2003.02.13 Y.Sasai Ver.0.00 ディレクトリならtrue
	FindClose( hfile );																			// 2002.11.26 Y.Sasai Ver.0.90 ファイル検索のクローズ

	return ( result );																			// 2002.11.26 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:FileExists
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:ファイル存在チェック処理関数です
			:
*PROCESS	:・ファイル存在チェック処理です。
			:
*INPUT		:const CString fname	:ファイル名
			:
*RETURN		: true = あるよ
			:false = ないよ
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
bool FileExists( const CString fname )
{
	WIN32_FIND_DATA fdata;
	HANDLE hfile = FindFirstFile( fname, &fdata );												// 2002.11.26 Y.Sasai Ver.0.90 ファイル検索
	bool result = true;

	if ( hfile == INVALID_HANDLE_VALUE ) {														// 2002.11.26 Y.Sasai Ver.0.90 みつからなかったら…
		return ( false );																		// 2002.11.26 Y.Sasai Ver.0.90 おわりだ
	}
	result = ( ( fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) == 0 );					// 2003.02.13 Y.Sasai Ver.0.00 ファイルならtrue
	FindClose( hfile );																			// 2002.11.26 Y.Sasai Ver.0.90 ファイル検索のクローズ

	return ( result );																			// 2002.11.26 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:FloatToStr
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:double→文字列変換処理関数です
			:
*PROCESS	:・double→文字列変換処理です。
			:
*INPUT		:const double val	:数値
			:
*RETURN		:文字列
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString FloatToStr( const double val )
{
	CString result;

	result.Format( "%f", val );

	return ( result );
}


/*=============================================================================
*NAME		:IntToStr
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:int→文字列変換処理関数です
			:
*PROCESS	:・int→文字列変換処理です。
			:
*INPUT		:const int val	:数値
			:
*RETURN		:文字列
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
CString IntToStr( const int val )
{
	CString result;

	result.Format( "%d", val );

	return ( result );
}


/*=============================================================================
*NAME		:StrToFloat
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:文字列→double変換処理関数です
			:
*PROCESS	:・文字列→double変換処理です。
			:
*INPUT		:const CString val	:文字列
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
double StrToFloat( const CString val )
{
	double result = 0;

	sscanf( val, "%f", &result );

	return ( result );
}


/*=============================================================================
*NAME		:StrToInt
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:文字列→int変換処理関数です
			:
*PROCESS	:・文字列→int変換処理です。
			:
*INPUT		:const CString val	:文字列
			:
*RETURN		:値
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 初期作成
*/
int StrToInt( const CString val )
{
	int result = 0;

	sscanf( val, "%d", &result );

	return ( result );
}


/*=============================================================================
*NAME		:ExeNameGet
			:
*MODULE		:MainFrm.cpp
			:
*FUNCTION	:アプリケーション名取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.01.31 Y.Sasai Ver.0.90 初期作成
*/
CString ExeNameGet( void )
{
	char path[MAX_PATH+1];

	if ( GetModuleFileName( AfxGetInstanceHandle(), path, sizeof( path ) - 1 ) == 0 ) {			// 2003.02.19 Y.Sasai Ver.0.90 ファイル名取得できなかったら…
		return ( "" );																			// 2003.02.19 Y.Sasai Ver.0.90 空欄だ
	}

	return ( path );
}


/*=============================================================================
*NAME		:ApplicationYearGet
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:アプリケーション年取得処理関数です
			:
*PROCESS	:・アプリケーション年取得処理です。
			:
*RETURN		:アプリケーションの年
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
int ApplicationYearGet( void )
{
	_finddata_t fdata;																			// 2003.01.31 Y.Sasai Ver.0.90 ファイル検索データ構造体
	int result;
	struct tm tinf;																				// 2003.01.31 Y.Sasai Ver.0.90 時間構造体
	int hfile = _findfirst( ExeNameGet(), &fdata );												// 2003.01.31 Y.Sasai Ver.0.90 ファイル検索

	if ( hfile >= 0 ) {																			// 2003.01.31 Y.Sasai Ver.0.90 みつかったら…
		_findclose( hfile );																	// 2003.01.31 Y.Sasai Ver.0.90 ファイル検索のクローズ
	} else {																					// 2003.01.31 Y.Sasai Ver.0.90 みつからなかったら…
		time( &fdata.time_create );																// 2003.01.31 Y.Sasai Ver.0.90 現在の時刻とする
	}
	tinf = *gmtime( &fdata.time_create );														// 2003.01.31 Y.Sasai Ver.0.90 ファイル作成時間を取得
	result = 1900 + tinf.tm_year;																// 2003.01.31 Y.Sasai Ver.0.90 年取得

	return ( result );																			// 2003.01.31 Y.Sasai Ver.0.90 おわりだ
}


/*=============================================================================
*NAME		:CopyrightStringGet
			:
*MODULE		:MainFrm.cpp
			:
*FUNCTION	:著作権文字列取得処理関数です
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.01.31 Y.Sasai Ver.0.90 初期作成
*/
CString CopyrightStringGet( const int startyear )
{
	const int nowyear = ApplicationYearGet();													// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK 現在の年
	CString result = "Copyright(c) ";															// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK 初期化だ
	CString year;

	if ( startyear >= nowyear ) {																// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK 同じ年なら…
		year.Format( "%d", startyear );
	} else {																					// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK ちがうなら…
		year.Format( "%d-%d", startyear, nowyear );
	}
	result = result + year + " OHT Inc.";

	return ( result );																			// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK おわりだ
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const int min, int& value, const int max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const short min, short& value, const short max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const char min, char& value, const char max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const unsigned int min, unsigned int& value, const unsigned int max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const unsigned short min, unsigned short& value, const unsigned short max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const unsigned char min, unsigned char& value, const unsigned char max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const __int64 min, __int64& value, const __int64 max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const double min, double& value, const double max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const float min, float& value, const float max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:最小値・最大値チェック処理関数です
			:
*PROCESS	:・範囲外の場合は範囲内におさめます。
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 初期作成
*/
void MinMaxCheck( const long double min, long double& value, const long double max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 最小値未満なら…
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 最小値だ
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 最大値を超えたら…
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 最大値だ
	}
}


// ===========================================
//		関数定義終了
// ===========================================
