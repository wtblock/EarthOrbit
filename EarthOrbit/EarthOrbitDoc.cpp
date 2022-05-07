
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
	LunarAngleInDegrees = 0;
	LunarVelocity = -1022; // meters per second
	LunarVelocityX = 0; // meters per second
	LunarVelocityY = -1022; // meters per second
	LunarDistance = 382500000; // meters from earth
	LunarInches = 1.0; // radius in inches on the screen of lunar orbit
	const double dLunarScaling = LunarScaling; // meters to inches
	LunarX = LunarDistance; // meters from earth's y axis
	LunarY = 0; // meters from earth's x axis
	
	// acceleration of gravity on the moon from the earth
	const double dLunarA = LunarEarthGravity;
	LunarAx = dLunarA; // lunar X vector acceleration m/s^2
	LunarAy = 0; // lunar Y vector acceleration m/s^2

	// the web provides different values for the mass of the sun, varying 
	// from a high value of 2.0e30 to a low value of 1.9885e30 kg
	// I experimented with numbers until the orbital period was 365.26 
	// days which is a well known value
	MassOfTheSun = 1.99355e30; // kg
	EarthAngleInDegrees = 0;
	// like the mass, the distance to the sun varies on the web, so I 
	// looked up the value of an astronomical unit which was specified
	// with a lot of precision
	EarthDistance = 1.495978707e11; // meters from earth (one astronomical unit)
	EarthInches = 3.0; // radius on the screen of earth orbit around the sun
	EarthX = EarthDistance; // meters from sun's y axis
	EarthY = 0; // meters from sun's x axis
	
	// acceleration of gravity on the earth from the sun
	const double dEarthA = EarthSolarGravity;
	EarthAx = dEarthA; // earth X vector acceleration m/s^2
	EarthAy = 0; // earth Y vector acceleration m/s^2

	SampleTime = 1; // seconds
	const double dSamplesPerDay = SamplesPerDay;
	RunningTime = 0; // seconds

	// circumference of the earth's orbit in meters
	const double dCircumference = EarthDistance * 2 * PI;

	// length of a year in seconds
	const double dSeconds = 365.26 * 86400;

	// velocity of the earth
	const double dVelocity = dCircumference / dSeconds;

	EarthVelocity = -dVelocity; // meters per second
	EarthVelocityX = 0; // meters per second
	EarthVelocityY = EarthVelocity; // meters per second
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
