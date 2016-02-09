#include <fstream>
#include <iterator>
using namespace std;

#include "myfile.h"


CFileReader::CFileReader()
{
	m_initialized = false;
}

string CFileReader::readfile(const string & filename)
{
//vector<char> buffer;
	m_str = "";
	ifstream s (filename.c_str());
	if (s.is_open())
	{
		s.unsetf (ios::skipws);

		istream_iterator<char> it1 (s);
		istream_iterator<char> it2;
		// Serves as "past-the-end" marker.
		for (; it1 != it2; it1++)
			m_str.append(1,*it1);
		//copy (it1, it2, back_inserter (m_str));
		m_initialized = true;
	}
	else
		throw CFileReaderException();
	return m_str;
}

string CFileReader::get()
{

	return m_str;
}

CFileWriter::CFileWriter()
{
	m_initialized = false;
}

void CFileWriter::writefile(const string & filename, const string & str)
{
//vector<char> buffer;
	m_str = str;
	m_filename = filename;
	ofstream s (m_filename.c_str());
	if (s.is_open())
	{
		string::const_iterator it;
		for (it = str.begin(); it != str.end(); it++)
		{
			s.put(*it);
		}
		m_initialized = true;
	}
	else
		throw CFileWriterException();
}

void CFileWriter::appendfile(const string & str)
{
//vector<char> buffer;
	if (!m_initialized)
		throw CFileReaderException();

	m_str.append(str);
	ofstream s (m_filename.c_str(), ios::app);
	if (s.is_open())
	{
		string::const_iterator it;
		for (it = str.begin(); it != str.end(); it++)
		{
			s.put(*it);
		}
	}
	else
		throw CFileWriterException();
}

void CFileWriter::appendfile(const string & filename, const string & str)
{
//vector<char> buffer;
	m_str = "";
	m_filename = filename;
	m_initialized = true;
	appendfile(str);
}

string CFileWriter::get()
{
	return m_str;
}
