#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <fstream>

std::string gettime()
{
	time_t currenttime = time(0);
	struct tm tstruct;
	char boiiiiii[80];
	tstruct = *localtime(&currenttime);
	strftime(boiiiiii, sizeof(boiiiiii), "%Y-%m-%d - %X", &tstruct);

	return boiiiiii;
}

void WriteToLog(std::string textToAdd)
{
	std::fstream file_;
	file_.open("CurrentSession.logs", std::fstream::app);
	file_ << gettime() << " -- " << textToAdd << std::endl;
	file_.close();
}

namespace Log
{
	void NewLog(std::string alphabetfromchina)
	{
		WriteToLog(alphabetfromchina);
	}
}