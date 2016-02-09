#ifndef _myfile_h
#define _myfile_h

#include <string>
using namespace std;

class CFileReaderException
{
};

class CFileReader
{
protected:
	string m_str;
public:
	CFileReader();
	string readfile(const string & filename);
	string get();
private:
	bool m_initialized;
};

class CFileWriterException
{
};

class CFileWriter
{
protected:
	string m_str;
	string m_filename;
public:
	CFileWriter();
	void writefile(const string & filename, const string & str);
	void appendfile(const string & str);
	void appendfile(const string & filename, const string & str);
	string get(); // throw CFileReaderException;
private:
	bool m_initialized;
};


#endif //_myfile_h
