
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
	double m_dLunarAngle; // angle of the moon in degrees
	double m_dLunarVelocity; // velocity in meters per second
	double m_dLunarVelocityX; // X velocity in meters per second
	double m_dLunarVelocityY; // Y velocity in meters per second
	double m_dLunarDistance; // distance to moon in meters from Earth
	double m_dLunarInches; // radius of lunar orbit around the earth on the screen
	double m_dLunarScaling; // lunar distance scale meters to inches on screen
	double m_dLunarX; // X coordinate of the moon in meters relative to earth
	double m_dLunarY; // Y coordinate of the moon in meters relative to earth
	double m_dLunarEarthGravity; // gravitational effect of earth on the moon
	double m_dLunarAx; // X vector of earth/lunar gravity
	double m_dLunarAy; // Y vector of earth/lunar gravity

	double m_dEarthAngle; // angle of the earth in degrees
	double m_dEarthVelocity; // velocity in meters per second
	double m_dEarthVelocityX; // X velocity in meters per second
	double m_dEarthVelocityY; // Y velocity in meters per second
	double m_dEarthDistance; // distance to earth in meters from sun
	double m_dEarthInches; // radius of earth orbit around the sun on the screen
	double m_dEarthScaling; // solar distance scale meters to inches on screen
	double m_dEarthX; // X coordinate of the earth in meters relative to sun
	double m_dEarthY; // Y coordinate of the earth in meters relative to sun
	double m_dEarthSolarGravity; // gravitational effect of sun on the earth
	double m_dEarthAx; // X vector of sun/earth gravity
	double m_dEarthAy; // Y vector of sun/earth gravity

	double m_dSampleTime; // time in seconds between samples
	double m_dSamplesPerDay; // number of samples per day
	double m_dRunningTime; // number of seconds the application has run
	double m_dMassOfTheEarth; // mass of the earth in kilograms
	double m_dMassOfTheSun; // mass of the sun in kilograms

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
	double GetLunarAngleInDegrees()
	{
		return m_dLunarAngle;
	}
	// angle in degrees of the moon
	void SetLunarAngleInDegrees( double value )
	{
		m_dLunarAngle = value;
	}
	// angle in degrees of the moon
	__declspec( property( get = GetLunarAngleInDegrees, put = SetLunarAngleInDegrees ) )
		double LunarAngleInDegrees;

	// velocity in meters per second
	double GetLunarVelocity()
	{
		return m_dLunarVelocity;
	}
	// velocity in meters per second
	void SetLunarVelocity( double value )
	{
		m_dLunarVelocity = value;
	}
	// velocity in meters per second
	__declspec( property( get = GetLunarVelocity, put = SetLunarVelocity ) )
		double LunarVelocity;

	// X velocity in meters per second
	double GetLunarVelocityX()
	{
		return m_dLunarVelocityX;
	}
	// X velocity in meters per second
	void SetLunarVelocityX( double value )
	{
		m_dLunarVelocityX = value;
	}
	// X velocity in meters per second
	__declspec( property( get = GetLunarVelocityX, put = SetLunarVelocityX ) )
		double LunarVelocityX;

	// Y velocity in meters per second
	double GetLunarVelocityY()
	{
		return m_dLunarVelocityY;
	}
	// Y velocity in meters per second
	void SetLunarVelocityY( double value )
	{
		m_dLunarVelocityY = value;
	}
	// Y velocity in meters per second
	__declspec( property( get = GetLunarVelocityY, put = SetLunarVelocityY ) )
		double LunarVelocityY;

	// distance to moon in meters from Earth
	double GetLunarDistance()
	{
		return m_dLunarDistance;
	}
	// distance to moon in meters from Earth
	void SetLunarDistance( double value )
	{
		m_dLunarDistance = value;
	}
	// distance to moon in meters from Earth
	__declspec( property( get = GetLunarDistance, put = SetLunarDistance ) )
		double LunarDistance;

	// radius of lunar orbit around the earth on the screen
	double GetLunarInches()
	{
		return m_dLunarInches;
	}
	// radius of lunar orbit around the earth on the screen
	void SetLunarInches( double value )
	{
		m_dLunarInches = value;
	}
	// radius of lunar orbit around the earth on the screen
	__declspec( property( get = GetLunarInches, put = SetLunarInches ) )
		double LunarInches;

	// lunar distance scale meters to inches on screen
	double GetLunarScaling()
	{
		const double dLunarDistance = LunarDistance;
		const double dLunarInches = LunarInches;
		const double value = dLunarDistance / dLunarInches;
		LunarScaling = value;
		return value;
	}
	// lunar distance scale meters to inches on screen
	void SetLunarScaling( double value )
	{
		m_dLunarScaling = value;
	}
	// lunar distance scale meters to inches on screen
	__declspec( property( get = GetLunarScaling, put = SetLunarScaling ) )
		double LunarScaling;

	// given a distance in meters, return the number of inches on the screen
	double GetLunarScreenInches( double meters )
	{
		const double scale = LunarScaling;
		const double value = meters / scale;
		return value;
	}
	// given a distance in meters, return the number of inches on the screen
	__declspec( property( get = GetLunarScreenInches ) )
		double LunarScreenInches[];

	// X coordinate of the moon in meters relative to earth
	double GetLunarX()
	{
		return m_dLunarX;
	}
	// X coordinate of the moon in meters relative to earth
	void SetLunarX( double value )
	{
		m_dLunarX = value;
	}
	// X coordinate of the moon in meters relative to earth
	__declspec( property( get = GetLunarX, put = SetLunarX ) )
		double LunarX;

	// Y coordinate of the moon in meters relative to earth
	double GetLunarY()
	{
		return m_dLunarY;
	}
	// Y coordinate of the moon in meters relative to earth
	void SetLunarY( double value )
	{
		m_dLunarY = value;
	}
	// Y coordinate of the moon in meters relative to earth
	__declspec( property( get = GetLunarY, put = SetLunarY ) )
		double LunarY;

	// angle in degrees of the earth
	double GetEarthAngleInDegrees()
	{
		return m_dEarthAngle;
	}
	// angle in degrees of the earth
	void SetEarthAngleInDegrees( double value )
	{
		m_dEarthAngle = value;
	}
	// angle in degrees of the earth
	__declspec( property( get = GetEarthAngleInDegrees, put = SetEarthAngleInDegrees ) )
		double EarthAngleInDegrees;

	// velocity in meters per second
	double GetEarthVelocity()
	{
		return m_dEarthVelocity;
	}
	// velocity in meters per second
	void SetEarthVelocity( double value )
	{
		m_dEarthVelocity = value;
	}
	// velocity in meters per second
	__declspec( property( get = GetEarthVelocity, put = SetEarthVelocity ) )
		double EarthVelocity;

	// X velocity in meters per second
	double GetEarthVelocityX()
	{
		return m_dEarthVelocityX;
	}
	// X velocity in meters per second
	void SetEarthVelocityX( double value )
	{
		m_dEarthVelocityX = value;
	}
	// X velocity in meters per second
	__declspec( property( get = GetEarthVelocityX, put = SetEarthVelocityX ) )
		double EarthVelocityX;

	// Y velocity in meters per second
	double GetEarthVelocityY()
	{
		return m_dEarthVelocityY;
	}
	// Y velocity in meters per second
	void SetEarthVelocityY( double value )
	{
		m_dEarthVelocityY = value;
	}
	// Y velocity in meters per second
	__declspec( property( get = GetEarthVelocityY, put = SetEarthVelocityY ) )
		double EarthVelocityY;

	// distance to earth in meters from sun
	double GetEarthDistance()
	{
		return m_dEarthDistance;
	}
	// distance to earth in meters from sun
	void SetEarthDistance( double value )
	{
		m_dEarthDistance = value;
	}
	// distance to earth in meters from sun
	__declspec( property( get = GetEarthDistance, put = SetEarthDistance ) )
		double EarthDistance;

	// radius of earth orbit around the sun on the screen
	double GetEarthInches()
	{
		return m_dEarthInches;
	}
	// radius of earth orbit around the sun on the screen
	void SetEarthInches( double value )
	{
		m_dEarthInches = value;
	}
	// radius of earth orbit around the sun on the screen
	__declspec( property( get = GetEarthInches, put = SetEarthInches ) )
		double EarthInches;

	// solar distance scale meters to inches on screen
	double GetEarthScaling()
	{
		const double dEarthDistance = EarthDistance;
		const double dEarthInches = EarthInches;
		const double value = dEarthDistance / dEarthInches;
		EarthScaling = value;
		return value;
	}
	// solar distance scale meters to inches on screen
	void SetEarthScaling( double value )
	{
		m_dEarthScaling = value;
	}
	// solar distance scale meters to inches on screen
	__declspec( property( get = GetEarthScaling, put = SetEarthScaling ) )
		double EarthScaling;

	double GetEarthScreenInches( double meters )
	{
		const double scale = EarthScaling;
		const double value = meters / scale;
		return value;
	}
	// given a distance in meters, return the number of inches on the screen
	__declspec( property( get = GetEarthScreenInches ) )
		double EarthScreenInches[];

	// X coordinate of the earth in meters relative to sun
	double GetEarthX()
	{
		return m_dEarthX;
	}
	// X coordinate of the earth in meters relative to sun
	void SetEarthX( double value )
	{
		m_dEarthX = value;
	}
	// X coordinate of the earth in meters relative to sun
	__declspec( property( get = GetEarthX, put = SetEarthX ) )
		double EarthX;

	// Y coordinate of the earth in meters relative to sun
	double GetEarthY()
	{
		return m_dEarthY;
	}
	// Y coordinate of the earth in meters relative to sun
	void SetEarthY( double value )
	{
		m_dEarthY = value;
	}
	// Y coordinate of the earth in meters relative to sun
	__declspec( property( get = GetEarthY, put = SetEarthY ) )
		double EarthY;

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

	// mass of the sun in kilograms
	double GetMassOfTheSun()
	{
		return m_dMassOfTheSun;
	}
	// mass of the sun in kilograms
	void SetMassOfTheSun( double value )
	{
		m_dMassOfTheSun = value;
	}
	// mass of the sun in kilograms
	__declspec( property( get = GetMassOfTheSun, put = SetMassOfTheSun ) )
		double MassOfTheSun;

	// acceleration of gravity on the moon due to the earth
	double GetLunarEarthGravity()
	{
		// g = G*M/R^2
		// g is the acceleration of gravity being calculated
		// G is the gravitational constant (6.657 x 10^-11 Nm2kg-2)
		// M is the mass of the earth in kg
		// R is radius (distance to the moon) in meters
		const double dG = 6.657e-11;
		const double dM = MassOfTheEarth;
		const double dR = LunarDistance;
		const double dR2 = dR * dR;
		m_dLunarEarthGravity = dG * dM / dR2;
		return m_dLunarEarthGravity;
	}
	// acceleration of gravity on the moon due to the earth
	__declspec( property( get = GetLunarEarthGravity ) )
		double LunarEarthGravity;

	// X vector of earth/lunar gravity
	double GetLunarAx()
	{
		return m_dLunarAx;
	}
	// X vector of earth/lunar gravity
	void SetLunarAx( double value )
	{
		m_dLunarAx = value;
	}
	// X vector of earth/lunar gravity
	__declspec( property( get = GetLunarAx, put = SetLunarAx ) )
		double LunarAx;

	// Y vector of earth/lunar gravity
	double GetLunarAy()
	{
		return m_dLunarAy;
	}
	// Y vector of earth/lunar gravity
	void SetLunarAy( double value )
	{
		m_dLunarAy = value;
	}
	// Y vector of earth/lunar gravity
	__declspec( property( get = GetLunarAy, put = SetLunarAy ) )
		double LunarAy;

	// acceleration of gravity on the earth due to the sun
	double GetEarthSolarGravity()
	{
		// g = G*M/R^2
		// g is the acceleration of gravity being calculated
		// G is the gravitational constant (6.657 x 10^-11 Nm2kg-2)
		// M is the mass of the earth in kg
		// R is radius (distance to the moon) in meters
		const double dG = 6.657e-11;
		const double dM = MassOfTheSun;
		const double dR = EarthDistance;
		const double dR2 = dR * dR;
		m_dEarthSolarGravity = dG * dM / dR2;
		return m_dEarthSolarGravity;
	}
	// acceleration of gravity on the earth due to the sun
	__declspec( property( get = GetEarthSolarGravity ) )
		double EarthSolarGravity;

	// X vector of sun/earth gravity
	double GetEarthAx()
	{
		return m_dEarthAx;
	}
	// X vector of sun/earth gravity
	void SetEarthAx( double value )
	{
		m_dEarthAx = value;
	}
	// X vector of sun/earth gravity
	__declspec( property( get = GetEarthAx, put = SetEarthAx ) )
		double EarthAx;

	// Y vector of sun/earth gravity
	double GetEarthAy()
	{
		return m_dEarthAy;
	}
	// Y vector of sun/earth gravity
	void SetEarthAy( double value )
	{
		m_dEarthAy = value;
	}
	// Y vector of sun/earth gravity
	__declspec( property( get = GetEarthAy, put = SetEarthAy ) )
		double EarthAy;

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
