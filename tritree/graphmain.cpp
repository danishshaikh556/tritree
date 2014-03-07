#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "name_lookup.h"




#include<map>
#include<set>

#include <fstream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
ostream &operator<<(ostream &os, const std::vector<T> &v)
{
  for (typename vector<T>::const_iterator i = v.begin(); i != v.end(); ++i)
  {
    os << *i << std::endl;
  }

  return os;
}


int main()
{
	 string names[] = {"AKRON", "ALABASTER", "ALBERT", "ALBERTA", "ALBERTON", "ALBERTVILLE", "ALEXANDER CITY", "ALEXANDRIA"};
  int num_names = sizeof(names)/sizeof(names[0]);
  bool ret;

	NameLookup lookup;
	//Graph lookup("danish");

	for (int i = 0; i < num_names; ++i)
  {
    ret = lookup.insert(names[i]);
    assert(ret);
  }


	// Should return ['\0', 'A', 'O', 'V']
	vector<char> next;
	lookup.getNextChars("ALBERT", &next);
	cout << "Valid characters after 'ALBERT':" << endl;
	cout << next;
	cout << endl;

	// Should return 4
	int count = lookup.getNumNamesStartingWith("ALB");
	cout << "Count of valid names after 'ALB' is: " << count << endl;
	cout << endl;

	 // Should return ["ALEXANDER CITY", "ALEXANDRIA"]
	vector<string> name_list;
	lookup.getNamesStartingWith("ALE", &name_list);
	cout << "Valid names after 'ALE':" << endl;
	cout << name_list << endl;

	// Should return ["ALEXANDER CITY"]
    ret = lookup.erase("ALEXANDRIA");
    assert(ret);
    cout << "Remove ALEXANDRIA" << endl;
    cout << endl;

	vector<string> name_list1;
	lookup.getNamesStartingWith("ALE", &name_list1);
	cout << "Valid names after 'ALE':" << endl;
	cout << name_list1 << endl;
     
	
    // Erasing non-existent names should return false
    ret = lookup.erase("DOES NOT EXIST");
    assert(!ret);
/*
    name_list.clear();
    lookup.getNamesStartingWith("ALE", &name_list);
   cout << "Valid names after 'ALE':" << endl;
   cout << name_list << endl;
  
 
    */




	
	int yu;
	cout<<"thsfisend"<<endl;
	cin>>yu;

	return 0;
}
