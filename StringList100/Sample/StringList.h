// ===========================================================
//		StringList�N���X
//
//				2003.02.12 Ver.1.0 ������		�����쐬
// ===========================================================


#if !defined( StrintListH_)
#define StrintListH


// ===========================================
//		�C���N���[�h�E�t�@�C��
// ===========================================
#include <Afxtempl.h>
#include <afxcoll.h>


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
class TStringList : public CStringList															// 2003.02.10 Y.Sasai Ver.0.90 �����񃊃X�g�N���X
{
private:
// �����g�p�֐�
	int IdentIndex( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 Ident�ʒu�擾����
	CString BeforeEqual( const CString );														// 2003.02.10 Y.Sasai Ver.0.90 �C�R�[���������O�̕�����擾����
	CString AfterEqual( const CString );														// 2003.02.10 Y.Sasai Ver.0.90 �C�R�[��������肠�Ƃ̕�����擾����
	bool LineGet( CString&, CString& );															// 2003.02.13 Y.Sasai Ver.0.90 �P�s�擾����
protected:
public:
// �O���g�p�\�֐�
	virtual void Assign( TStringList* );														// 2003.02.10 Y.Sasai Ver.0.90 ���e�R�s�[����
	bool KeyExists( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �L�[�����݃`�F�b�N����
	bool IdentExists( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 Ident�����݃`�F�b�N����
	void DeleteValue( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �l�폜����
	virtual int Add( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y�ǉ�����
	void Delete( const int );																	// 2003.02.10 Y.Sasai Ver.0.90 �폜����
	void Clear( void );																			// 2003.02.10 Y.Sasai Ver.0.90 �S��������
	bool LoadFromFile( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C������ǂݍ��ݏ���
	bool SaveToFile( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C���ɏ������ݏ���
// �v���p�e�B�g�p�֐�
	CString ItemsGet( const int );																// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y�擾����
	CString operator[]( int a1 ) {																// 2002.12.11 Y.Sasai Ver.1.0.1.10 �I�y���[�^
		return ( Items[a1] );
	}
	void ItemsSet( const int, const CString );													// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y�ݒ菈��
	CString IdentGet( const int );																// 2003.02.10 Y.Sasai Ver.0.90 Ident���擾����
	void IdentSet( const int, const CString );													// 2003.02.10 Y.Sasai Ver.0.90 Ident���ݒ菈��
	CString ValueGet( const CString );															// 2003.02.10 Y.Sasai Ver.0.90 �l�擾����
	void ValueSet( const CString, const CString );												// 2003.02.10 Y.Sasai Ver.0.90 �l�ݒ菈��
	int CountGet( void );																		// 2003.02.10 Y.Sasai Ver.0.90 �v�f���擾����
	CString TextGet( void );																	// 2003.02.13 Y.Sasai Ver.0.90 �e�L�X�g�擾����
	void TextSet( CString );																	// 2003.02.13 Y.Sasai Ver.0.90 �e�L�X�g�ݒ菈��

// �O���g�p�\�v���p�e�B
	__declspec( property( get = ItemsGet, put = ItemsSet ) ) CString Items[];					// 2003.02.10 Y.Sasai Ver.0.90 �A�C�e���Y
	__declspec( property( get = IdentGet, put = IdentSet ) ) CString Key[];						// 2003.02.10 Y.Sasai Ver.0.90 �L�[��
	__declspec( property( get = IdentGet, put = IdentSet ) ) CString Ident[];					// 2003.02.10 Y.Sasai Ver.0.90 Ident��
	__declspec( property( get = ValueGet, put = ValueSet ) ) CString Value[];					// 2003.02.10 Y.Sasai Ver.0.90 �l
	__declspec( property( get = CountGet ) ) int Count;											// 2003.02.10 Y.Sasai Ver.0.90 �v�f��
	__declspec( property( get = TextGet, put = TextSet ) ) CString Text;						// 2003.02.13 Y.Sasai Ver.0.90 �e�L�X�g
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
