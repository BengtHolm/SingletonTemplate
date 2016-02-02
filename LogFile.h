// LogFile.h: interface for the CLogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGFILE_H__4A9D73D5_7588_11D3_A2E2_00104BB8D7A4__INCLUDED_)
#define AFX_LOGFILE_H__4A9D73D5_7588_11D3_A2E2_00104BB8D7A4__INCLUDED_

#include <string>

#include "myfile.h"

class CLogFile: private CFileWriter
{
public:
	bool write( const std::string& data );
	bool init( const std::string& logfilename );

	static CLogFile* Instance();

protected:
	// singleton
	CLogFile();
	CLogFile( const std::string& logfilename );
	~CLogFile();

	static CLogFile* m_pInstance;

public:
	// reference count
	void AddRef() { ++m_reference_count; }
	void Release()
	{
	   if( --m_reference_count == 0 )
	   {
			delete m_pInstance;
			m_pInstance = 0;
	   }
	}

private:
	// reference count
	unsigned long m_reference_count;
};

#endif // !defined(AFX_LOGFILE_H__4A9D73D5_7588_11D3_A2E2_00104BB8D7A4__INCLUDED_)
