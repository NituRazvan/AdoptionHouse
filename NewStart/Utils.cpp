#include "Utils.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string trim(const string& s)
{
	string result(s);
	size_t pos = result.find_first_not_of(" ");
	if (pos != -1)
		result.erase(0, pos);
	pos = result.find_last_not_of(" ");
	if (pos != string::npos)
		result.erase(pos + 1);

	return result;
}

vector<string> tokenize(const string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}