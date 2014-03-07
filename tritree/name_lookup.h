#ifndef _name_lookup_h
#define _name_lookup_h
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <map>
#include<set>
#include <fstream>
#include <vector>
#include <string>
using namespace std;



class NameLookup
{
public:
	
	NameLookup();
	
	bool insert(string name);
	void getNextChars(string subString, vector<char>* next);
	int  getNumNamesStartingWith(string nameStarting);
	void getNamesStartingWith(string nameStarting, vector<string> * name_list);
	bool erase(string to_erase);
	
	
private:
	
	struct graphT
	{
		char name;
		int endshere;
		map<char,graphT * > nodemap;
	};
	
	graphT * root;
	int  globalCalls;
    void addChar(string name,graphT * curr);
	void printin(string sofar,graphT * curr);
	void addCharToVec(graphT * curr,vector<char> * next);
	void listofNames(string soFar,graphT * curr ,vector<string>* name_list);
	graphT * getNode(string sofar,graphT * curr);
	
};



#endif

