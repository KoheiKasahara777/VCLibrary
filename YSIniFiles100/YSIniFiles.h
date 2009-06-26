// ===========================================================
//		YSIniFiles�N���X
//
//				2003.02.10 Ver.1.0 ������		�����쐬
// ===========================================================


#if !defined( YSIniFilesH_)
#define YSIniFilesH


// ===========================================
//		�C���N���[�h�E�t�@�C��
// ===========================================
#include <Afxtempl.h>
#include <Afxwin.h>
#include <afxcoll.h>
#include "StringList.h"


// ===========================================
//		�}�N����`
// ===========================================
#define	XIdent			"__X"																	// 2003.02.12 Y.Sasai Ver.0.90 �����W�pIdent��
#define	YIdent			"__Y"																	// 2003.02.12 Y.Sasai Ver.0.90 �����W�pIdent��
#define	LeftIdent		"Left"																	// 2003.02.12 Y.Sasai Ver.0.90 �����W�pIdent��
#define	TopIdent		"Top"																	// 2003.02.12 Y.Sasai Ver.0.90 ����W�pIdent��
#define	RightIdent		"Right"																	// 2003.02.12 Y.Sasai Ver.0.90 �E���W�pIdent��
#define	BottomIdent		"Bottom"																// 2003.02.12 Y.Sasai Ver.0.90 �����W�pIdent��
#define	WidthIdent		"Width"																	// 2003.02.12 Y.Sasai Ver.0.90 �����pIdent��
#define	HeightIdent		"Height"																// 2003.02.12 Y.Sasai Ver.0.90 �����pIdent��


// ===========================================
//		���l��`
// ===========================================


// ===========================================
//		�\���̐錾
// ===========================================


