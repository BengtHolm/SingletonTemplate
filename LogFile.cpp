// LogFile.cpp: implementation of the CLogFile class.
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "LogFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogFile::CLogFile()
{
	cout << "Creating LogFile" << endl;
	m_reference_count = 0;  // reference count
}

CLogFile::CLogFile( const string& logfilename )
{
	init( logfilename );
}

CLogFile::~CLogFile()
{
	cout << "Deleting LogFile" << endl;
}

bool CLogFile::init( const string& logfilename )
{
	cout << "Initializing Logfile: " << logfilename << endl;
	try
	{
		appendfile( logfilename, "" );
	}
	catch( CFileWriterException& )
	{
		return false;
	}
	return true;
}

bool CLogFile::write( const string& data )
{
	try
	{
		appendfile( data + "\n" );
		cout << "Writing string: " << data << endl;
	}
	catch( CFileWriterException& )
	{
		return false;
	}
	return true;
}

CLogFile* CLogFile::Instance()
{
	if( m_pInstance == 0 )
	{
		m_pInstance = new CLogFile();
	}
	m_pInstance->AddRef(); // reference count
	return m_pInstance;
}

CLogFile* CLogFile::m_pInstance = 0;



