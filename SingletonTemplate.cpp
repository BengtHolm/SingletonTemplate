// SingletonTemplate.cpp : Defines the entry point for the console application.
//

#include "LogFile.h"
#include "singletonImpl.h"


void client()
{
	SingletonPtr<CLogFile> pLogFile;
	pLogFile->write( "Writing from client" );
}

int main()
{
	SingletonPtr<CLogFile> pLogFile;

	pLogFile->init( "/home/bengt/exercises/singletonTemplate.log" );
	pLogFile->write( "Writing from main" );

	client();

	pLogFile->write( "Writing from main - again" );

	return 0;
}
