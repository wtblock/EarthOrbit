
// EarthOrbitView.cpp : implementation of the CEarthOrbitView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EarthOrbit.h"
#endif

#include "EarthOrbitDoc.h"
#include "EarthOrbitView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEarthOrbitView

IMPLEMENT_DYNCREATE(CEarthOrbitView, CScrollView)

BEGIN_MESSAGE_MAP(CEarthOrbitView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CEarthOrbitView construction/destruction

CEarthOrbitView::CEarthOrbitView()
{
	// TODO: add construction code here

}

CEarthOrbitView::~CEarthOrbitView()
{
}

BOOL CEarthOrbitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CEarthOrbitView drawing

void CEarthOrbitView::OnDraw(CDC* /*pDC*/)
{
	CEarthOrbitDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CEarthOrbitView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CEarthOrbitView printing

BOOL CEarthOrbitView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEarthOrbitView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEarthOrbitView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CEarthOrbitView diagnostics

#ifdef _DEBUG
void CEarthOrbitView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CEarthOrbitView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CEarthOrbitDoc* CEarthOrbitView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEarthOrbitDoc)));
	return (CEarthOrbitDoc*)m_pDocument;
}
#endif //_DEBUG


// CEarthOrbitView message handlers
