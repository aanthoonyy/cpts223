#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "BankData.hpp"

/*
In tasks (i) and (k), the number of buckets increases as we add more data to the
container. Explain how the C++ STL std::unordered_map container would increase
the number of buckets (i.e., size of the hash-table), i.e., how will it calculate the new number
of buckets?
	std::unordered_map would increase the number of buckets by rehashing the table when the
	load factor gets too high. It will calculate the new number of buckets by increasing the
	size to the nearest prime number that is atleast double the original table size.

What is the worst-case Big-O for iterating through the entire unordered map? List
any assumptions that you make
	Worst case would be O(N) because at worst case, it'll have to go through the whole
	map of N size

Assuming that the underlying hash table created cannot be resized, and that the
hash function is poor, what is the worst-case Big-O for inserting key-value pairs based on a
key? List any other assumptions that you make
	Worst case would be O(N) as well, because worst case it'll have to go through the 
	whole map of size N to find a spot

Based on your conclusions of the tasks that were performed in this assignment,
when and why should we use an unordered map?
	We should use an unordered map when storing data that can have a specific ID
	attached to it. For example this assigment we used bank data, but the same
	could be applied to any data of a user like social media. It helps keep data
	organized.

Is an std::unordered_map a robust choice for storing, removing, and searching
bank accounts? Explain
	I'd say yes, do to the nature of a unordered_map, it would be hard to organize data
	which could make accessing data take a long time, i'd assume you'd have millions
	of customers using this service. But if you don't have to do those operations
	frequenetly, it isn't the worst possible solution. 
*/

using namespace std;
int main(int argc, char* argv[])
{
	// Task 0 - we need a unordered map to store our key and mapped values
	// std::unordered_map<keyType, ValueType>; What should the key be? What about the value?
	cout << endl << "Task 0" << endl << endl;
	unordered_map<int, tuple<double, double>> map;
	cout << "unordered map created" << endl;

	
    /*Tasks (c) and (d): parse and read all data from BankAccounts.csv;
	                    insert the data into the std::unordered_map */
	cout << endl << "Tasks (c) and (d)" << endl << endl;
	string grab1;
	string grab2;
	string grab3;
	ifstream infile("BankAccounts.csv");
	while (!infile.eof()){
		getline(infile, grab1, ',');
		getline(infile, grab2, ',');
		getline(infile, grab3, '\n');
		if(grab1 != "AcctNum"){
		auto mapTuple = make_tuple(stod(grab2), stod(grab3));
		map.emplace(stoi(grab1), mapTuple);
		}
	}
	cout << "inserted bankaccount.csv into unordered map" << endl;
	
	//Task (e): Print the bucket number for each of the mapped data
	cout << endl << "Task (e)" << endl << endl;
	for (auto& [grab1, mapTuple] : map)
	{
		cout << "accNum: " << grab1 << ", savings: $" << get<0>(mapTuple) << ", checking: $" 
			<< get<1>(mapTuple) << ", bucket number: " << map.bucket(grab1)
			<< endl;
	}


    //Task (f): Print the number of buckets in the container - 1st print
	cout << endl << "Task (f)" << endl << endl;

	cout << endl << "===============" << endl;
	cout << "bucket count: "<<map.bucket_count() << endl;
	cout << "===============" << endl << endl;


	cout << endl << "Task (g)" << endl << endl;

	//Task (g): Print the max number of elements that can be stored in the container
	cout << "max number of elements that can be stored in a container: " << map.max_size() << endl;	

	
	//Task (j): Print the key-value pairs - 1st print
	cout << endl << "Task (j)" << endl << endl;
	cout << "printing key-value pairs" << endl;
	for (auto& [grab1, mapTuple] : map)
	{
		cout << "accNum: " << grab1 << ", savings: $" << get<0>(mapTuple) << ", checking: $" 
			<< get<1>(mapTuple)
			<< endl;
	}

	//Task (h) : Erase the item with key 11111111
	cout << endl << "Task (h)" << endl << endl;
	map.erase(11111111);
	cout << "===============" << endl;
	cout << "erasing accNum: 11111111" << endl;
	cout << "===============" << endl;



	cout << endl << "Task(i)" << endl << endl;
	/* Task(i) : Add the following BankData values to the container:
                 22222222,8000, 1100.5
                 65733773, 10000, 755.67  */
	cout << "===============" << endl;
	cout << "adding accNum: 22222222" << endl;
	cout << "===============" << endl;
	auto mapTuple = make_tuple(8000, 1100.5);
	map.emplace(22222222, mapTuple);

	cout << "===============" << endl;
	cout << "adding accNum: 65733773" << endl;
	cout << "===============" << endl << endl;
	mapTuple = make_tuple(10000, 755.67);
	map.emplace(65733773, mapTuple);


	cout << endl << "Task (j)" << endl << endl;
	//Task (j): Print the key-value pairs - 2nd print
	cout << "printing key-value pairs" << endl;
	for (auto& [grab1, mapTuple] : map)
	{
		cout << "accNum: " << grab1 << ", savings: $" << get<0>(mapTuple) << ", checking: $" 
			<< get<1>(mapTuple)
			<< endl;
	}
	

    //Task (f): Print the number of buckets in the container - 2nd print
	cout << endl << "Task (f)" << endl;
	cout << endl << "===============" << endl;
	cout << "bucket count: "<<map.bucket_count() << endl;
	cout << "===============" << endl << endl;


	cout << endl << "Task (k)" << endl;
    /* Task(k) : Insert 100 additional accounts to the unordered_map container. You should randomly generate the account numbers, checking and saving balances of each BankData object.  
        * For account number : randomly generate a number between 50000000 and 99999999
        * For checking and savings accounts: randomly generate balances between 500 and 19000. You can simply generate integers without decimal points. 
        * After inserting each account, check the number of buckets. If the bucket size has increased (i.e., the hash table is re-hashed), print the new bucket size. See appendix for example output. */
	srand((unsigned) time(NULL));
	int numBuckets = map.bucket_count();
	for (int i = 0; i < 100; i++)
	{
		int accNum = rand()%(99999999-50000000 + 1) + 50000000;
		double checking = rand()%(19000-500 + 1) + 500;
		double savings = rand()%(19000-500 + 1) + 500;
		auto mapTuple = make_tuple(savings, checking);
		map.emplace(accNum, mapTuple);

		if (map.bucket_count() > numBuckets)
		{
			numBuckets = map.bucket_count();
			cout << "===============" << endl;
			cout << "bucket size increased!" << endl;
			cout << "bucket count: "<<map.bucket_count() << endl;
			cout << "===============" << endl;
		}

		cout << "inserted: accNum: " << accNum <<", savings: $" 
			<< savings << ", checking: $" << checking 
			<< ", bucket count: " << map.bucket_count() 
			<< endl;

	}
	
	return 0;

}