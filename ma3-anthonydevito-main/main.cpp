#include <map>
#include <fstream>
#include <string>
#include <vector>
#include "TwitterData.hpp"

using namespace std;

/*
o (1 pts) What piece of data read from the file did you use for the key and why? 
	o I used the username initially because they are unique which is a requirement for a map,
	I switched to category because it was instructed to. Which gave me problem with keys
	because the keys were no longer unique. I got it figured out though.
o (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for 
inserting key-value pairs based on a key? 
	o O(logN)
o (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for 
retrieving data based on a key? 
	o O(logN)
o (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for 
deleting key-value pairs based on a key? 
	o O(logN)
o (2 pts) Assuming that the map is using a red-black tree, what is the worst-case Big-O for 
iterating through the entire map? 
	o O(N)
o (4 pts) Based on the specific algorithm that you used to find and remove a key-value pair 
based on a value, what is the worst-case Big-O? 
	o O(N)
o (4 pts) Based on your conclusions of the tasks that were performed in this assignment, when 
and why should we use a map? 
	o Based on my conclusions of the tasks that were performed in this assigment, we should
	maps when we want to use a unique key to access data about the key. For example in this
	assignment I used the username to hold the users name, email, caterogy, etc. Using a key
	is helpful in quickly in accessing that infomation to print, delete in my case.
*/

ostream& operator<<(ostream& os, const map<string, tuple<string, string, string, string, string>>& info){
for (const auto& [user, infoData] : info)
	{
        os << user << ",\"" << get<0>(infoData) << "," 
            << get<1>(infoData) << "," 
            << get<2>(infoData) << "," 
            << get<3>(infoData) << "," 
            << get<4>(infoData) << "\"" 
            << endl;
    }
    	return os;
	}

int main(int argc, char* argv[])
{
	// mpUserName =  mpActualName = mpEmail = mpCategory = nullptr;
	// mpNumTweets
	// we need a map to store our key-value pairs
	// std::map<keyType, ValueType>; What should the key be? What about the value?
	map<string, tuple<string, string, string, string, string>> info ;
	// Tasks 1(c) and (d) - Read the CSV file and insert the data into the std::map object
	ifstream infile("TwitterAccounts.csv");
	string user;
	string firstName;
	string lastName;
	string email;
	string category;
	string numTweets;
	string grab;
	
	// lexi5,"Last,First,Email,NumTweets,MostViewedCategory"
	while (!infile.eof())
	{
		getline(infile, user, ',');
		getline(infile, grab, '"');
		getline(infile, lastName, ',');
		getline(infile, firstName, ',');
		getline(infile, email, ',');
		getline(infile, numTweets, ',');
		getline(infile, category, '"');
		getline(infile, grab, '\n');
		auto infoData = make_tuple(lastName, firstName, email, numTweets, category);
		info.emplace(user, infoData);
	}
	// Task 1(g) - 1st print - iterate through the std::map and print the key-value pairs; print using a range loop
	for (auto& [user, infoData] : info)
	{
		cout << user << ",\"" << get<0>(infoData) << "," 
			<< get<1>(infoData) << "," 
			<< get<2>(infoData) << "," 
			<< get<3>(infoData) << "," 
			<< get<4>(infoData) << "\"" 
			<< endl;
	}

	// Task 1(e) - remove the key-value pair matching key “ken2005”
	info.erase("ken2005");
	cout << "===============" << endl;
	cout << "erasing ken2005" << endl;
	cout << "===============" << endl;

	// Task 1(g) - 2nd print - iterate through the std::map and print the key-value pairs; print using a for loop using iterators
	for (auto i = info.begin(); i != info.end(); i++)
	{
		auto& user = i->first;
    	auto& infoData = i->second;

		cout << user << ",\"" << get<0>(infoData) << "," 
			<< get<1>(infoData) << "," 
			<< get<2>(infoData) << "," 
			<< get<3>(infoData) << "," 
			<< get<4>(infoData) << "\""
			<< endl;
	}

	// Task 1(f) - remove the key-value pair matching last and first name “Ay,Arslan”
	for (auto i = info.begin(); i != info.end(); i++)
	{
		auto& user = i->first;
    	auto& infoData = i->second;
		if (get<0>(infoData) == "Ay" && get<1>(infoData) == "Arslan")
		{
			info.erase(user);
			cout << "===============" << endl;
			cout << "erasing Ay, Arslan" << endl;
			cout << "===============" << endl;
			break;
		}
	}

	// Task 1(g) - 3rd print - print using a “<< operator for map” . You need to define the operator function in main.cpp
	cout << info << endl;
	//Task 1(h) reorganize the data and store it in a map object where the keys are categories and values are vectors of TwitterData
	map<string, vector<string>> reorginizedData;
	string key;
	for (auto i = info.begin(); i != info.end(); i++){
		auto& user = i->first;
    	auto& infoData = i->second;
		key = get<4>(infoData);
		vector<string> vec;
		if (reorginizedData.find(key) == reorginizedData.end())
		{
		vec.push_back(user);
		vec.push_back(get<0>(infoData));
		vec.push_back(get<1>(infoData));
		vec.push_back(get<2>(infoData));
		vec.push_back(get<3>(infoData));
		reorginizedData.emplace(key, vec);
		}
		else{
		auto& vec = reorginizedData[key];
        vec.push_back(user);
        vec.push_back(get<0>(infoData));
        vec.push_back(get<1>(infoData));
        vec.push_back(get<2>(infoData));
        vec.push_back(get<3>(infoData));
		}
	}
	// Task 1(i) - print (MostViewedCategory, vector of TwitterData) pairs.
	for (auto& [key, vec] : reorginizedData)
	{
		for (int s = 0; s < vec.size(); ++s)
		{
			if (s % 5 == 0)
			{
				cout << endl << key << ": ";
			}
			if (s % 5 == 0)
			{
			cout << vec[s] << ",\"";
			}
			else if (s % 5 == 4)
			{
			cout << vec[s] << "\"";
			}
			else{
				cout << vec[s] << ",";
			}
			
		}
	}
	cout << endl;
	return 0;
}

