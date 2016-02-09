// SingletonTemplate.cpp : Defines the entry point for the console application.
//

#include "LogFile.h"
#include "singletonImpl.h"

template <>
SingletonImpl< CLogFile > * SingletonImpl< CLogFile >::m_pInstance=0;

void client()
{
	SingletonPtr<SingletonImpl<CLogFile> > pLogFile;
	pLogFile->write( "Writing from client" );
}

int main()
{
	SingletonPtr<SingletonImpl<CLogFile> > pLogFile;

	pLogFile->init( "C:\\singletonTemplate.log" );
	pLogFile->write( "Writing from main" );

	client();

	pLogFile->write( "Writing from main - again" );

	return 0;
}
