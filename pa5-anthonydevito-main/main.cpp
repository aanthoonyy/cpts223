#include "ChainingHash.h"
#include "ProbingHash.h"
#include "ParallelProbingHash.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

//#include "ParallelProbingHash.h" 
#include <omp.h>

#define NUM_THREADS 4  // update this value with the number of cores in your system. 

/*
a. How did the serial implementations for the ChainingHash and ProbingHash
compare to each other? Did you expect the time results obtained? Explain
	The serial implemmentations compared to each other in the logic behind rehashing.
	For rehashing, both rehashed when the load factor 0.75 was reached, and both
	rehashed in a similar matter of making a copy of vector, resizing, emptying 
	the original vector, and then copying vector over. I did not expect the results,
	I would have though probing would have been the slowest because I thought it 
	was by nature. The way it handles collisions is less effiecent.

b.Compare the parallel and serial implementations for the ProbingHash. Did the
parallel implementations provide you with the expected speedup? Explain.
	Both implementations for ProbingHash were similar, just parallel had to be
	adjusted to use the >OMP> library. My search time was faster, but everything
	else was slower. 

c.What could you change in your parallel implementations to improve performance and
speedup? Explain.
	I think the best thing I could chnage would be the efficiency of my code. Making
	sure things were done more streamline probably would help. I think its weird that
	when I did my parallel implementations it used more buckets then serial. That would
	be the first thing I'd investigate into.


*/
using namespace std;
int main()
{
	srand(time(NULL));
	fstream hashAnalysis("HashAnalysis.txt");
	/*Task I (a)- ChainingHash table*/
	hashAnalysis << "---------------------------------------------" 
					<< endl 
					<< "             Chaining Hash table" 
					<< endl
					<<  "---------------------------------------------" 
					<< endl;

		//  create an object of type ChainingHash 
		ChainingHash<int, int> ChainingHash(11);
		// In order, insert values with keys 1 – 1,000,000. For simplicity, the key and value stored are the same. 
		clock_t start=clock();
		for (int i = 1; i <= 1000000; i++)
		{
			ChainingHash.emplace(i,i);
			//cout << "inserted: " << i <<"," << i << endl;
		}
		clock_t end=clock();
    	auto totalTimeInsertC = (double)(end - start)/CLOCKS_PER_SEC;
		
		// Report the total amount of time, in seconds, required to insert the values to ChainingHash table. Write the results to a file called “HashAnalysis.txt”. 
		hashAnalysis << "Chaining Hashing insertion time: " << totalTimeInsertC << " seconds." << endl;
		// Search for the value with key 177 in ChainingHash table. Report the time required to find the value in each table by writing it to the “HashAnalysis.txt” file. 
		start=clock();
		cout << "the key 177 was found at postion (" << ChainingHash.bucket(177)<< ")" << endl;
		end=clock();
    	auto totalTimeSearch177C = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Chaining Hash search time: " << totalTimeSearch177C << " seconds." << endl;
		// Search for the value with key 2,000,000 in ChainingHash table. Report the time required to find the value in each table by writing it to the file.  
		if (ChainingHash.bucket(2000000) != -1)
		{
			start=clock();
			cout << "the key 2,000,000 was found at postion (" << ChainingHash.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2mC = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Chaining Hash failed search time: : " << totalTimeSearch2mC << " seconds." << endl;
		}
		else{
			start=clock();
			cout << "the key 2,000,000 was not found. Returned postion (" << ChainingHash.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2mC = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Chaining Hash failed search time: : " << totalTimeSearch2mC << " seconds." << endl;
		}
		// Remove the value with key 177 from ChainingHash table. Report the time required to remove the value with in each table by writing it to the file.  
		cout << "removing key 177" << endl;
		start=clock();
		ChainingHash.erase(177);
		end=clock();
		auto totalTimeRemoveC = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Chaining Hash deletion time: " << totalTimeRemoveC << " seconds." << endl;
		if (ChainingHash.bucket(177) != -1){
			cout << "177 doesn't get deleted" << endl;
		}
		hashAnalysis << "Table Size: " << ChainingHash.size() << " elements." << endl;
		hashAnalysis << "Bucket Size: " << ChainingHash.bucket_count() << " buckets." << endl;
		hashAnalysis << "Load factor: " << ChainingHash.load_factor() << "." << endl;

		// Also, write to the file the final size, bucket count, and load factor of the hash for ChainingHash table. 

		/* Example output template:
			Chaining insertion time: 
			Chaining search time: 
			Chaining failed search time: 
			Chaining deletion time: 
			Table size: 
			Bucket count: 
			Load factor: 
		*/

	/*Task I (b) - ProbingHash table (using Linear Probing) */
		hashAnalysis << "---------------------------------------------" 
					<< endl 
					<< "             Probing Hash table" 
					<< endl
					<<  "---------------------------------------------" 
					<< endl;
		//  create an object of type ProbingHash 
		ProbingHash<int, int> probHash(11);
		// In order, insert values with keys 1 – 1,000,000. For simplicity, the key and value stored are the same.
		start=clock();
		for (int i = 1; i <= 1000000; i++)
		{
			probHash.emplace(i,i);
			//cout << probHash.bucket_count() << ",";
		}
		end=clock();
    	auto totalTimeInsert = (double)(end - start)/CLOCKS_PER_SEC;
		
		// Report the total amount of time, in seconds, required to insert the values to ProbingHash table. Write the results to a file called “HashAnalysis.txt”. 
		hashAnalysis << "Linear Probing insertion time: " << totalTimeInsert << " seconds." << endl;
		// Search for the value with key 177 in ProbingHash table. Report the time required to find the value in each table by writing it to the “HashAnalysis.txt” file. 

		start=clock();
		cout << "the key 177 was found at postion (" << probHash.bucket(177)<< ")" << endl;
		end=clock();
    	auto totalTimeSearch177 = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Linear Probing search time: " << totalTimeSearch177 << " seconds." << endl;

		// Search for the value with key 2,000,000 in ProbingHash table. Report the time required to find the value in each table by writing it to the file.  
		if (probHash.bucket(2000000) != -1)
		{
			start=clock();
			cout << "the key 2,000,000 was found at postion (" << probHash.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2m = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Linear Probing failed search time: : " << totalTimeSearch2m << " seconds." << endl;
		}
		else{
			start=clock();
			cout << "the key 2,000,000 was not found. Returned postion (" << probHash.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2m = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Linear Probing failed search time: : " << totalTimeSearch2m << " seconds." << endl;
		}
		
		// Remove the value with key 177 from ProbingHash table. Report the time required to remove the value with in each table by writing it to the file.  
		cout << "removing key 177" << endl;
		start=clock();
		probHash.erase(177);
		end=clock();
		auto totalTimeRemove = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Linear Probing deletion time: " << totalTimeRemove << " seconds." << endl;
		if (probHash.bucket(177) != -1){
			cout << "177 doesn't get deleted" << endl;
		}
		hashAnalysis << "Table Size: " << probHash.size() << " elements." << endl;
		hashAnalysis << "Bucket Size: " << probHash.bucket_count() << " buckets." << endl;
		hashAnalysis << "Load factor: " << probHash.load_factor() << "." << endl;
		// Also, write to the file the final size, bucket count, and load factor of the hash for ProbingHash table. 

		/* Example output template:
			Linear Probing insertion time: 
			Linear Probing search time: 
			Linear Probing failed search time: 
			Linear Probing deletion time: 
			Table size: 
			Bucket count: 
			Load factor: 
		*/

	

	/*Task II -  ParallelProbingHash table (using Linear Probing) */
      hashAnalysis << "---------------------------------------------" 
					<< endl 
					<< " Parallel Probing Hash table (Single Thread)" 
					<< endl
					<<  "---------------------------------------------" 
					<< endl;
	  // (a) Using a single thread:  
		//  create an object of type ParallelProbingHash 
		ParallelProbingHash<int, int> parallelProbing(101);
		// Set the number of threads (omp_set_num_threads()) to 1 
		omp_set_num_threads(1);
		/* In an OpenMP parallel region (#pragma omp parallel), in order, insert values with keys 1 – 1,000,000. 
		Inside the parallel region make sure that the value for the iteration number of the loop is shared among all threads. 
		For simplicity, the key and value stored are the same.
        */
	   	
		start=clock();
		#pragma omp parallel for
		for (int i = 1; i <= 1000000; i++)
		{
			parallelProbing.emplace(i,i);
			//cout << probHash.bucket_count() << ",";
		}
		end=clock();
    	auto totalTimeInsertPp = (double)(end - start)/CLOCKS_PER_SEC;
		// Report the total amount of time, in seconds, required to insert the values to ParallelProbingHash table. Write the results to a file called “HashAnalysis.txt”. 
		#pragma omp parallel
		hashAnalysis << "Parallel Linear Probing insertion time: " << totalTimeInsertPp << " seconds." << endl;
		// Search for the value with key 177 in ParallelProbingHash table. Report the time required to find the value in each table by writing it to the “HashAnalysis.txt” file. 

		start=clock();
		#pragma omp parallel
		cout << "the key 177 was found at postion (" << parallelProbing.bucket(177)<< ")" << endl;
		end=clock();
    	auto totalTimeSearch177pp = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Parallel Linear Probing search time: " << totalTimeSearch177pp << " seconds." << endl;

		// Search for the value with key 2,000,000 in ProbingHash table. Report the time required to find the value in each table by writing it to the file.  
		if (parallelProbing.bucket(2000000) != -1)
		{
			start=clock();
			#pragma omp parallel
			cout << "the key 2,000,000 was found at postion (" << parallelProbing.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2mpp = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Parallel Linear Probing failed search time: : " << totalTimeSearch2mpp << " seconds." << endl;
		}
		else{
			start=clock();
			#pragma omp parallel
			cout << "the key 2,000,000 was not found. Returned postion (" << parallelProbing.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2mpp = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Parallel Linear Probing failed search time: : " << totalTimeSearch2mpp << " seconds." << endl;
		}
		
		// Remove the value with key 177 from ProbingHash table. Report the time required to remove the value with in each table by writing it to the file.  
		cout << "removing key 177" << endl;
		start=clock();
		#pragma omp parallel
		parallelProbing.erase(177);
		end=clock();
		auto totalTimeRemovepp = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Parallel Linear Probing deletion time: " << totalTimeRemovepp << " seconds." << endl;
		if (parallelProbing.bucket(177) != -1){
			cout << "177 doesn't get deleted" << endl;
		}
		#pragma omp parallel
		hashAnalysis << "Table Size: " << parallelProbing.size() << " elements." << endl;
		#pragma omp parallel
		hashAnalysis << "Bucket Size: " << parallelProbing.bucket_count() << " buckets." << endl;
		#pragma omp parallel
		hashAnalysis << "Load factor: " << parallelProbing.load_factor() << "." << endl;
		
		// Also, write to the file the final size, bucket count, and load factor of the hash for ParallelProbingHash table. 

		/* Example output template:
			Parallel Probing insertion time: 
			Parallel Probing search time: 
			Parallel Probing failed search time: 
			Parallel Probing deletion time: 
			Table size: 
			Bucket count: 
			Load factor: 
		*/

	// (b) Using multiple threads:  
	      hashAnalysis << "---------------------------------------------" 
					<< endl 
					<< "    Parallel Probing Hash table (Multi Thread)" 
					<< endl
					<<  "---------------------------------------------" 
					<< endl;
		//  create an object of type ParallelProbingHash 
		ParallelProbingHash<int, int> parallelProbing2(101);
		// i.	Change the number of threads to match the number of cores on your system 
		omp_set_num_threads(2);
		/* In an OpenMP parallel region (#pragma omp parallel), in order, insert values with keys 1 – 1,000,000. 
		Inside the parallel region make sure that the value for the iteration number of the loop is shared among all threads. 
		For simplicity, the key and value stored are the same.
        */
	   	
		start=clock();
		//#pragma omp parallel for
		for (int i = 1; i <= 1000000; i++)
		{
			parallelProbing2.emplace(i,i);
			//cout << probHash.bucket_count() << ",";
		}
		end=clock();
    	auto totalTimeInsertPp2 = (double)(end - start)/CLOCKS_PER_SEC;
		// Report the total amount of time, in seconds, required to insert the values to ParallelProbingHash table. Write the results to a file called “HashAnalysis.txt”. 
		
		hashAnalysis << "Parallel Linear Probing insertion time: " << totalTimeInsertPp2 << " seconds." << endl;
		// Search for the value with key 177 in ParallelProbingHash table. Report the time required to find the value in each table by writing it to the “HashAnalysis.txt” file. 

		start=clock();
		#pragma omp parallel
		
		cout << "the key 177 was found at postion (" <<  parallelProbing2.bucket(177) << ")" << endl;
		end=clock();
    	auto totalTimeSearch177pp2 = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Parallel Linear Probing search time: " << totalTimeSearch177pp2 << " seconds." << endl;

		// Search for the value with key 2,000,000 in ProbingHash table. Report the time required to find the value in each table by writing it to the file.  
		if (parallelProbing2.bucket(2000000) != -1)
		{
			start=clock();
			#pragma omp parallel
			cout << "the key 2,000,000 was found at postion (" << parallelProbing2.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2mpp2 = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Parallel Linear Probing failed search time: : " << totalTimeSearch2mpp2 << " seconds." << endl;
		}
		else{
			start=clock();
			#pragma omp parallel
			cout << "the key 2,000,000 was not found. Returned postion (" << parallelProbing2.bucket(2000000)<< ")" << endl;
			end=clock();
    		auto totalTimeSearch2mpp2 = (double)(end - start)/CLOCKS_PER_SEC;
			hashAnalysis << "Parallel Linear Probing failed search time: : " << totalTimeSearch2mpp2 << " seconds." << endl;
		}
		
		// Remove the value with key 177 from ProbingHash table. Report the time required to remove the value with in each table by writing it to the file.  
		cout << "removing key 177" << endl;
		start=clock();
		#pragma omp parallel
		parallelProbing2.erase(177);
		end=clock();
		auto totalTimeRemovepp2 = (double)(end - start)/CLOCKS_PER_SEC;
		hashAnalysis << "Parallel Linear Probing deletion time: " << totalTimeRemovepp2 << " seconds." << endl;
		if (parallelProbing2.bucket(177) != -1){
			cout << "177 doesn't get deleted" << endl;
		}
		hashAnalysis << "Table Size: " << parallelProbing2.size() << " elements." << endl;
		hashAnalysis << "Bucket Size: " << parallelProbing2.bucket_count() << " buckets." << endl;
		hashAnalysis << "Load factor: " << parallelProbing2.load_factor() << "." << endl;
		// Also, write to the file the final size, bucket count, and load factor of the hash for ParallelProbingHash table. 

		/* Example output template:
			Parallel Probing insertion time: 
			Parallel Probing search time: 
			Parallel Probing failed search time: 
			Parallel Probing deletion time: 
			Table size: 
			Bucket count: 
			Load factor: 
		*/
		
	system("clear");
	hashAnalysis.close();
	ifstream hashAnalysis2("HashAnalysis.txt");
	

    string line;
    while (getline(hashAnalysis2, line)) {
        cout << line << endl;
    }
	hashAnalysis2.close();
	return 0;
}