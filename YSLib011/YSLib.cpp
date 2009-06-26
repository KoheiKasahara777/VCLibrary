// ===========================================================
//		YS���C�u����
//
//				2003.02.12 Ver.1.0 ������		�����쐬
// ===========================================================


// ===========================================
//		�C���N���[�h�E�t�@�C��
// ===========================================
#include "stdafx.h"
#include "YSLib.h"
#include <io.h>
#include <AFXWIN.H>


// ===========================================
//		�}�N����`
// ===========================================


// ===========================================
//		���l��`
// ===========================================


// ===========================================
//		�\���̐錾
// ===========================================


// ===========================================
//		�N���X�錾
// ===========================================


// ===========================================
//		�ϐ���`
// ===========================================


// ===========================================
//		�֐���`
// ===========================================


/*=============================================================================

 *NAME		:DirectoryExists
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�f�B���N�g�����݃`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�f�B���N�g�����݃`�F�b�N�����ł��B
			:
*INPUT		:const CString fname	:�f�B���N�g����
			:
*RETURN		: true = �����
			:false = �Ȃ���
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool DirectoryExists( const CString dname )
{
	WIN32_FIND_DATA fdata;
	HANDLE hfile = FindFirstFile( dname, &fdata );												// 2002.11.26 Y.Sasai Ver.0.90 �f�B���N�g������
	bool result = true;

	if ( hfile == INVALID_HANDLE_VALUE ) {														// 2002.11.26 Y.Sasai Ver.0.90 �݂���Ȃ�������c
		return ( false );																		// 2002.11.26 Y.Sasai Ver.0.90 ����肾
	}
	result = ( ( fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) != 0 );					// 2003.02.13 Y.Sasai Ver.0.00 �f�B���N�g���Ȃ�true
	FindClose( hfile );																			// 2002.11.26 Y.Sasai Ver.0.90 �t�@�C�������̃N���[�Y

	return ( result );																			// 2002.11.26 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:FileExists
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�t�@�C�����݃`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�t�@�C�����݃`�F�b�N�����ł��B
			:
*INPUT		:const CString fname	:�t�@�C����
			:
*RETURN		: true = �����
			:false = �Ȃ���
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool FileExists( const CString fname )
{
	WIN32_FIND_DATA fdata;
	HANDLE hfile = FindFirstFile( fname, &fdata );												// 2002.11.26 Y.Sasai Ver.0.90 �t�@�C������
	bool result = true;

	if ( hfile == INVALID_HANDLE_VALUE ) {														// 2002.11.26 Y.Sasai Ver.0.90 �݂���Ȃ�������c
		return ( false );																		// 2002.11.26 Y.Sasai Ver.0.90 ����肾
	}
	result = ( ( fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) == 0 );					// 2003.02.13 Y.Sasai Ver.0.00 �t�@�C���Ȃ�true
	FindClose( hfile );																			// 2002.11.26 Y.Sasai Ver.0.90 �t�@�C�������̃N���[�Y

	return ( result );																			// 2002.11.26 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:FloatToStr
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:double��������ϊ������֐��ł�
			:
*PROCESS	:�Edouble��������ϊ������ł��B
			:
*INPUT		:const double val	:���l
			:
*RETURN		:������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:int��������ϊ������֐��ł�
			:
*PROCESS	:�Eint��������ϊ������ł��B
			:
*INPUT		:const int val	:���l
			:
*RETURN		:������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:������double�ϊ������֐��ł�
			:
*PROCESS	:�E������double�ϊ������ł��B
			:
*INPUT		:const CString val	:������
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:������int�ϊ������֐��ł�
			:
*PROCESS	:�E������int�ϊ������ł��B
			:
*INPUT		:const CString val	:������
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:�A�v���P�[�V�������擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.01.31 Y.Sasai Ver.0.90 �����쐬
*/
CString ExeNameGet( void )
{
	char path[MAX_PATH+1];

	if ( GetModuleFileName( AfxGetInstanceHandle(), path, sizeof( path ) - 1 ) == 0 ) {			// 2003.02.19 Y.Sasai Ver.0.90 �t�@�C�����擾�ł��Ȃ�������c
		return ( "" );																			// 2003.02.19 Y.Sasai Ver.0.90 �󗓂�
	}

	return ( path );
}


