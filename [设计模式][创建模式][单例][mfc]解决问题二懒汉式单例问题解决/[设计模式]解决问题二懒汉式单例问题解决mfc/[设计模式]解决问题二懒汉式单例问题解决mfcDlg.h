
// [设计模式]解决问题二懒汉式单例问题解决mfcDlg.h : 头文件
//

#pragma once


// C设计模式解决问题二懒汉式单例问题解决mfcDlg 对话框
class C设计模式解决问题二懒汉式单例问题解决mfcDlg : public CDialogEx
{
// 构造
public:
	C设计模式解决问题二懒汉式单例问题解决mfcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
