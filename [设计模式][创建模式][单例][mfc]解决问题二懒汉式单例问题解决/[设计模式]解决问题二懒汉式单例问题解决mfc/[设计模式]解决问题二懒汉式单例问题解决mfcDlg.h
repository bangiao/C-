
// [���ģʽ]������������ʽ����������mfcDlg.h : ͷ�ļ�
//

#pragma once


// C���ģʽ������������ʽ����������mfcDlg �Ի���
class C���ģʽ������������ʽ����������mfcDlg : public CDialogEx
{
// ����
public:
	C���ģʽ������������ʽ����������mfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
