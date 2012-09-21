
// SkiaTestDlg.h : ͷ�ļ�
//

#pragma once


// CSkiaTestDlg �Ի���
class SkCanvas;
class SkBitmap;
class CSkiaTestDlg : public CDialogEx
{
// ����
public:
	CSkiaTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CSkiaTestDlg();

// �Ի�������
	enum { IDD = IDD_SKIATEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	SkCanvas* m_pCanvas;
	SkBitmap* m_pBitmap;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBntDraw();
	afx_msg void OnBnClickedBtnOut();
	afx_msg void OnSelchangeCombo();
};
