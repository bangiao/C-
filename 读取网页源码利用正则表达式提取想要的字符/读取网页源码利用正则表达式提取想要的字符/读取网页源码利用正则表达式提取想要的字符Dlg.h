
// ��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�Dlg.h : ͷ�ļ�
//

#pragma once


// C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�Dlg �Ի���
class C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�Dlg : public CDialogEx
{
// ����
public:
	C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

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
};