/*=============================================================================
*NAME		:ApplicationYearGet
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�A�v���P�[�V�����N�擾�����֐��ł�
			:
*PROCESS	:�E�A�v���P�[�V�����N�擾�����ł��B
			:
*RETURN		:�A�v���P�[�V�����̔N
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
int ApplicationYearGet( void )
{
	_finddata_t fdata;																			// 2003.01.31 Y.Sasai Ver.0.90 �t�@�C�������f�[�^�\����
	int result;
	struct tm tinf;																				// 2003.01.31 Y.Sasai Ver.0.90 ���ԍ\����
	int hfile = _findfirst( ExeNameGet(), &fdata );												// 2003.01.31 Y.Sasai Ver.0.90 �t�@�C������

	if ( hfile >= 0 ) {																			// 2003.01.31 Y.Sasai Ver.0.90 �݂�������c
		_findclose( hfile );																	// 2003.01.31 Y.Sasai Ver.0.90 �t�@�C�������̃N���[�Y
	} else {																					// 2003.01.31 Y.Sasai Ver.0.90 �݂���Ȃ�������c
		time( &fdata.time_create );																// 2003.01.31 Y.Sasai Ver.0.90 ���݂̎����Ƃ���
	}
	tinf = *gmtime( &fdata.time_create );														// 2003.01.31 Y.Sasai Ver.0.90 �t�@�C���쐬���Ԃ��擾
	result = 1900 + tinf.tm_year;																// 2003.01.31 Y.Sasai Ver.0.90 �N�擾

	return ( result );																			// 2003.01.31 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:CopyrightStringGet
			:
*MODULE		:MainFrm.cpp
			:
*FUNCTION	:���쌠������擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.01.31 Y.Sasai Ver.0.90 �����쐬
*/
CString CopyrightStringGet( const int startyear )
{
	const int nowyear = ApplicationYearGet();													// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK ���݂̔N
	CString result = "Copyright(c) ";															// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK ��������
	CString year;

	if ( startyear >= nowyear ) {																// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK �����N�Ȃ�c
		year.Format( "%d", startyear );
	} else {																					// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK �������Ȃ�c
		year.Format( "%d-%d", startyear, nowyear );
	}
	result = result + year + " OHT Inc.";

	return ( result );																			// 2003.01.31 Y.Sasai Ver.1.13-SU-NOK ����肾
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const int min, int& value, const int max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const short min, short& value, const short max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const char min, char& value, const char max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const unsigned int min, unsigned int& value, const unsigned int max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const unsigned short min, unsigned short& value, const unsigned short max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const unsigned char min, unsigned char& value, const unsigned char max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const __int64 min, __int64& value, const __int64 max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const double min, double& value, const double max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const float min, float& value, const float max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


/*=============================================================================
*NAME		:MinMaxCheck
			:
*MODULE		:YSLib.cpp
			:
*FUNCTION	:�ŏ��l�E�ő�l�`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�͈͊O�̏ꍇ�͔͈͓��ɂ����߂܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.19 Y.Sasai Ver.0.90 �����쐬
*/
void MinMaxCheck( const long double min, long double& value, const long double max )
{
	if ( value < min ) {																		// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l�����Ȃ�c
		value = min;																			// 2002.12.05 Y.Sasai Ver.0.90 �ŏ��l��
	} else if ( max < value ) {																	// 2002.12.05 Y.Sasai Ver.0.90 �ő�l�𒴂�����c
		value = max;																			// 2002.12.05 Y.Sasai Ver.0.90 �ő�l��
	}
}


// ===========================================
//		�֐���`�I��
// ===========================================
