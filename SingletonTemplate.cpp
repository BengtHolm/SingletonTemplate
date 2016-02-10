// SingletonTemplate.cpp : Defines the entry point for the console application.
//

#include "LogFile.h"
#include "singletonImpl.h"

template <>
SingletonImpl< CLogFile > * SingletonImpl< CLogFile >::m_pInstance=0;

void client()
{
	SingletonPtr<CLogFile> pLogFile;
	pLogFile->write( "Writing from client" );
}

int main()
{
	SingletonPtr<CLogFile> pLogFile;

	pLogFile->init( "C/home/bengt/exercises/singletonTemplate.log" );
	pLogFile->write( "Writing from main" );

	client();

	pLogFile->write( "Writing from main - again" );

	return 0;
}
