
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
	MassOfTheEarth = 5.983e24; // kg
	LunarAngleInDegrees = -90;
	LunarVelocity = -1022; // meters per second
	LunarVelocityX = 0; // meters per second
	LunarVelocityY = -1022; // meters per second
	LunarDistance = 382500000; // meters from earth
	LunarInches = 1.0; // radius on the screen of lunar orbit around earth
	LunarScaling =  500000000;
	LunarX = LunarDistance; // meters from earth's x axis
	LunarY = 0; // meters from earth's y axis
	
	// acceleration of gravity on the moon from the earth
	const double dLunarA = LunarEarthGravity;
	LunarAx = dLunarA; // lunar X vector acceleration m/s^2
	LunarAy = 0; // lunar Y vector acceleration m/s^2

	MassOfTheSun = 1.988e30; // kg
	EarthAngleInDegrees = -90;
	EarthVelocity = -29780; // meters per second
	EarthVelocityX = 0; // meters per second
	EarthVelocityY = -29780; // meters per second
	EarthDistance = 149600000000; // meters from earth
	EarthInches = 3.0; // radius on the screen of earth orbit around the sun
	EarthX = EarthDistance; // meters from sun's x axis
	EarthY = 0; // meters from sun's y axis
	
	// acceleration of gravity on the earth from the sun
	const double dEarthA = EarthSolarGravity;
	EarthAx = dEarthA; // earth X vector acceleration m/s^2
	EarthAy = 0; // earth Y vector acceleration m/s^2

	SampleTime = 1; // seconds
	const double dSamplesPerDay = SamplesPerDay;
	RunningTime = 0; // seconds
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
