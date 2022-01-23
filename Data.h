#pragma once
#include <vector>
#include <functional>
using namespace std;
class CData
{
public:
	CData();
	~CData();

	// utility parameter
	double alpha = 0; 
	double beta = 0.1;


	// all customer points
	vector<CPoint> Customers;
	// leader's existing facilities

	// all candidate facility sites, for the leader or follower 
	vector<CPoint> Sites;
	

	// Generate an instance and save it to a file.
	void GenerateInstance(int num_rows_columns, int I, int J);
	
	// read customers and candidate facility sietes from a csv file¡£
	void ReadInstanceFromFile(char* filename);
	
	// Write the customers and candidate sites to a given file.
	void SaveInstance2File(char* filename);

	//split a string by another string, called a pattern.
	std::vector<std::string> split(std::string str, std::string pattern)
};

