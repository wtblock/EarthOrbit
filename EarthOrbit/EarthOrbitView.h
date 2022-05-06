
/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2022 by W. T. Block, All Rights Reserved
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
class CEarthOrbitView : public CScrollView
{
protected: // create from serialization only
	CEarthOrbitView();
	DECLARE_DYNCREATE( CEarthOrbitView )

	CSize m_sizeClient;	// physical size of client area
	double m_dTop; // top of view in inches

	int m_nPhysicalPageWidth;
	int m_nPhysicalPageHeight;
	int m_nLogicalPageWidth;
	int m_nLogicalPageHeight;
	bool m_bInitialUpdate;
	int m_nNumPages;
	bool m_bRunning;
	bool m_bSingleOrbit;
	vector<CPoint> m_EarthPoints;
	vector<CPoint> m_LunarPoints;

	// properties
public:
	// pointer to the document class
	CEarthOrbitDoc* GetDocument() const;
	// pointer to the document class
	__declspec( property( get = GetDocument ) )
		CEarthOrbitDoc* Document;

	// logical pixels per inch
	int GetMap()
	{
		CEarthOrbitDoc* pDoc = Document;
		const int value = pDoc->Map;
	}
	// logical pixels per inch
	__declspec( property( get = GetMap ) )
		int Map;

