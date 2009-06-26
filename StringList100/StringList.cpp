// ===========================================================
//		StringList�N���X
//
//				2003.02.12 Ver.1.0 ������		�����쐬
// ===========================================================


// ===========================================
//		�C���N���[�h�E�t�@�C��
// ===========================================
#include <io.h>
#include "stdafx.h"
#include "StringList.h"


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
*NAME		:TStringList::Assign
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:���e�R�s�[�����֐��ł�
			:
*PROCESS	:�E���e�R�s�[�����ł��B
			:
*INPUT		:const TStringList source	:�R�s�[���ƃN���X
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::Assign( TStringList* source )
{
	int tempi;

	Clear();																					// 2003.02.10 Y.Sasai Ver.0.90 �S����
	for ( tempi = 0; tempi < source->Count; tempi++ ) {
		Add( source->Items[tempi] );															// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
	}
}


/*=============================================================================
*NAME		:TStringList::KeyExists
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�L�[�����݃`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�L�[�����݃`�F�b�N�����ł��B
			:
*INPUT		:const CString key	:�L�[��
			:
*RETURN		: true = ����I��
			:false = �G���[�I��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TStringList::KeyExists( const CString key )
{
	return ( IdentExists( key ) );																// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ��݂�IdentExists�Ȃ񂾂�
}


/*=============================================================================
*NAME		:TStringList::IdentExists
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:Ident�����݃`�F�b�N�����֐��ł�
			:
*PROCESS	:�EIdent�����݃`�F�b�N�����ł��B
			:
*INPUT		:const CString iname
			:
*RETURN		: true = ���݂����
			:false = ���݂��Ȃ���
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TStringList::IdentExists( const CString iname )
{
	return ( IdentIndex( iname ) >= 0 );														// 2003.02.10 Y.Sasai Ver.0.90 �����true
}


/*=============================================================================
*NAME		:TStringList::IdentIndex
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:Ident�ʒu�擾�����֐��ł�
			:
*PROCESS	:�EIdent�ʒu�擾�����ł��B
			:
*INPUT		:const CString iname	:ident��
			:
*RETURN		:�ʒu
			:-1 = �݂���Ȃ�����
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
int TStringList::IdentIndex( const CString iname )
{
	int tempi;

	for ( tempi = 0; tempi < Count; tempi++ ) {
		if ( iname.CompareNoCase( Ident[tempi] ) == 0 ) {										// 2003.02.10 Y.Sasai Ver.0.90 �����Ȃ�c
			return ( tempi );																	// 2003.02.10 Y.Sasai Ver.0.90 ���ꂾ
		}
	}

	return ( -1 );																				// 2003.02.10 Y.Sasai Ver.0.90 �݂���Ȃ�������
}


/*=============================================================================
*NAME		:TStringList::DeleteValue
			:
*MODULE		:StringList.cpp
			:
*FUNCTION   :�l�폜�����֐��ł�
            :
*PROCESS    :�E�l�폜�����ł��B
			:
*INPUT		:const CString iname	:Ident��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::DeleteValue( const CString iname )
{
	const int ipos = IdentIndex( iname );														// 2003.02.10 Y.Sasai Ver.0.90 Ident���ʒu�擾

	if ( ipos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		return;																					// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	}
	Delete( ipos );																				// 2003.02.10 Y.Sasai Ver.0.90 �폜��
}


/*=============================================================================
*NAME		:TStringList::Add
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�A�C�e���Y�ǉ������֐��ł�
			:
*PROCESS	:�E�A�C�e���Y�ǉ������ł��B
			:
*INPUT		:const CString txt	:�ǉ�������
			:
*RETURN		:�ǉ������v�f�ʒu
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
int TStringList::Add( const CString txt )
{
	AddTail( txt );																				// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
	return ( Count );
}


/*=============================================================================
*NAME		:TStringList::Delete
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�폜�����֐��ł�
			:
*PROCESS	:�E�w��ʒu�̕�������폜���܂��B
			:
*INPUT		:const int index	:�C���f�b�N�X�ԍ�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::Delete( const int index )
{
	RemoveAt( FindIndex( index ) );																// 2003.02.10 Y.Sasai Ver.0.90 �폜��
}


/*=============================================================================
*NAME		:TStringList::Clear
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�S�f�[�^�폜�����֐��ł�
			:
*PROCESS	:�E�S�f�[�^�폜���܂��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::Clear( void )
{
	RemoveAll();																				// 2003.02.10 Y.Sasai Ver.0.90 �S�f�[�^�폜��
}


/*=============================================================================
*NAME		:TStringList::LoadFromFile
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�t�@�C������ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�E�t�@�C������ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString fname	:�t�@�C����
			:
*RETURN		: true = ����I��
			:false = �G���[�I��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TStringList::LoadFromFile( const CString fname )
{
	FILE* fp = fopen( fname, "rt" );															// 2003.02.10 Y.Sasai Ver.0.90 �e�L�X�g�ǂݍ��݃��[�h
	char txt[1024+1];
	bool result = true;
	int tempi;

	if ( fp == NULL ) {																			// 2003.02.10 Y.Sasai Ver.0.90 NULL�Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ��߂܂ւ�
	}
	Clear();																					// 2003.02.12 Y.Sasai Ver.0.90 �S������
	while ( true ) {
		if ( fgets( txt,  sizeof( txt ) - 1, fp ) == NULL ) {									// 2003.02.10 Y.Sasai Ver.0.90 �P�s�ǂݍ��݂����Ȃ�c
			if ( feof( fp ) == 0 ) {															// 2003.02.10 Y.Sasai Ver.0.90 �I�[�łȂ��Ȃ�c
				result = false;																	// 2003.02.10 Y.Sasai Ver.0.90 �G���[��
			}
			break;																				// 2003.02.10 Y.Sasai Ver.0.90 �ʂ��邼
		}
		for ( tempi = strlen( txt ) - 1; tempi >= 0; tempi-- ) {
			if ( txt[tempi] < ' ' ) {															// 2003.02.12 Y.Sasai Ver.0.90 ���䕶���Ȃ�c
				txt[tempi] = 0;																	// 2003.02.12 Y.Sasai Ver.0.90 �k���ɂ���
			} else {																			// 2003.02.13 Y.Sasai Ver.0.90 �ʏ핶���Ȃ�c
				break;
			}
		}
		Add( txt );																				// 2003.02.12 Y.Sasai Ver.0.90 �ǉ���
	}
	if ( fclose( fp ) != 0 ) {																	// 2003.02.10 Y.Sasai Ver.0.90 �N���[�Y�G���[�Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 �G���[��
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 �܂������ł���
}


/*=============================================================================
*NAME		:TStringList::SaveToFile
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�t�@�C���ɏ������ݏ����֐��ł�
			:
*PROCESS	:�E�t�@�C���ɏ������ݏ����ł��B
			:
*INPUT		:const CString fname	:�t�@�C����
			:
*RETURN		: true = ����I��
			:false = �G���[�I��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TStringList::SaveToFile( const CString fname )
{
	FILE* fp = fopen( fname, "wt" );															// 2003.02.10 Y.Sasai Ver.0.90 �e�L�X�g�������݃��[�h
	int tempi;
	bool result = true;
	CString txt;

	if ( fp == NULL ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �I�[�v���ł��Ȃ�������c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 �G���[��
	}
	for ( tempi = 0; tempi < Count; tempi++ ) {
		txt = Items[tempi] + "\n";																// 2003.02.12 Y.Sasai Ver.0.90 ���s�R�[�h��ǉ�����
		if ( fputs( txt, fp ) < 0 ) {															// 2003.02.10 Y.Sasai Ver.0.90 �P�s�������݃G���[�Ȃ�c
			result = false;																		// 2003.02.10 Y.Sasai Ver.0.90 �G���[��
			break;																				// 2003.02.10 Y.Sasai Ver.0.90 �ʂ��邼
		}
	}
	if ( fclose( fp ) != 0 ) {																	// 2003.02.10 Y.Sasai Ver.0.90 �N���[�Y�G���[�Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 �G���[��
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniSection::ItemsGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�A�C�e���Y�擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:�A�C�e���Y�ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:Ident���擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:Ident���ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::IdentSet( const int a1, const CString p1 )
{
	CString vtxt = AfterEqual( Items[a1] );														// 2003.02.10 Y.Sasai Ver.0.90 Value������擾
	Items[a1] = p1 + "=" + vtxt;																// 2003.02.10 Y.Sasai Ver.0.90 �V����������ݒ�
}


/*=============================================================================
*NAME		:TStringList::ValueGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�l�擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
CString TStringList::ValueGet( const CString a1 )
{
	const int ipos = IdentIndex( a1 );															// 2003.02.10 Y.Sasai Ver.0.90 Index�ԍ��擾

	if ( ipos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		return ( "" );																			// 2003.02.10 Y.Sasai Ver.0.90 �󗓂�
	}

	return ( AfterEqual( Items[ipos] ) );														// 2003.02.10 Y.Sasai Ver.0.90 Value�������Ԃ�
}


/*=============================================================================
*NAME		:TStringList::ValueSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�l�ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::ValueSet( const CString a1, const CString p1 )
{
	const int ipos = IdentIndex( a1 );															// 2003.02.10 Y.Sasai Ver.0.90 Index�ԍ��擾

	if ( ipos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		Add( a1 + "=" + p1 );																	// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		Items[ipos] = Ident[ipos] + "=" + p1;													// 2003.02.10 Y.Sasai Ver.0.90 �ݒ肾
	}
}


/*=============================================================================
*NAME		:TStringList::CountGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�v�f���擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:�C�R�[���������O�̕�����擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
CString TStringList::BeforeEqual( const CString txt )
{
	const int epos = txt.Find( '=' );															// 2003.02.10 Y.Sasai Ver.0.90 �C�R�[�������񌟍�
	CString result;

	if ( epos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		result = txt.Left( epos );																// 2003.02.10 Y.Sasai Ver.0.90 �O�̕������Ԃ�
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		result = txt;																			// 2003.02.10 Y.Sasai Ver.0.90 ���̂܂ܕԂ�
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TStringList::AfterEqual
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�C�R�[��������肠�Ƃ̕�����擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
CString TStringList::AfterEqual( const CString txt )
{
	const int epos = txt.Find( '=' );															// 2003.02.10 Y.Sasai Ver.0.90 �C�R�[�������񌟍�
	CString result;

	if ( epos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		result = txt.Mid( epos + 1 );															// 2003.02.10 Y.Sasai Ver.0.90 ������̕������Ԃ�
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		result = "";																			// 2003.02.10 Y.Sasai Ver.0.90 �󗓂�
	}

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TStringList::TextGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�e�L�X�g�擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 �����쐬
*/
CString TStringList::TextGet( void )
{
	CString result = "";																		// 2003.02.13 Y.Sasai Ver.0.90 ��������
	int tempi;

	for ( tempi = 0; tempi < Count; tempi++ ) {
		result = result + Items[tempi] + "\n";													// 2003.02.13 Y.Sasai Ver.0.90 ���ׂĂ̕������ǉ����Ă���
	}

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 ���ꂾ
}


/*=============================================================================
*NAME		:TStringList::TextSet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�e�L�X�g�ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 �����쐬
*/
void TStringList::TextSet( CString p1 )
{
	CString txt;
	int tempi = 0;
	bool lstat = true;

	Clear();																					// 2003.02.13 Y.Sasai Ver.0.90 �S��������
	while ( true ) {
		lstat = LineGet( p1, txt );																// 2003.02.13 Y.Sasai Ver.0.90 �P�s�擾
		if ( lstat == false ) {																	// 2003.02.13 Y.Sasai Ver.0.90 �����Ȃ�c
			if ( txt != "" ) {																	// 2003.02.13 Y.Sasai Ver.0.90 ��s�łȂ��Ȃ�c
				Add( txt );																		// 2003.02.13 Y.Sasai Ver.0.90 �ǉ���
			}
			break;																				// 2003.02.13 Y.Sasai Ver.0.90 �ʂ��邼
		}
		Add( txt );																				// 2003.02.13 Y.Sasai Ver.0.90 �ǉ���
	}
}


/*=============================================================================
*NAME		:TStringList::LineGet
			:
*MODULE		:StringList.cpp
			:
*FUNCTION	:�P�s�擾�����֐��ł�
			:
*PROCESS	:�E�P�s�擾�����ł��B
			:
*INPUT		:CString& source	:��������
*INPUT		:CString& txt		:�擾������
			:
*RETURN		: true = �܂������������
			:false = �Ō�܂ł�������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 �����쐬
*/
bool TStringList::LineGet( CString& source, CString& txt )
{
	const CString cr = "\n";																	// 2003.02.13 Y.Sasai Ver.0.90 ���s����
	const int crpos = source.Find( cr );														// 2003.02.13 Y.Sasai Ver.0.90 ���s����������
	const int crlen = cr.GetLength();															// 2003.02.13 Y.Sasai Ver.0.90 ���s������
	const bool result = ( crpos >= 0 );															// 2003.02.13 Y.Sasai Ver.0.90 ���s��������������true

	if ( result == true ) {																		// 2003.02.13 Y.Sasai Ver.0.90 ���s��������������c
		txt = source.Left( crpos );																// 2003.02.13 Y.Sasai Ver.0.90 ������擾
		source = source.Mid( crpos + crlen );													// 2003.02.13 Y.Sasai Ver.0.90 ���s�����ȍ~�̕�������擾
	} else {																					// 2003.02.13 Y.Sasai Ver.0.90 ���s�������Ȃ�������c
		txt = source;																			// 2003.02.13 Y.Sasai Ver.0.90 ���̂܂܃R�s�[
		source = "";																			// 2003.02.13 Y.Sasai Ver.0.90 ��s�ɂ���
	}

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 ����肾
}


// ===========================================
//		�֐���`�I��
// ===========================================