// ===========================================
//		�N���X�錾
// ===========================================
class TYSIniSection : public TStringList														// 2003.02.10 Y.Sasai Ver.0.90 Ini�Z�N�V�����N���X
{
private:
// �v���p�e�B�g�p�ϐ�
	CString FName;																				// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V������
protected:
public:
// �O���g�p�\�֐�
	virtual void Assign( TYSIniSection* );														// 2003.02.10 Y.Sasai Ver.0.90 ���e�R�s�[����
	virtual int Add( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y�ǉ�����
// �v���p�e�B�g�p�֐�
	CString NameGet( void );																	// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������擾����
	void NameSet( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������ݒ菈��

// �O���g�p�\�v���p�e�B
	__declspec( property( get = NameGet, put = NameSet ) ) CString Name;						// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V������
};


class TYSIniFile : public CObList																// 2003.02.10 Y.Sasai Ver.0.90 Ini�t�@�C���N���X
{
private:
// �v���p�e�B�g�p�ϐ�
	CString FFileName;																			// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C����

// �����g�p�֐�
	bool SectionCheck( CString );																// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����`�F�b�N����
	CString SectionNameGet( const CString );													// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������擾����
	void WriteSub( TStringList*, TYSIniSection* );												// 2003.02.10 Y.Sasai Ver.0.90 �������݃T�u����
// �v���p�e�B�g�p�֐�
	CString NumberGet( const int );																// 2003.02.13 Y.Sasai Ver.0.90 ���l������擾����

// �����g�p�v���p�e�B
	__declspec( property( get = NumberGet ) ) CString Number[];									// 2003.02.13 Y.Sasai Ver.0.90 ���l������
protected:
public:
// �O���g�p�\�֐�
	TYSIniFile( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 �R���X�g���N�^�֐�
	virtual ~TYSIniFile( void );																// 2003.02.10 Y.Sasai Ver.0.90 �f�X�g���N�^�֐�
	bool Read( void );																			// 2003.02.10 Y.Sasai Ver.0.90 �ǂݍ��ݏ���
	bool Write( void );																			// 2003.02.10 Y.Sasai Ver.0.90 �������ݏ���
	TYSIniSection* Add( void );																	// 2003.02.10 Y.Sasai Ver.0.90 �ǉ�����
	void Delete( const int );																	// 2003.02.10 Y.Sasai Ver.0.90 �폜����
	void Assign( TYSIniFile* );																	// 2003.02.10 Y.Sasai Ver.0.90 ���e�R�s�[����
	void Clear( void );																			// 2003.02.10 Y.Sasai Ver.0.90 �S�f�[�^����������
	void DeleteKey( const CString, const CString );												// 2003.02.10 Y.Sasai Ver.0.90 �L�[�폜����
	void EraseSection( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����폜����
	bool ReadBool( const CString, const CString, const bool );									// 2003.02.10 Y.Sasai Ver.0.90 bool�l�ǂݍ��ݏ���
	double ReadFloat( const CString, const CString, const double );								// 2003.02.10 Y.Sasai Ver.0.90 double�l�ǂݍ��ݏ���
	int ReadInteger( const CString, const CString, const int );									// 2003.02.10 Y.Sasai Ver.0.90 int�l�ǂݍ��ݏ���
	CPoint ReadPoint( const CString, const CString, const CPoint* point = NULL );				// 2003.02.12 Y.Sasai Ver.0.90 ���W�\���̓ǂݍ��ݏ���
	CRect ReadRect( const CString, const CString, const CRect* rect = NULL );					// 2003.02.12 Y.Sasai Ver.0.90 �l�p�`�\���̓ǂݍ��ݏ���
	CString ReadString( const CString, const CString, const CString );							// 2003.02.10 Y.Sasai Ver.0.90 ������l�ǂݍ��ݏ���
	int ReadStringList( const CString, const CString, TStringList& );							// 2003.02.13 Y.Sasai Ver.0.90 �����񃊃X�g�ǂݍ��ݏ���
	int SectionIndex( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�����ʒu�擾����
	bool SectionExists( const CString );														// 2003.02.10 Y.Sasai Ver.0.90 �Z�N�V�������݃`�F�b�N����
	bool UpdateFile( void );																	// 2003.02.10 Y.Sasai Ver.0.90 �f�[�^�������ݏ���
	bool ValueExists( const CString, const CString );											// 2003.02.10 Y.Sasai Ver.0.90 �L�[���݃`�F�b�N
	void WriteBool( const CString, const CString, const bool );									// 2003.02.10 Y.Sasai Ver.0.90 bool�l�������ݏ���
	void WriteFloat( const CString, const CString, const double );								// 2003.02.10 Y.Sasai Ver.0.90 double�l�������ݏ���
	void WriteInteger( const CString, const CString, const int );								// 2003.02.10 Y.Sasai Ver.0.90 int�l�������ݏ���
	void WritePoint( const CString, const CString, const CPoint& );								// 2003.02.12 Y.Sasai Ver.0.90 ���W�\���̏������ݏ���
	void WriteRect( const CString, const CString, const CRect& );								// 2003.02.12 Y.Sasai Ver.0.90 �l�p�`�\���̏������ݏ���
	void WriteString( const CString, const CString, const CString );							// 2003.02.10 Y.Sasai Ver.0.90 ������l�������ݏ���
	void WriteStringList( const CString, const CString, TStringList& );							// 2003.02.13 Y.Sasai Ver.0.90 �����񃊃X�g�������ݏ���
// �v���p�e�B�g�p�֐�
	CString FileNameGet( void );																// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C�����擾����
	void FileNameSet( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C�����ݒ菈��
	TYSIniSection* ItemsGet( const int );														// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y�擾����
	TYSIniSection* operator[]( int a1 ) {														// 2002.12.11 Y.Sasai Ver.1.0.1.10 �I�y���[�^
		return ( Items[a1] );
	}
	void ItemsSet( const int, TYSIniSection* );													// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y�ݒ菈��

// �O���g�p�\�v���p�e�B
	__declspec( property( get = FileNameGet, put = FileNameSet ) ) CString FileName;			// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C����
	__declspec( property( get = ItemsGet, put = ItemsSet ) ) TYSIniSection* Items[];			// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y
	__declspec( property( get = GetCount ) ) int Count;											// 2003.02.10 Y.Sasai Ver.0.90 �v�f��
};


// ===========================================
//		�ϐ���`
// ===========================================


// ===========================================
//		�֐���`
// ===========================================


// ===========================================
//		�֐���`�I��
// ===========================================
#endif