	// height of the document in inches
	double GetDocumentHeight()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->Height;
		return value;
	}
	// height of document in inches
	__declspec( property( get = GetDocumentHeight ) )
		double DocumentHeight;

	// width of the document in inches
	double GetDocumentWidth()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->Width;
		return value;
	}
	// width of the document in inches
	__declspec( property( get = GetDocumentWidth ) )
		double DocumentWidth;

	// margin of the document in inches
	double GetDocumentMargin()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->Margin;
		return value;
	}
	// margin of the document in inches
	__declspec( property( get = GetDocumentMargin ) )
		double DocumentMargin;

	// height of the document in logical pixels
	int GetLogicalDocumentHeight()
	{
		const int value = InchesToLogical( DocumentHeight );
		return value;
	}
	// height of the document in logical pixels
	__declspec( property( get = GetLogicalDocumentHeight ) )
		int LogicalDocumentHeight;

	// width of the document in logical pixels
	int GetLogicalDocumentWidth()
	{
		const int value = InchesToLogical( DocumentWidth );
		return value;
	}
	// width of the document in logical pixels
	__declspec( property( get = GetLogicalDocumentWidth ) )
		int LogicalDocumentWidth;

	// margin of the document in logical pixels
	int GetLogicalDocumentMargin()
	{
		const int value = InchesToLogical( DocumentMargin );
		return value;
	}
	// margin of the document in logical pixels
	__declspec( property( get = GetLogicalDocumentMargin ) )
		int LogicalDocumentMargin;

	// get height of the view in inches
	double GetVisibleHeight()
	{
		CClientDC dc( this );
		SetDrawDC( &dc );
		CSize sizeLogical = m_sizeClient;
		dc.DPtoLP( &sizeLogical );
		const double value = LogicalToInches( sizeLogical.cy );
		return value;
	}
	// get height of the view in inches
	__declspec( property( get = GetVisibleHeight ) )
		double VisibleHeight;

	// get line height in inches
	double GetLineHeight()
	{
		return 0.25;
	}
	// get line height in inches
	__declspec( property( get = GetLineHeight ) )
		double LineHeight;

	// get last viewable position in inches accounting for view height
	double GetLast()
	{
		double value = DocumentHeight - VisibleHeight;
		if ( value < 0 )
		{
			value = 0;
		}
		return value;
	}
	// get last viewable position in inches accounting for view height
	__declspec( property( get = GetLast ) )
		double Last;

	// get page height in inches
	double GetPageHeight()
	{
		const double value = VisibleHeight / 2;
		return value;
	}
	// get page height in inches
	__declspec( property( get = GetPageHeight ) )
		double PageHeight;

	// number of scrolling lines
	int GetScrollLines()
	{
		const double dLines = Last / LineHeight;
		int value = int( dLines );
		if ( !NearlyEqual( double( value ), dLines ) )
		{
			value++;
		}
		return value;
	}
	// number of scrolling lines
	__declspec( property( get = GetScrollLines ) )
		int ScrollLines;

	// top of view in inches
	double GetTopOfView()
	{
		return m_dTop;
	}
	// top of view in inches
	void SetTopOfView( double value )
	{
		m_dTop = value;
	}
	// top of view in inches
	__declspec( property( get = GetTopOfView, put = SetTopOfView ) )
		double TopOfView;

	// running?
	bool GetRunning()
	{
		return m_bRunning;
	}
	// running?
	void SetRunning( bool value )
	{
		m_bRunning = value;
	}
	// running?
	__declspec( property( get = GetRunning, put = SetRunning ) )
		bool Running;

	// running?
	bool GetSingleOrbit()
	{
		return m_bSingleOrbit;
	}
	// running?
	void SetSingleOrbit( bool value )
	{
		m_bSingleOrbit = value;
	}
	// running?
	__declspec( property( get = GetSingleOrbit, put = SetSingleOrbit ) )
		bool SingleOrbit;

	// get bottom of view in inches
	double GetBottomOfView()
	{
		return m_dTop + VisibleHeight;
	}
	// get bottom of view in inches
	__declspec( property( get = GetBottomOfView ) )
		double BottomOfView;

	// velocity in meters per second
	double GetLunarVelocity()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->LunarVelocity;
		return value;
	}
	// velocity in meters per second
	void SetLunarVelocity( double value )
	{
		Document->LunarVelocity = value;
	}
	// velocity in meters per second
	__declspec( property( get = GetLunarVelocity, put = SetLunarVelocity ) )
		double LunarVelocity;

	// horizontal velocity in meters per second
	double GetHorizontalLunarVelocity()
	{
		// earth moon angle in radians
		const double dRadians = LunarAngleInRadians;

		// the velocity towards the earth
		const double dLunarVelocity = LunarVelocity;

		// we are interested in the vector adjacent to the
		// angle which requires the cosine of the angle
		const double dCosine = cos( dRadians );

		// the cosine of the angle multiplied by the velocity (hypotenuse 
		// of the triangle) yields the horizontal velocity (side adjacent
		// to the angle)
		const double value = dLunarVelocity * dCosine;
		return value;
	}
	// horizontal velocity in meters per second
	__declspec( property( get = GetHorizontalLunarVelocity ) )
		double HorizontalLunarVelocity;

	// vertical velocity in meters per second
	double GetVerticalLunarVelocity()
	{
		// earth moon angle in radians forming the triangle
		// on the display
		const double dRadians = LunarAngleInRadians;

		// the velocity corresponds towards the earth
		const double dLunarVelocity = LunarVelocity;

		// we are interested in the vector opposite of the
		// angle which requires the sine of the angle
		const double dSine = sin( dRadians );

		// the sine of the angle multiplied by the velocity (hypotenuse 
		// of the triangle) yields the vertical velocity (side opposite
		// of the angle)
		const double value = dLunarVelocity * dSine;
		return value;
	}
	// vertical velocity in meters per second
	__declspec( property( get = GetVerticalLunarVelocity ) )
		double VerticalLunarVelocity;

	// angle in radians of the moon
	double GetLunarAngleInRadians()
	{
		// center of the moon on the screen
		CPoint ptMoon = MoonCenter;

		// triangle where the hypotenuse is the vector from the 
		// earth to the moon
		CPoint ptEarth = EarthCenter;

		// difference between the moon's center X and the earth's center X
		const int nX = ptMoon.x - ptEarth.x;

		// same for Y except NOTE the reverse order. This is due to 
		// our inverted coordinate system from standard Cartesian
		// coordinates (our Y gets larger as you go down instead of
		// getting larger when you go up) which has to be accounted
		// for when doing trigonometry. Our logical coordinate system
		// is setup by the SetDrawDC and SetPrintDC in order to make
		// all drawing device independent where DC stands for device
		// context.
		const int nY = ptEarth.y - ptMoon.y;

		// length of the hypotenuse using the Pythagorean theorem
		// i.e. square root of the sum of the squares of the sides
		const double dH = sqrt( double( nX * nX + nY * nY ) );

		// sine of the angle is the ratio of the opposite side / hypotenuse 
		const double dSine = double( nY ) / dH;

		// angle in radians is the arc sine of the sine of the angle
		const double value = asin( dSine );

		return value;
	}
	// angle in radians of the moon
	__declspec( property( get = GetLunarAngleInRadians ) )
		double LunarAngleInRadians;

	// angle in degrees of the moon
	double GetLunarAngleInDegrees()
	{
		// angle in radians
		const double dRadians = LunarAngleInRadians;

		// angle in degrees 
		const double value = Degrees( dRadians );

		// record the angle
		LunarAngleInDegrees = value;

		return value;
	}
	// angle in degrees of the moon
	void SetLunarAngleInDegrees( double value )
	{
		CEarthOrbitDoc* pDoc = Document;
		pDoc->LunarAngleInDegrees = value;
	}
	// angle in degrees of the moon
	__declspec( property( get = GetLunarAngleInDegrees, put = SetLunarAngleInDegrees ) )
		double LunarAngleInDegrees;

	// distance to earth in meters
	double GetLunarDistance()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->LunarDistance;
		return value;
	}
	// distance to earth in meters
	void SetLunarDistance( double value )
	{
		CEarthOrbitDoc* pDoc = Document;
		pDoc->LunarDistance = value;
	}
	// distance to earth in meters
	__declspec( property( get = GetLunarDistance, put = SetLunarDistance ) )
		double LunarDistance;

	// velocity in meters per second
	double GetEarthVelocity()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->EarthVelocity;
		return value;
	}
	// velocity in meters per second
	void SetEarthVelocity( double value )
	{
		Document->EarthVelocity = value;
	}
	// velocity in meters per second
	__declspec( property( get = GetEarthVelocity, put = SetEarthVelocity ) )
		double EarthVelocity;

	// horizontal velocity in meters per second
	double GetHorizontalEarthVelocity()
	{
		// earth sun angle in radians forming the triangle
		// on the display
		const double dRadians = EarthAngleInRadians;

		// the velocity corresponds to the hypotenuse of the
		// triangle 
		const double dEarthVelocity = EarthVelocity;

		// we are interested in the vector adjacent to the
		// angle which requires the cosine of the angle
		const double dCosine = cos( dRadians );

		// the cosine of the angle multiplied by the velocity (hypotenuse 
		// of the triangle) yields the horizontal velocity (side adjacent
		// to the angle)
		const double value = dEarthVelocity * dCosine;
		return value;
	}
	// horizontal velocity in meters per second
	__declspec( property( get = GetHorizontalEarthVelocity ) )
		double HorizontalEarthVelocity;

	// vertical velocity in meters per second
	double GetVerticalEarthVelocity()
	{
		// earth sun angle in radians forming the triangle
		// on the display
		const double dRadians = EarthAngleInRadians;

		// the velocity corresponds to the hypotenuse of the
		// triangle 
		const double dEarthVelocity = EarthVelocity;

		// we are interested in the vector opposite of the
		// angle which requires the sine of the angle
		const double dSine = sin( dRadians );

		// the sine of the angle multiplied by the velocity (hypotenuse 
		// of the triangle) yields the vertical velocity (side opposite
		// of the angle)
		const double value = dEarthVelocity * dSine;
		return value;
	}
	// vertical velocity in meters per second
	__declspec( property( get = GetVerticalEarthVelocity ) )
		double VerticalEarthVelocity;

	// angle in radians of the earth
	double GetEarthAngleInRadians()
	{
		// center of the moon
		CPoint ptEarth = EarthCenter;

		// triangle where the hypotenuse is the vector from the 
		// sun to the earth
		CPoint ptSun = SunCenter;

		// difference between the earth's center X and the sun's center X
		const int nX = ptEarth.x - ptSun.x;

		// same for Y except NOTE the reverse order. This is due to 
		// our inverted coordinate system from standard Cartesian
		// coordinates (our Y gets larger as you go down instead of
		// getting larger when you go up) which has to be accounted
		// for when doing trigonometry. Our logical coordinate system
		// is setup by the SetDrawDC and SetPrintDC in order to make
		// all drawing device independent where DC stands for device
		// context.
		const int nY = ptSun.y - ptEarth.y;

		// length of the hypotenuse using the Pythagorean theorem
		const double dH = sqrt( double( nX * nX + nY * nY ) );

		// length of the hypotenuse using the Pythagorean theorem
		// i.e. square root of the sum of the squares of the sides
		const double dSine = double( nY ) / dH;

		// sine of the angle is the ratio of the opposite side / hypotenuse 
		const double value = asin( dSine );

		return value;
	}
	// angle in radians of the moon
	__declspec( property( get = GetEarthAngleInRadians ) )
		double EarthAngleInRadians;

	// angle in degrees of the moon
	double GetEarthAngleInDegrees()
	{
		// angle in radians
		const double dRadians = EarthAngleInRadians;

		// angle in degrees 
		const double value = Degrees( dRadians );

		// record the angle
		EarthAngleInDegrees = value;

		return value;
	}
	// angle in degrees of the moon
	void SetEarthAngleInDegrees( double value )
	{
		CEarthOrbitDoc* pDoc = Document;
		pDoc->EarthAngleInDegrees = value;
	}
	// angle in degrees of the moon
	__declspec( property( get = GetEarthAngleInDegrees, put = SetEarthAngleInDegrees ) )
		double EarthAngleInDegrees;

	// distance to earth in meters
	double GetEarthDistance()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->EarthDistance;
		return value;
	}
	// distance to earth in meters
	void SetEarthDistance( double value )
	{
		CEarthOrbitDoc* pDoc = Document;
		pDoc->EarthDistance = value;
	}
	// distance to earth in meters
	__declspec( property( get = GetEarthDistance, put = SetEarthDistance ) )
		double EarthDistance;

	// time in seconds between samples
	double GetSampleTime()
	{
		CEarthOrbitDoc* pDoc = Document;
		const double value = pDoc->SampleTime;
		return value;
	}
	// time in seconds between samples
	void SetSampleTime( double value )
	{
		CEarthOrbitDoc* pDoc = Document;
		pDoc->SampleTime = value;
	}
	// time in seconds between samples
	__declspec( property( get = GetSampleTime, put = SetSampleTime ) )
		double SampleTime;

	// meters per inch scale
	double GetMetersPerInch()
	{
		const double dMeters = LunarDistance;
		const double dMargin = DocumentMargin;
		const double dInches = DocumentWidth - 2 * dMargin;
		const double value = dMeters / dInches;
		return value;
	}
	// meters per inch scale
	__declspec( property( get = GetMetersPerInch ) )
		double MetersPerInch;

	// point defining the sun's center
	CPoint GetSunCenter()
	{
		// get the center of the sun on the document
		const double dDocumentWidth = DocumentWidth;
		const double dDocumentHeight = DocumentHeight;
		const int nX = InchesToLogical( dDocumentWidth / 2 );
		const int nY = InchesToLogical( dDocumentHeight / 2 );

		// build the point
		CPoint value( nX, nY );
		return value;
	}
	// point defining the sun's center
	__declspec( property( get = GetSunCenter ) )
		CPoint SunCenter;

	// rectangle defining the sun
	CRect GetSunRectangle()
	{
		// get the center of the sun on the document
		CPoint ptCenter = SunCenter;

		// rectangle size (width and height) in inches
		const double dSize = 0.75;
		const int nSize = InchesToLogical( dSize );
		CSize size( nSize, nSize );

		// build the rectangle
		CRect value( ptCenter, size );

		// recenter the rectangle
		value.OffsetRect( -size.cx / 2, -size.cy / 2 );
		return value;
	}
	// rectangle defining the sun
	__declspec( property( get = GetSunRectangle ) )
		CRect SunRectangle;

	// point defining the earth's center
	CPoint GetEarthCenter()
	{
		CEarthOrbitDoc* pDoc = Document;

		// build the point starting with the sun's center
		CPoint value = SunCenter;

		// x and y coordinates of the earth relative to the sun
		// in meters
		const double dMetersX = pDoc->EarthX;
		const double dMetersY = pDoc->EarthY;

		// x and y coordinates of the earth relative to the sun
		// in screen inches
		const double dInchesX = pDoc->EarthScreenInches[ dMetersX ];
		const double dInchesY = pDoc->EarthScreenInches[ dMetersY ];

		// x and y coordinates of the earth relative to the sun
		// in logical pixels
		const int nX = InchesToLogical( dInchesX );
		const int nY = InchesToLogical( dInchesY );

		// offset the sun center by the earth's relative coordinates
		value.Offset( nX, nY );

		return value;
	}
	// point defining the earth's center
	__declspec( property( get = GetEarthCenter ) )
		CPoint EarthCenter;

	// rectangle defining the earth
	CRect GetEarthRectangle()
	{
		// get the center of the earth on the document
		CPoint ptCenter = EarthCenter;

		// rectangle size (width and height) in inches
		const double dSize = 0.5;
		const int nSize = InchesToLogical( dSize );
		CSize size( nSize, nSize );

		// build the rectangle
		CRect value( ptCenter, size );

		// recenter the rectangle
		value.OffsetRect( -size.cx / 2, -size.cy / 2 );
		return value;
	}
	// rectangle defining the earth
	__declspec( property( get = GetEarthRectangle ) )
		CRect EarthRectangle;

	// point defining the moon's center
	CPoint GetMoonCenter()
	{
		CEarthOrbitDoc* pDoc = Document;

		// build the point starting with the earth's center
		CPoint value = EarthCenter;

		// x and y coordinates of the moon relative to the earth
		// in meters
		const double dMetersX = pDoc->LunarX;
		const double dMetersY = pDoc->LunarY;

		// x and y coordinates of the moon relative to the earth
		// in screen inches
		const double dInchesX = pDoc->LunarScreenInches[ dMetersX ];
		const double dInchesY = pDoc->LunarScreenInches[ dMetersY ];

		// x and y coordinates of the moon relative to the earth
		// in logical pixels
		const int nX = InchesToLogical( dInchesX );
		const int nY = InchesToLogical( dInchesY );

		// offset the earth center by the moon's relative coordinates
		value.Offset( nX, nY );

		return value;
	}
	// point defining the moon's center
	__declspec( property( get = GetMoonCenter ) )
		CPoint MoonCenter;

	// rectangle defining the moon
	CRect GetMoonRectangle()
	{
		// get the center of the earth on the document
		CPoint ptCenter = MoonCenter;

		// rectangle size (width and height) in inches
		const double dSize = 0.25;
		const int nSize = InchesToLogical( dSize );
		CSize size( nSize, nSize );

		// build the rectangle
		CRect value( ptCenter, size );

		// recenter the rectangle
		value.OffsetRect( -size.cx / 2, -size.cy / 2 );
		return value;
	}
	// rectangle defining the moon
	__declspec( property( get = GetMoonRectangle ) )
		CRect MoonRectangle;

	// public methods
