//Data.cpp: Instance-related codes

#include "stdafx.h"
#include "Data.h"
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <algorithm>

#include <fstream> 
#include <string>
#include <iostream>
#include <streambuf> 

// This is the code for manuscript titled "Sequential Competitive Facility Location: Exact and Approximate Algorithms"
// The manuscript is available on http://arxiv.org/abs/2103.04259 .
// Authors: Mingyao Qi, Siqian Shen and Ruiwei Jiang
// Last updated: 12/31/2020 

CData::CData()
{
}

CData::~CData()
{
}

void CData::SaveInstance2File(char* filename)
{
	ofstream oFile;
	oFile.open(filename, ios::out | ios::trunc);
	oFile << Customers.size() << "," << Sites.size() << ", # demand points, # candidate sites" << endl;
	for (int i = 0; i < Customers.size(); i++)
	{
		oFile << Customers[i].x << "," << Customers[i].y << endl;
	}
	for (int i = 0; i < Sites.size(); i++)
	{
		oFile << Sites[i].x << "," << Sites[i].y << endl;
	}
	oFile.close();
}

// Generate an instance and save it to a file.
// num_rows_columns: the maximum horizontal (and vertical) coordinates of the facilities and customers.
// I: number of demand points
// J: number of candidate sites
void CData::GenerateInstance(int num_rows_columns, int I, int J)
{
	Customers.clear();
	Sites.clear();

	vector<CPoint> Points;
	// add all grid points
	for (int j = 1; j < num_rows_columns + 1; j++)
	{
		for (int i = 1; i < num_rows_columns + 1; i++)
		{
			Points.push_back(CPoint(i, j));
		}
	}

	// randomly shuffle the vector
	//int myrandom(int i) { return std::rand() % i; }
	std::random_shuffle(Points.begin(), Points.end()/*,myrandom*/);
	// add to the demand points
	for (int i = 0; i < I; i++)
	{
		Customers.push_back(Points[i]);
	}
	// add to the candidate sites
	for (int j = I; j < I + J; j++)
	{
		Sites.push_back(Points[j]);
	}

	char sName[128];
	sprintf(sName, "instance_%3d_%3d.csv", I, J);
	SaveInstance2File(sName);
}

// read customers and candidate facility sietes from a csv file
void CData::ReadInstanceFromFile(char* filename)
{
	Customers.clear();
	Sites.clear();

	ifstream iFile(filename);
	string   readStr((std::istreambuf_iterator<char>(iFile)), std::istreambuf_iterator<char>());
	iFile.close();
	vector<string> lines;
	vector<string> line;
	CCommon Common;
	lines = Common.split(readStr, "\n");

	// read # demand points and # sites
	line = split(lines[0], ",");
	int I = atoi(line[0].c_str());
	int J = atoi(line[1].c_str());
	for (int i = 1; i < lines.size() && i < I+J+1; i++) // read from the second line
	{
		int x, y;
		line = Common.split(lines[i], ",");
		x = atoi(line[0].c_str());
		y = atoi(line[1].c_str());
		if (i < I + 1)
			Customers.push_back(CPoint(x, y));
		else if (i < I + J + 1)
			Sites.push_back(CPoint(x, y));
	}
}

//split a string by another string, called a pattern.
std::vector<std::string> CData::split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;// extend the string
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}




