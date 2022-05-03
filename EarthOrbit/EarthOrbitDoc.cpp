
/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2022 by W. T. Block, All Rights Reserved
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EarthOrbit.h"
#include "EarthOrbitDoc.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE( CEarthOrbitDoc, CDocument )

/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP( CEarthOrbitDoc, CDocument )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
CEarthOrbitDoc::CEarthOrbitDoc()
{
	AngleInDegrees = -90;
	Velocity = -1022; // meters per second
	VelocityX = 0; // meters per second
	VelocityY = -1022; // meters per second
	MetersToMoon = 382500000; // meters
	DistanceScale = 100000000;
	MoonX = MetersToMoon;
	MoonY = 0;
	StartX = MoonX;
	StartY = 0;
	SampleTime = 1; // seconds
	const double dSamplesPerDay = SamplesPerDay;
	RunningTime = 0; // seconds
	MassOfTheEarth = 5.983e24; // kg
	const double dEarthPeriod = EarthPeriod;
}

/////////////////////////////////////////////////////////////////////////////
CEarthOrbitDoc::~CEarthOrbitDoc()
{
}

/////////////////////////////////////////////////////////////////////////////
BOOL CEarthOrbitDoc::OnNewDocument()
{
	if ( !CDocument::OnNewDocument() )
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
void CEarthOrbitDoc::Serialize( CArchive& ar )
{
	if ( ar.IsStoring() )
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
void CEarthOrbitDoc::AssertValid() const
{
	CDocument::AssertValid();
}

/////////////////////////////////////////////////////////////////////////////
void CEarthOrbitDoc::Dump( CDumpContext& dc ) const
{
	CDocument::Dump( dc );
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
