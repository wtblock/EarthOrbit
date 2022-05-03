
// EarthOrbitView.h : interface of the CEarthOrbitView class
//

#pragma once


class CEarthOrbitView : public CScrollView
{
protected: // create from serialization only
	CEarthOrbitView();
	DECLARE_DYNCREATE(CEarthOrbitView)

// Attributes
public:
	CEarthOrbitDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CEarthOrbitView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EarthOrbitView.cpp
inline CEarthOrbitDoc* CEarthOrbitView::GetDocument() const
   { return reinterpret_cast<CEarthOrbitDoc*>(m_pDocument); }
#endif