public:
	// PI
	static inline const double PI()
	{
		return 3.1415926535897932384626433832795;
	}

	// degrees from radians
	template <class T> static inline T Degrees( T radians )
	{
		return (T)180 / (T)PI() * radians;
	}

	// radians from degrees
	template <class T> static inline T Radians( T degrees )
	{
		return (T)PI() / (T)180 * degrees;
	}

	// compare two reals and determine if they are nearly equal 
	// (within the given error range)
	template <class T> static inline bool NearlyEqual
	(
		T value1, T value2, T error = T( 0.0001 )
	)
	{
		const T diff = fabs( value1 - value2 );
		return diff < error;
	}

	// Round value to nearest multiple of nearest (ie. if nearest is 0.1
	// round to the nearest tenth or if nearest is 5, round to the nearest
	// multiple of five).  If second parameter is not supplied, value is 
	// rounded to the nearest whole number 
	template <class T> static inline T RoundToNearest
	(
		T value, T nearest = T( 1 )
	)
	{
		if ( nearest == 0 )
		{
			nearest = 1;
		}
		nearest = fabs( nearest ); // positive number
		value /= nearest;
		value = value < 0 ?
			ceil( value - T( 0.5 ) ) :
			floor( value + T( 0.5 ) );
		value *= nearest;
		return value;
	}

	// convert logical co-ordinate value to inches
	double LogicalToInches( int nValue )
	{
		CEarthOrbitDoc* pDoc = Document;
		const int nMap = pDoc->Map;
		return ( double( nValue ) / nMap );
	}

	// convert inches to logical co-ordinate value
	int InchesToLogical( double dValue )
	{
		CEarthOrbitDoc* pDoc = Document;
		const int nMap = pDoc->Map;
		return int( dValue * nMap );
	}

	// prepare the device context for printing
	void SetPrintDC
	(
		CDC* pDC,
		int& nPhysicalWidth, // in pixels
		int& nPhysicalHeight, // in pixels
		int& nLogicalWidth, // in inches * Map
		int& nLogicalHeight // in inches * Map
	);

	// prepare the device context for drawing and
	// return the logical width
	int SetDrawDC( CDC* pDC );

	// protected methods
