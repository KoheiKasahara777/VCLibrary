// ===========================================================
//		YSIniFiles�N���X
//
//				2003.02.10 Ver.1.0 ������		�����쐬
// ===========================================================


// ===========================================
//		�C���N���[�h�E�t�@�C��
// ===========================================
#include <io.h>
#include "stdafx.h"
#include "YSIniFiles.h"
#include "YSLib.h"


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
*NAME		:TYSIniSection::Assign
			:
*MODULE		:YSIniFiles.cpp
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
void TYSIniSection::Assign( TYSIniSection* source )
{
	FName = source->Name;																		// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������R�s�[
	TStringList::Assign( source );
}


/*=============================================================================
*NAME		:TYSIniSection::Add
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�A�C�e���Y�ǉ������֐��ł�
			:
*PROCESS	:�E�A�C�e���Y�ǉ������ł��B
			:
*INPUT		:const CString txt		:�ǉ�������
			:
*RETURN		:�ǉ������v�f�ʒu
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 �����쐬
*/
int TYSIniSection::Add( const CString txt )
{
	CString txt2 = txt;
	int result;

	txt2.TrimLeft();
	txt2.TrimRight();
	if ( txt2 != "" ) {																			// 2003.02.12 Y.Sasai Ver.0.90 �����񂪂���Ȃ�c
		result = TStringList::Add( txt );														// 2003.02.12 Y.Sasai Ver.0.90 �ǉ���
	} else {																					// 2003.02.12 Y.Sasai Ver.0.90 �����񂪂Ȃ�������c
		result = -1;																			// 2003.02.12 Y.Sasai Ver.0.90 ��������
	}

	return ( result );																			// 2003.02.12 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniSection::NameGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�Z�N�V�������擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:�Z�N�V�������ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:�R���X�g���N�^�֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
TYSIniFile::TYSIniFile( const CString fname ) : CObList( 16 )
{
	FFileName = fname;																			// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C�����ݒ�
	Read();																						// 2003.02.10 Y.Sasai Ver.0.90 �ǂݍ��݂�
}


/*=============================================================================
*NAME		:TYSIniFile::TYSIniFile
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�f�X�g���N�^�֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
TYSIniFile::~TYSIniFile( void )
{
	Clear();																					// 2003.02.10 Y.Sasai Ver.0.90 �S��������
	CObList::~CObList();																		// 2003.02.12 Y.Sasai Ver.0.90 �e�N���X�̏�����
}


/*=============================================================================
*NAME		:TYSIniFile::Read
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�EIni�t�@�C���ǂݍ��݂ł��B
			:
*RETURN		: true = ����I��
			:false = �G���[�I��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::Read( void )
{
	TStringList slist;																			// 2003.02.10 Y.Sasai Ver.0.90 �����񃊃X�g
	int tempi;
	TYSIniSection* ysection;																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����N���X
	CString sitem;

	if ( FileName == "" ) {																		// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C�������ݒ�Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 �����
	} else if ( FileExists( FileName ) == false ) {												// 2003.02.10 Y.Sasai Ver.0.90 ���̃t�@�C�����Ȃ�������c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	}

	ysection = NULL;																			// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����N���X��������
	if ( slist.LoadFromFile( FileName ) == false ) {											// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C���ǂݍ��݃G���[�Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 �G���[��
	}
	for ( tempi = 0; tempi < slist.Count; tempi++ ) {
		sitem = slist[tempi];
		if ( sitem == "" ) {																	// 2003.02.10 Y.Sasai Ver.0.90 ��s�Ȃ�c
			continue;																			// 2003.02.10 Y.Sasai Ver.0.90 ����
		}
		if ( SectionCheck( sitem ) == true ) {													// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������Ȃ�c
			ysection = Add();																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ǉ�
			ysection->Name = SectionNameGet( sitem );											// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������ݒ�
		} else if ( ysection != NULL ) {														// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ݒ肳��Ă���Ȃ�c
			ysection->Add( sitem );																// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ɒǉ�
		}
	}

	return ( true );																			// 2003.02.10 Y.Sasai Ver.0.90 �܂������ł���
}


/*=============================================================================
*NAME		:TYSIniFile::SectionCheck
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�Z�N�V�����`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�Z�N�V�����`�F�b�N�����ł��B
			:
*INPUT		:const CString txt	:�Z�N�V����������
			:
*RETURN		: true = �����
			:false = �Ȃ���
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::SectionCheck( CString txt )
{
	txt.TrimLeft();																				// 2003.02.10 Y.Sasai Ver.0.90 �O��̋󔒏���
	txt.TrimRight();
	if ( txt == "" ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �󗓂Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	}

	if ( txt[0] != '[' ) {																		// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����J�n�����łȂ��Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	} else if ( txt.Find( ']' ) <= 0 ) {														// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����I���������Ȃ��Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	}

	return ( true );																			// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V��������
}


/*=============================================================================
*NAME		:TYSIniFile::SectionNameGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�Z�N�V�������擾�����֐��ł�
			:
*PROCESS	:�E�Z�N�V�������擾�����ł��B
			:
*INPUT		:CString txt	:������
			:
*RETURN		:�Z�N�V����������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
CString TYSIniFile::SectionNameGet( CString txt )
{
	int kpos;
	CString result;

	txt.TrimLeft();																				// 2003.02.10 Y.Sasai Ver.0.90 �O��̋󔒏���
	txt.TrimRight();
	kpos = txt.Find( ']' );																		// 2003.02.10 Y.Sasai Ver.0.90 �����������ʒu�擾
	result = txt.Mid( 1, kpos - 1 );															// 2003.02.10 Y.Sasai Ver.0.90 ������擾��

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::Write
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�������ݏ����֐��ł�
			:
*PROCESS	:�EIni�t�@�C���������ݏ����ł��B
			:
*RETURN		: true = ����I��
			:false = �G���[�I��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::Write( void )
{
	TStringList slist;																			// 2003.02.10 Y.Sasai Ver.0.90 �����񃊃X�g�N���X
	int tempi;																					// 2003.02.10 Y.Sasai Ver.0.90 ��Ɨp�ϐ�

	if ( FileName == "" ) {																		// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C�������ݒ�Ȃ�c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	}
	for ( tempi = 0; tempi < Count; tempi++ ) {
		WriteSub( &slist, Items[tempi] );														// 2003.02.10 Y.Sasai Ver.0.90 �������ݏ�����
		if ( tempi < ( Count - 1 ) ) {															// 2003.02.10 Y.Sasai Ver.0.90 �Ō�łȂ��Ȃ�c
			slist.Add( "" );																	// 2003.02.10 Y.Sasai Ver.0.90 ��s�ǉ���
		}
	}
	slist.SaveToFile( FileName );																// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C���ɏ�������

	return ( true );
}


/*=============================================================================
*NAME		:TYSIniFile::WriteSub
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�������݃T�u�����֐��ł�
			:
*PROCESS	:�E�������݃T�u�����ł��B
			:
*INPUT		:TStringList slist			:�����񃊃X�g�N���X
*INPUT		:TYSIniSection ysection		:�Z�N�V�����N���X
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::WriteSub( TStringList* slist, TYSIniSection* ysection )
{
	int tempi;

	slist->Add( "[" + ysection->Name + "]" );													// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������ݒ�
	for ( tempi = 0; tempi < ysection->Count; tempi++ ) {
		slist->Add( ysection->Items[tempi] );													// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
	}
}


/*=============================================================================
*NAME		:TYSIniFile::Add
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�ǉ������֐��ł�
			:
*PROCESS	:�E�ǉ������ł��B
			:
*RETURN		:�ǉ��N���X
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
TYSIniSection* TYSIniFile::Add( void )
{
	TYSIniSection* result = new TYSIniSection();												// 2003.02.10 Y.Sasai Ver.0.90 �V�K�̃Z�N�V�����N���X�쐬

	AddTail( result );																			// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���

	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::Delete
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�폜�����֐��ł�
			:
*PROCESS	:�E�폜�����ł��B
			:
*INPUT		:const int index	:�C���f�b�N�X�ԍ�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::Delete( const int index )
{
	TYSIniSection* ysection = (TYSIniSection*)GetAt( FindIndex( index ) );						// 2003.02.10 Y.Sasai Ver.0.90 ini�Z�N�V�����N���X�擾

	delete( ysection );																			// 2003.02.10 Y.Sasai Ver.0.90 �j����
	RemoveAt( FindIndex( index ) );																// 2003.02.10 Y.Sasai Ver.0.90 �폜��
}


/*=============================================================================
*NAME		:TYSIniFile::Assign
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:���e�R�s�[�����֐��ł�
			:
*PROCESS	:�E���e�R�s�[�����ł��B
			:
*INPUT		:const TYSIniFile source	:�R�s�[���ƃN���X
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::Assign( TYSIniFile* source )
{
	int tempi;
	TYSIniSection* ysection;

	Clear();																					// 2003.02.10 Y.Sasai Ver.0.90 ��������
	for ( tempi = 0; tempi < source->Count; tempi++ ) {
		ysection = Add();																		// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
		ysection->Assign( source->Items[tempi] );												// 2003.02.10 Y.Sasai Ver.0.90 ���e�R�s�[
	}
}


/*=============================================================================
*NAME		:TYSIniFile::Clear
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�S�f�[�^�����������֐��ł�
			:
*PROCESS	:�E�S�f�[�^�����������ł��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::Clear( void )
{
	int tempi;

	for ( tempi = Count - 1; tempi >= 0; tempi-- ) {
		Delete( tempi );																		// 2003.02.10 Y.Sasai Ver.0.90 ���ׂč폜��
	}
}


/*=============================================================================
*NAME		:TYSIniFile::DeleteKey
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�L�[�폜�����֐��ł�
			:
*PROCESS	:�E�L�[�폜�����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::DeleteKey( const CString section, const CString iname )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ʒu�擾

	if ( spos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		Items[spos]->DeleteValue( iname );														// 2003.02.10 Y.Sasai Ver.0.90 �폜��
	}
}


/*=============================================================================
*NAME		:TYSIniFile::EraseSection
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�Z�N�V�����폜�����֐��ł�
			:
*PROCESS	:�E�Z�N�V�����폜�����ł��B
			:
*INPUT		:const CString section		:�Z�N�V������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::EraseSection( const CString section )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ʒu�擾

	if ( spos >= 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		RemoveAt( FindIndex( spos ) );															// 2003.02.10 Y.Sasai Ver.0.90 �폜��
	}
}


/*=============================================================================
*NAME		:TYSIniFile::ReadBool
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:bool�l�ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�Ebool�l�ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const bool defvalue		:�f�t�H���g�l
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::ReadBool( const CString section, const CString iname, const bool defvalue )
{
	bool result = ( ReadInteger( section, iname, (int)defvalue ) != 0 );						// 2003.02.10 Y.Sasai Ver.0.90 �ǂݍ��݂�
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::ReadFloat
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:double�l�ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�Edouble�l�ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const double defvalue	:�f�t�H���g�l
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:int�l�ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�Eint�l�ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const int defvalue		:�f�t�H���g�l
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:���W�\���̓ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�E���W�\���̓ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const CPoint* point	:���W�\���̃|�C���^
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 �����쐬
*/
CPoint TYSIniFile::ReadPoint( const CString section, const CString iname, const CPoint* point )
{
	CPoint defpoint;																			// 2003.02.12 Y.Sasai Ver.0.90 �����l
	CPoint result;																				// 2003.02.12 Y.Sasai Ver.0.90 �I���l

	if ( point != NULL ) {																		// 2003.02.12 Y.Sasai Ver.0.90 �f�t�H���g�ݒ肪����Ȃ�c
		defpoint = *point;																		// 2003.02.12 Y.Sasai Ver.0.90 ���W�ݒ�
	} else {																					// 2003.02.12 Y.Sasai Ver.0.90 �f�t�H���g���Ȃ��Ȃ�c
		defpoint.x = 0;																			// 2003.02.12 Y.Sasai Ver.0.90 ��������
		defpoint.y = 0;																			// 2003.02.12 Y.Sasai Ver.0.90 ��������
	};
	result.x = ReadInteger( section, iname + XIdent, defpoint.x );								// 2003.02.12 Y.Sasai Ver.0.90 �����W�ǂݍ���
	result.y = ReadInteger( section, iname + YIdent, defpoint.y );								// 2003.02.12 Y.Sasai Ver.0.90 �����W�ǂݍ���

	return ( result );																			// 2003.02.12 Y.Sasai Ver.0.90 ���̂܂ܕԂ�
}


/*=============================================================================
*NAME		:TYSIniFile::ReadRect
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�l�p�`�\���̓ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�E�l�p�`�\���̓ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const CRect* rect		:�l�p�`�\���̃|�C���^
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 �����쐬
*/
CRect TYSIniFile::ReadRect( const CString section, const CString iname, const CRect* rect )
{
	CRect defrect;																				// 2003.02.12 Y.Sasai Ver.0.90 �����l
	CRect result;																				// 2003.02.12 Y.Sasai Ver.0.90 �I���l

	if ( rect != NULL ) {																		// 2003.02.12 Y.Sasai Ver.0.90 �f�t�H���g�ݒ肪����Ȃ�c
		defrect = *rect;																		// 2003.02.12 Y.Sasai Ver.0.90 ���W�ݒ�
	} else {																					// 2003.02.12 Y.Sasai Ver.0.90 �f�t�H���g���Ȃ��Ȃ�c
		defrect.left = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 ��������
		defrect.top = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 ��������
		defrect.right = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 ��������
		defrect.bottom = 0;																		// 2003.02.12 Y.Sasai Ver.0.90 ��������
	}

	result.left = ReadInteger( section, iname + LeftIdent, defrect.left );						// 2003.02.12 Y.Sasai Ver.0.90 �����W�ǂݍ���
	result.top = ReadInteger( section, iname + TopIdent, defrect.top );							// 2003.02.12 Y.Sasai Ver.0.90 ����W�ǂݍ���
	result.right = ReadInteger( section, iname + RightIdent, defrect.right );					// 2003.02.12 Y.Sasai Ver.0.90 �E���W�ǂݍ���
	result.bottom = ReadInteger( section, iname + BottomIdent, defrect.bottom );				// 2003.02.12 Y.Sasai Ver.0.90 �����W�ǂݍ���
	result.NormalizeRect();																		// 2003.02.12 Y.Sasai Ver.0.90 �l�p�`�̐��K��

	return ( result );																			// 2003.02.12 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::ReadString
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:������l�ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�E������l�ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const CString defvalue	:�f�t�H���g�l
			:
*RETURN		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
CString TYSIniFile::ReadString( const CString section, const CString iname, const CString defvalue )
{
	CString result = defvalue;																	// 2003.02.10 Y.Sasai Ver.0.90 �I���l
	int spos;
	TYSIniSection* ysection;																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����N���X

	spos = SectionIndex( section );																// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ʒu�擾
	if ( spos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		ysection = Add();																		// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
		ysection->Name = section;																// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������ݒ�
		ysection->Value[iname] = defvalue;														// 2003.02.10 Y.Sasai Ver.0.90 �ݒ肾
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		ysection = Items[spos];																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����N���X�擾
		if ( ysection->IdentExists( iname ) == true ) {											// 2003.02.10 Y.Sasai Ver.0.90 ��������c
			result = ysection->Value[iname];													// 2003.02.10 Y.Sasai Ver.0.90 ���ꂾ
		} else {																				// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
			ysection->Value[iname] = defvalue;													// 2003.02.10 Y.Sasai Ver.0.90 �����l��
		}
	}

	return ( result );
}


/*=============================================================================
*NAME		:TYSIniFile::ReadStringList
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�����񃊃X�g�ǂݍ��ݏ����֐��ł�
			:
*PROCESS	:�E�����񃊃X�g�ǂݍ��ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:TStringList& slist		:�ݒ�N���X
			:
*RETURN		:�ǂݍ��ݍs��
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 �����쐬
*/
int TYSIniFile::ReadStringList( const CString section, const CString iname, TStringList& slist )
{
	int result = 0;																				// 2003.02.13 Y.Sasai Ver.0.90 ��������
	CString ident;
	CString txt;

	slist.Clear();																				// 2003.02.13 Y.Sasai Ver.0.90 �S������
	while ( true ) {
		ident = iname + Number[result];															// 2003.02.13 Y.Sasai Ver.0.90 Ident���쐬
		if ( ValueExists( section, ident ) == false ) {											// 2003.02.13 Y.Sasai Ver.0.90 Ident�����Ȃ�������c
			break;																				// 2003.02.13 Y.Sasai Ver.0.90 �ʂ��邼
		}
		txt = ReadString( section, ident, "" );													// 2003.02.13 Y.Sasai Ver.0.90 ������ǂݍ���
		slist.Add( txt );																		// 2003.02.13 Y.Sasai Ver.0.90 �ǉ���
		result++;																				// 2003.02.13 Y.Sasai Ver.0.00 ���Z��
	}

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::SectionIndex
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�Z�N�V�����ʒu�擾�����֐��ł�
			:
*PROCESS	:�E�Z�N�V�����ʒu�擾�����ł��B
			:
*INPUT		:const CString section	:�Z�N�V����������
			:
*RETURN		:�ʒu
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
int TYSIniFile::SectionIndex( const CString section )
{
	int tempi;

	for ( tempi = 0; tempi < Count; tempi++ ) {
		if ( section.CompareNoCase( Items[tempi]->Name ) == 0 ) {								// 2003.02.10 Y.Sasai Ver.0.90 �݂�������c
			return ( tempi );																	// 2003.02.10 Y.Sasai Ver.0.90 ���ꂾ
		}
	}

	return ( -1 );																				// 2003.02.10 Y.Sasai Ver.0.90 �݂���񂩂�����
}


/*=============================================================================
*NAME		:TYSIniFile::SectionExists
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�Z�N�V�������݃`�F�b�N�����֐��ł�
			:
*PROCESS	:�E�Z�N�V�������݃`�F�b�N�����ł��B
			:
*INPUT		:const CString section	:�Z�N�V����������
			:
*RETURN		: true = ��������
			:false = �Ȃ�������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::SectionExists( const CString section )
{
	bool result = ( SectionIndex( section ) >= 0 );												// 2003.02.10 Y.Sasai Ver.0.90 �C���f�b�N�X���݂���
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::UpdateFile
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�f�[�^�������ݏ����֐��ł�
			:
*PROCESS	:�E�f�[�^�������ݏ����ł��B
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::UpdateFile( void )
{
	bool result = Write();																		// 2003.02.10 Y.Sasai Ver.0.90 �����̏������݂Ȃ񂾂�
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ����肾
}


/*=============================================================================
*NAME		:TYSIniFile::ValueExists
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�L�[���݃`�F�b�N�֐��ł��B
			:
*PROCESS	:�E�L�[���݃`�F�b�N�ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
			:
*RETURN		: true = ��������
			:false = �Ȃ�������
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
bool TYSIniFile::ValueExists( const CString section, const CString iname )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ʒu�擾

	if ( spos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������
	} else if ( Items[spos]->IdentExists( iname ) == false ) {									// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		return ( false );																		// 2003.02.10 Y.Sasai Ver.0.90 ����肾
	}

	return ( true );																			// 2003.02.10 Y.Sasai Ver.0.90 �܂������ł���
}


/*=============================================================================
*NAME		:TYSIniFile::WriteBool
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:bool�l�������ݏ����֐��ł�
			:
*PROCESS	:�Ebool�l�������ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const bool ival		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:double�l�������ݏ����֐��ł�
			:
*PROCESS	:�Edouble�l�������ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const double ival		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:int�l�������ݏ����֐��ł�
			:
*PROCESS	:�Eint�l�������ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const int ival			:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:���W�\���̏������ݏ����֐��ł�
			:
*PROCESS	:�E���W�\���̏������ݏ����ł��B
			:
*INPUT		:const CString section		:�Z�N�V������
*INPUT		:const CString iname		:Ident��
*INPUT		:const CPoint& point		:���W�\����
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::WritePoint( const CString section, const CString iname, const CPoint& point )
{
	WriteInteger( section, iname + XIdent, point.x );											// 2003.02.12 Y.Sasai Ver.0.90 �����W��������
	WriteInteger( section, iname + YIdent, point.y );											// 2003.02.12 Y.Sasai Ver.0.90 �����W��������
}


/*=============================================================================
*NAME		:TYSIniFile::WriteRect
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�l�p�`�\���̏������ݏ����֐��ł�
			:
*PROCESS	:�E�l�p�`�\���̏������ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const CRect& rect		:���W�\����
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.12 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::WriteRect( const CString section, const CString iname, const CRect& rect )
{
	CRect rc = rect;																			// 2003.02.12 Y.Sasai Ver.0.90 �l�p�`�擾

	rc.NormalizeRect();																			// 2003.02.12 Y.Sasai Ver.0.90 �l�p�`�̐��K��
	WriteInteger( section, iname + LeftIdent, rc.left );										// 2003.02.12 Y.Sasai Ver.0.90 �����W��������
	WriteInteger( section, iname + TopIdent, rc.top );											// 2003.02.12 Y.Sasai Ver.0.90 ����W��������
	WriteInteger( section, iname + RightIdent, rc.right );										// 2003.02.12 Y.Sasai Ver.0.90 �E���W��������
	WriteInteger( section, iname + BottomIdent, rc.bottom );									// 2003.02.12 Y.Sasai Ver.0.90 �����W��������
}


/*=============================================================================
*NAME		:TYSIniFile::WriteString
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:������l�������ݏ����֐��ł�
			:
*PROCESS	:�E������l�������ݏ����ł��B
			:
*INPUT		:const CString section	:�Z�N�V������
*INPUT		:const CString iname	:Ident��
*INPUT		:const CString ival		:�l
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::WriteString( const CString section, const CString iname, const CString ival )
{
	int spos = SectionIndex( section );															// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ʒu�擾
	TYSIniSection* ysection;																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����N���X

	if ( spos < 0 ) {																			// 2003.02.10 Y.Sasai Ver.0.90 �Ȃ�������c
		ysection = Add();																		// 2003.02.10 Y.Sasai Ver.0.90 �ǉ���
		ysection->Name = section;																// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������ݒ�
		ysection->Value[iname] = ival;															// 2003.02.10 Y.Sasai Ver.0.90 �ݒ肾
	} else {																					// 2003.02.10 Y.Sasai Ver.0.90 ��������c
		ysection = Items[spos];																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����N���X�擾
		ysection->Value[iname] = ival;															// 2003.02.10 Y.Sasai Ver.0.90 �ݒ肾
	}
}


/*=============================================================================
*NAME		:TYSIniFile::WriteStringList
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�����񃊃X�g�������ݏ����֐��ł�
			:
*PROCESS	:�E�����񃊃X�g�̏������݂ł��B
			:
*INPUT		:const CString section		:�Z�N�V������
*INPUT		:const CString iname		:Ident��
*INPUT		:const TStringList& slist	:���e
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::WriteStringList( const CString section, const CString iname, TStringList& slist )
{
	CString ident;
	int tempi;

	for ( tempi = 0; true; tempi++ ) {
		ident = iname + Number[tempi];															// 2003.02.13 Y.Sasai Ver.0.00 Ident���쐬
		if ( tempi < slist.Count ) {															// 2003.02.13 Y.Sasai Ver.0.00 �����񃊃X�g�s�����Ȃ�c
			WriteString( section, iname + Number[tempi], slist[tempi] );						// 2003.02.13 Y.Sasai Ver.0.90 �����񏑂�����
		} else {																				// 2003.02.13 Y.Sasai Ver.0.00 �s���𒴂�����c
			if ( ValueExists( section, ident ) == false ) {										// 2003.02.13 Y.Sasai Ver.0.90 Ident�����Ȃ�������c
				break;																			// 2003.02.13 Y.Sasai Ver.0.00 �ʂ��邼
			}
			DeleteKey( section, ident );														// 2003.02.13 Y.Sasai Ver.0.00 �폜��
		}
	}
}


/*=============================================================================
*NAME		:TYSIniFile::NumberGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:���l������擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.13 Y.Sasai Ver.0.90 �����쐬
*/
CString TYSIniFile::NumberGet( const int a1 )
{
	CString result;
	char nbuf[16];

	sprintf( nbuf, "%05d", a1 );																// 2003.02.13 Y.Sasai Ver.0.90 ������쐬
	result = nbuf;																				// 2003.02.13 Y.Sasai Ver.0.90 ���e�ݒ�

	return ( result );																			// 2003.02.13 Y.Sasai Ver.0.90 �����Ԃ�
}


/*=============================================================================
*NAME		:TYSIniFile::FileNameGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�t�@�C�����擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
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
*FUNCTION	:�t�@�C�����ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::FileNameSet( const CString p1 )
{
	FFileName = p1;																				// 2003.02.10 Y.Sasai Ver.0.90 �ݒ肾
}


/*=============================================================================
*NAME		:TYSIniFile::ItemsGet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�A�C�e���Y�擾�����֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
TYSIniSection* TYSIniFile::ItemsGet( const int a1 )
{
	TYSIniSection* result = (TYSIniSection*)GetAt( FindIndex( a1 ) );							// 2003.02.10 Y.Sasai Ver.0.90 ���ꂾ
	return ( result );																			// 2003.02.10 Y.Sasai Ver.0.90 ���ꂾ
}


/*=============================================================================
*NAME		:TYSIniFile::ItemsSet
			:
*MODULE		:YSIniFiles.cpp
			:
*FUNCTION	:�A�C�e���Y�ݒ菈���֐��ł�
			:
*PROGRAMMED	:Y.Sasai
*HISTORY	:
*ID -- DATE ------- NOTE ------------------------------------------------------
*00 03.02.10 Y.Sasai Ver.0.90 �����쐬
*/
void TYSIniFile::ItemsSet( const int a1, TYSIniSection* p1 )
{
	TYSIniSection* ysection = (TYSIniSection*)GetAt( FindIndex( a1 ) );							// 2003.02.10 Y.Sasai Ver.0.90 ���ꂾ

	ysection->Assign( p1 );																		// 2003.02.10 Y.Sasai Ver.0.90 ���e�R�s�[��
}


// ===========================================
//		�֐���`�I��
// ===========================================
