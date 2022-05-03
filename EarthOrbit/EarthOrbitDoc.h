
/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2022 by W. T. Block, All Rights Reserved
/////////////////////////////////////////////////////////////////////////////

#pragma once

/////////////////////////////////////////////////////////////////////////////
class CEarthOrbitDoc : public CDocument
{
protected: // create from serialization only
	CEarthOrbitDoc();
	DECLARE_DYNCREATE( CEarthOrbitDoc )
	double m_dAngle; // angle of the moon in degrees
	double m_dVelocity; // velocity in meters per second
	double m_dVelocityX; // X velocity in meters per second
	double m_dVelocityY; // Y velocity in meters per second
	double m_dMetersToMoon; // distance to moon in meters
	double m_dDistanceScale; // distance scale meters to inches on screen
	double m_dMoonX; // X coordinate of the moon in meters
	double m_dMoonY; // Y coordinate of the moon in meters
	double m_dStartX; // Start X coordinate of the moon in meters
	double m_dStartY; // Start Y coordinate of the moon in meters
	double m_dSampleTime; // time in seconds between samples
	double m_dSamplesPerDay; // number of samples per day
	double m_dRunningTime; // number of seconds the application has run
	double m_dMassOfTheEarth; // mass of the earth in kilograms
	double m_dEarthPeriod; // period of the lunar orbit in seconds
	double m_dAccelerationOfGravity; // meters per second squared

// properties
public:
	// PI
	double GetPI()
	{
		return 3.1415926535897932384626433832795;
	}
	// PI
	__declspec( property( get = GetPI ) )
		double PI;

	// degrees from radians
	double GetDegrees( double dRadians )
	{
		return 180.0 / PI * dRadians;
	}
	// degrees from radians
	__declspec( property( get = GetDegrees ) )
		double Degrees[];

	// radians from degrees
	double GetRadians( double dDegrees )
	{
		return PI / 180.0 * dDegrees;
	}
	// radians from degrees
	__declspec( property( get = GetRadians ) )
		double Radians[];

	// logical pixels per inch
	int GetMap()
	{
		return 1000;
	}
	// logical pixels per inch
	__declspec( property( get = GetMap ) )
		int Map;

	// number of pages in the document
	UINT GetPages()
	{
		return 1;
	}
	// number of pages in the document
	__declspec( property( get = GetPages ) )
		UINT Pages;

	// height of document in inches
	double GetHeight()
	{
		return 8.5;
	}
	// height of document in inches
	__declspec( property( get = GetHeight ) )
		double Height;

	// width of document in inches
	double GetWidth()
	{
		return 11.0;
	}
	// width of document in inches
	__declspec( property( get = GetWidth ) )
		double Width;

	// margin of document in inches
	double GetMargin()
	{
		return 0.25;
	}
	// margin of document in inches
	__declspec( property( get = GetMargin ) )
		double Margin;

	// angle in degrees of the moon
	double GetAngleInDegrees()
	{
		return m_dAngle;
	}
	// angle in degrees of the moon
	void SetAngleInDegrees( double value )
	{
		m_dAngle = value;
	}
	// angle in degrees of the moon
	__declspec( property( get = GetAngleInDegrees, put = SetAngleInDegrees ) )
		double AngleInDegrees;

	// velocity in meters per second
	double GetVelocity()
	{
		return m_dVelocity;
	}
	// velocity in meters per second
	void SetVelocity( double value )
	{
		m_dVelocity = value;
	}
	// velocity in meters per second
	__declspec( property( get = GetVelocity, put = SetVelocity ) )
		double Velocity;

	// X velocity in meters per second
	double GetVelocityX()
	{
		return m_dVelocityX;
	}
	// X velocity in meters per second
	void SetVelocityX( double value )
	{
		m_dVelocityX = value;
	}
	// X velocity in meters per second
	__declspec( property( get = GetVelocityX, put = SetVelocityX ) )
		double VelocityX;

	// Y velocity in meters per second
	double GetVelocityY()
	{
		return m_dVelocityY;
	}
	// Y velocity in meters per second
	void SetVelocityY( double value )
	{
		m_dVelocityY = value;
	}
	// Y velocity in meters per second
	__declspec( property( get = GetVelocityY, put = SetVelocityY ) )
		double VelocityY;

	// distance to moon in meters
	double GetMetersToMoon()
	{
		return m_dMetersToMoon;
	}
	// distance to moon in meters
	void SetMetersToMoon( double value )
	{
		m_dMetersToMoon = value;
	}
	// distance to moon in meters
	__declspec( property( get = GetMetersToMoon, put = SetMetersToMoon ) )
		double MetersToMoon;

	// mass of the earth in kilograms
	double GetMassOfTheEarth()
	{
		return m_dMassOfTheEarth;
	}
	// mass of the earth in kilograms
	void SetMassOfTheEarth( double value )
	{
		m_dMassOfTheEarth = value;
	}
	// mass of the earth in kilograms
	__declspec( property( get = GetMassOfTheEarth, put = SetMassOfTheEarth ) )
		double MassOfTheEarth;

