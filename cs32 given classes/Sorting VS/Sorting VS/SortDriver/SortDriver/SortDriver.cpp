// SortDriver.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>
#include <cstring>
#include "SortRoutine.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"


void dumparray( int array[], int size );
int getlength( char * f );
void fillarray( int array[],  char * f );
void runsort( int array[], int size, cs32::SortRoutine * sr, bool show_results );
void usage();
void fillarraywithinput( int array[], int& size );


typedef int* intArrayPtr;

// Command-line has the form
// SortDriver [-help] [-print] [sorttype] [datafile] 
// sorttype will be bubblesort if not provided
// datafile will be read from cin if not provided
// -print means show sorted array when finished
// by default, runs in no-print mode
int main(int argc, char* argv[])
{
    using namespace cs32;
    
	char * f = new char[ 1024 ];
	bool file_provided = false;
	char * s = new char[ 1024 ];
	bool sort_provided = false;
	bool show_results = false;
	int size = 0;
	intArrayPtr dataarray = nullptr;

	// sorttype datafile
	for (int i = 1; i < argc; ++i) {
		if (strcmp( argv[i], "-help" ) == 0) {
			usage();
			exit(0);
		}
		if (strcmp( argv[i], "-print" ) == 0) {
			show_results = true;
		}
		else if (sort_provided) {
			strcpy_s( f, 1023, argv[i] );
			file_provided = true;
		}
		else {
			strcpy_s( s, 1023, argv[i] );
			sort_provided = true;
		}
	}
	if (!sort_provided)		strcpy_s( s, 1023, "bubblesort" );
	if (file_provided) {
		size = getlength( f );
		dataarray = new int[ size ];
		fillarray( dataarray, f );
	}
	else {
		size = 128;
		dataarray = new int[ 128 ];
		fillarraywithinput( dataarray, size );
	}

	if (strcmp( s, "bubblesort" ) == 0) {
		BubbleSort bs = BubbleSort();
		runsort( dataarray, size, &bs, show_results );
	}
	else if (strcmp( s, "insertionsort" ) == 0) {
		InsertionSort is = InsertionSort();
		runsort( dataarray, size, &is, show_results );
	}
	else if (strcmp( s, "shellsort" ) == 0) {
		ShellSort ss = ShellSort();
		runsort( dataarray, size, &ss, show_results );
	}
	else if (strcmp( s, "mergesort" ) == 0) {
		MergeSort ms = MergeSort();
		runsort( dataarray, size, &ms, show_results );
	}
	else if (strcmp( s, "quicksort" ) == 0) {
		QuickSort qs = QuickSort();
		runsort( dataarray, size, &qs, show_results );
	}
	else if (strcmp( s, "heapsort" ) == 0) {
		HeapSort hs = HeapSort();
		runsort( dataarray, size, &hs, show_results );
	}

	delete [] f;
	delete [] s;
    if (dataarray != nullptr) {
        delete [] dataarray;
    }
    return 0;
}

void dumparray( int array[], int size ) {
    using namespace std;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int getlength( char * filename ) {
    using namespace std;
	ifstream fin;
	int value;
	int size = 0;
	fin.open( filename );
	if (fin.fail()) {
		cout << "Input file opening failed for filename=" << filename << endl;
		exit( 1 );
	}
	while (!fin.eof()) {
		fin >> value;
		size++;
	}
	fin.close();
	return( size - 1 );
}

void fillarray( int array[],  char * filename ) {
    using namespace std;
	ifstream fin;
	int i = 0;
	fin.open( filename );
	if (fin.fail()) {
		cout << "Input file opening failed for filename=" << filename << endl;
		exit( 1 );
	}
	while (!fin.eof()) {
		fin >> array[ i ];
		i++;
	}
	fin.close();
}

void runsort( int array[], int size, cs32::SortRoutine * sr,
			  bool show_results ) {
	sr->sort( array, size );
	if (show_results)
		dumparray( array, size );
	sr->printStats();
}

void usage() {
    using namespace std;
	cout << "SortDriver [-help|-print] [sorttype] [datafile]" << endl;
	cout << "sorttype will be bubblesort, if not provided" << endl;
	cout << "datafile will be read from cin, if not provided" << endl;
	cout << "-print means show sorted array when finished" << endl;
	cout << "by default, runs in silent mode" << endl;
}

void fillarraywithinput( int array[], int& size ) {
    using namespace std;
	string data;
	int k = 0;
	unsigned int startcntr = 0;
	unsigned int endcntr = 0;
	cout << "Enter one line of data to sort" << endl;
	getline( cin, data );
	data += " ";  // in case string does not end with whitespace
	for (endcntr = 0; endcntr < data.length(); ++endcntr) {
		if (isspace(data.at(endcntr)) && startcntr <= endcntr) {
			string bit = data.substr( startcntr, endcntr - startcntr + 1 );
			if (isspace( bit.at(0) )) {
				startcntr = endcntr + 1;
				continue;
			}
			int value = atoi( bit.c_str() );
			array[ k++ ] = value;
			startcntr = endcntr + 1;
		}	
	}
	size = k;
}
