// ===========================================================
//		YS���C�u����
//
//				2003.02.12 Ver.1.0 ������		�����쐬
// ===========================================================


#if !defined( YSLibH_)
#define YSLibH


// ===========================================
//		�C���N���[�h�E�t�@�C��
// ===========================================
#include <afxcoll.h>
#include <Afxtempl.h>


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
bool DirectoryExists( const CString );															// 2003.02.13 Y.Sasai Ver.0.00 �f�B���N�g�����݃`�F�b�N����
bool FileExists( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 �t�@�C�����݃`�F�b�N����
CString FloatToStr( const double );																// 2003.02.10 Y.Sasai Ver.0.90 double��������ϊ�����
CString IntToStr( const int );																	// 2003.02.10 Y.Sasai Ver.0.90 int��������ϊ�����
double StrToFloat( const CString );																// 2003.02.10 Y.Sasai Ver.0.90 ������double�ϊ�����
int StrToInt( const CString );																	// 2003.02.10 Y.Sasai Ver.0.90 ������int�ϊ�����
CString ExeNameGet( void );																		// 2003.02.19 Y.Sasai Ver.0.90 �A�v���P�[�V�����t���p�X�擾����
int ApplicationYearGet( void );																	// 2003.02.19 Y.Sasai Ver.0.90 �A�v���P�[�V�����N�擾����
CString CopyrightStringGet( const int );														// 2003.02.19 Y.Sasai Ver.0.90 ���쌠������擾����
void MinMaxCheck( const int, int&, const int );													// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const short, short&, const short );											// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const char, char&, const char );												// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const unsigned int, unsigned int&, const unsigned int );						// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const unsigned short, unsigned short&, const unsigned short );				// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const unsigned char, unsigned char&, const unsigned char );					// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const __int64, __int64&, const __int64 );										// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const double, double&, const double );										// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const float, float&, const float );											// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����
void MinMaxCheck( const long double, long double&, const long double );							// 2003.02.19 Y.Sasai Ver.0.90 �ŏ��l�E�ő�l�`�F�b�N����


// ===========================================
//		�֐���`�I��
// ===========================================
#endif