protected:
	// add the current moon position to the historical points of the lunar orbit
	void AddLunarPoint();

	// add the current earth position to the historical points of the earth orbit
	void AddEarthPoint();

	// update the position of the moon for a day
	void UpdateMoonPosition();

	// update the position of the earth for a day
	void UpdateEarthPosition();

	// render the lunar orbit 
	void RenderLunarOrbit( CDC* pDC );

	// render the lunar orbit 
	void RenderEarthOrbit( CDC* pDC );

	// render the equations of motion
	void RenderEquations( CDC* pDC );

	// render the text information
	void RenderText( CDC* pDC );

	// render the grid
	void RenderGrid( CDC* pDC );

	// render the scale labels in inches
	void RenderScale( CDC* pDC );

	// render the moon's shape
	void RenderMoon( CDC* pDC );

	// render the earth's shape
	void RenderEarth( CDC* pDC );

	// render the sun's shape
	void RenderSun( CDC* pDC );

	// render the sun / earth triangle - the sun's acceleration is 
	// applied toward's the earth along the triangle's hypotenuse, but
	// in order to calculate velocity and position of the earth that 
	// gravitational attraction needs to be broken into a vertical and
	// horizontal vector represented by the sides of the right triangle
	void RenderTriangle( CDC* pDC );

	// render the page or view
	void render
	(
		CDC* pDC, double dTopOfView, double dBottomOfView, int nLogicalWidth
	);

	// set the scroll bar position and range
	void SetupScrollBars()
	{
		const double dLast = Last;
		if ( NearlyEqual( dLast, 0.0 ) )
		{
			SetScrollPos( SB_VERT, 0, FALSE );
			SetScrollRange( SB_VERT, 0, 1, TRUE );
		}
		else
		{
			int nLines = ScrollLines;
			if ( nLines <= 1 )
			{
				nLines = 2;
			}
			const double dRatio = TopOfView / Last;
			const double dLine = double( nLines ) * dRatio;
			int nLine = int( dLine + 0.5 );
			if ( nLine >= nLines )
			{
				nLine = nLines - 1;
			}

			SetScrollPos( SB_VERT, nLine, FALSE );
			SetScrollRange( SB_VERT, 0, nLines - 1, TRUE );
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// generate font characteristics from given font enumeration, where
	// the enumeration is based on Atlas PDF definition
	static void BuildFont
	(
		CString csFace, // name of the font face
		bool bBold, // bold font if true
		bool bItalic, // italic font if true
		int nTextHeight, // text height in pixels
		bool bVertical, // vertical orientation
		CFont& font, // generated font
		BYTE nCharSet = ANSI_CHARSET, // current character set
		bool bFlipX = false, // flip horizontally
		bool bFlipY = false, // flip vertically
		short nUp = -1, // moving up is a negative value
		int nTextWidth = 0 // default width
	);


	// Overrides
public:
	virtual void OnPrepareDC( CDC* pDC, CPrintInfo* pInfo = NULL );
	virtual void OnDraw( CDC* pDC );  // overridden to draw this view
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting( CPrintInfo* pInfo );
	virtual void OnBeginPrinting( CDC* pDC, CPrintInfo* pInfo );
	virtual void OnPrint( CDC* pDC, CPrintInfo* pInfo );
	virtual void OnEndPrinting( CDC* pDC, CPrintInfo* pInfo );

	// Implementation
public:
	virtual ~CEarthOrbitView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:

	// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp( UINT nFlags, CPoint point );
	afx_msg void OnContextMenu( CWnd* pWnd, CPoint point );
	afx_msg void OnSize( UINT nType, int cx, int cy );
	afx_msg void OnVScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer( UINT_PTR nIDEvent );
	afx_msg void OnEditPause();
	afx_msg void OnUpdateEditPause( CCmdUI *pCmdUI );
	afx_msg void OnEditRun();
	afx_msg void OnUpdateEditRun( CCmdUI *pCmdUI );
	afx_msg void OnEditSingleOrbit();
	afx_msg void OnUpdateEditSingleorbit( CCmdUI *pCmdUI );
};

#ifndef _DEBUG  // debug version in EarthOrbitView.cpp
inline CEarthOrbitDoc* CEarthOrbitView::GetDocument() const
{
	return reinterpret_cast<CEarthOrbitDoc*>( m_pDocument );
}
#endif