	// period of the lunar orbit in seconds
	double GetEarthPeriod()
	{
		const double dDays = 27.32;
		const double dSeconds = dDays * 86400;
		m_dEarthPeriod = dSeconds;
		return m_dEarthPeriod;
	}
	// period of the lunar orbit in seconds
	__declspec( property( get = GetEarthPeriod ) )
		double EarthPeriod;

	// acceleration of gravity on the moon
	double GetAccelerationOfGravity()
	{
		// g = G*M/R^2
		// g is the acceleration of gravity being calculated
		// G is the gravitational constant (6.657 x 10^-11 Nm2kg-2)
		// M is the mass of the earth in kg
		// R is radius (distance to the moon) in meters
		const double dG = 6.657e-11;
		const double dM = MassOfTheEarth;
		const double dR = MetersToMoon;
		const double dR2 = dR * dR;
		m_dAccelerationOfGravity = dG * dM / dR2;
		return m_dAccelerationOfGravity;
	}
	// acceleration of gravity on the moon
	__declspec( property( get = GetAccelerationOfGravity ) )
		double AccelerationOfGravity;

	// distance scale meters to inches on screen
	double GetDistanceScale()
	{
		return m_dDistanceScale;
	}
	// distance scale meters to inches on screen
	void SetDistanceScale( double value )
	{
		m_dDistanceScale = value;
	}
	// distance scale meters to inches on screen
	__declspec( property( get = GetDistanceScale, put = SetDistanceScale ) )
		double DistanceScale;

	// given a distance in meters, return the number of inches on the screen
	double GetScreenInches( double meters )
	{
		const double scale = DistanceScale;
		const double value = meters / scale;
		return value;
	}
	// given a distance in meters, return the number of inches on the screen
	__declspec( property( get = GetScreenInches ) )
		double ScreenInches[];

	// X coordinate of the moon in meters
	double GetMoonX()
	{
		return m_dMoonX;
	}
	// X coordinate of the moon in meters
	void SetMoonX( double value )
	{
		m_dMoonX = value;
	}
	// X coordinate of the moon in meters
	__declspec( property( get = GetMoonX, put = SetMoonX ) )
		double MoonX;

	// Y coordinate of the moon in meters
	double GetMoonY()
	{
		return m_dMoonY;
	}
	// Y coordinate of the moon in meters
	void SetMoonY( double value )
	{
		m_dMoonY = value;
	}
	// Y coordinate of the moon in meters
	__declspec( property( get = GetMoonY, put = SetMoonY ) )
		double MoonY;

	// Start X coordinate of the moon in meters
	double GetStartX()
	{
		return m_dStartX;
	}
	// Start X coordinate of the moon in meters
	void SetStartX( double value )
	{
		m_dStartX = value;
	}
	// Start X coordinate of the moon in meters
	__declspec( property( get = GetStartX, put = SetStartX ) )
		double StartX;

	// Start Y coordinate of the moon in meters
	double GetStartY()
	{
		return m_dStartY;
	}
	// Start Y coordinate of the moon in meters
	void SetStartY( double value )
	{
		m_dStartY = value;
	}
	// Start Y coordinate of the moon in meters
	__declspec( property( get = GetStartY, put = SetStartY ) )
		double StartY;

	// time in seconds between samples
	double GetSampleTime()
	{
		return m_dSampleTime;
	}
	// time in seconds between samples
	void SetSampleTime( double value )
	{
		m_dSampleTime = value;
	}
	// time in seconds between samples
	__declspec( property( get = GetSampleTime, put = SetSampleTime ) )
		double SampleTime;

	// samples per day
	double GetSamplesPerDay()
	{
		const double dSecondsPerDay = 86400.0;
		const double dSampleTime = SampleTime;
		const double value = dSecondsPerDay / dSampleTime;
		SamplesPerDay = value;
		return value;
	}
	// samples per day
	void SetSamplesPerDay( double value )
	{
		m_dSamplesPerDay = value;
	}
	// samples per day
	__declspec( property( get = GetSamplesPerDay, put = SetSamplesPerDay ) )
		double SamplesPerDay;

	// number of seconds the application has run
	double GetRunningTime()
	{
		return m_dRunningTime;
	}
	// number of seconds the application has run
	void SetRunningTime( double value )
	{
		m_dRunningTime = value;
	}
	// number of seconds the application has run
	__declspec( property( get = GetRunningTime, put = SetRunningTime ) )
		double RunningTime;

	// get a pointer to the view
	CView* GetView()
	{
		POSITION pos = GetFirstViewPosition();
		CView* value = 0;
		while ( value == 0 && pos )
		{
			value = GetNextView( pos );
		}

		return value;
	}
	// get a pointer to the view
	__declspec( property( get = GetView ) )
		CView* View;


	// Operations
public:

	// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize( CArchive& ar );

	// Implementation
public:
	virtual ~CEarthOrbitDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};
