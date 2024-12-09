// Datamaker.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include "Random.h"



void usage();
void write_file( const char * filename, 
				 const int size,
				 const int max_value );

// Command-line has the form
// Datamaker [-help] [filename] [size] [max_value]
// filename will be output.dat if not provided
// size will be 1000 if not provided
// maxvalue will be 32000 if not provided
int main(int argc, char** argv)
{
    using namespace std;
	char * f = new char[ 1024 ];
	strcpy_s( f, 1023, "output.dat" );
	int size = 1000;
	int max_value = 32000;

	// no breaks force triple work with three args
	switch( argc ) {
	case 5:
		if (strcmp( argv[4], "-help") == 0) {
			usage();
			exit(0);
		}
	case 4:
		if (strcmp( argv[3], "-help") == 0) {
			usage();
			exit(0);
		}
		max_value = atoi( argv[3] );
	case 3:
		if (strcmp( argv[2], "-help") == 0) {
			usage();
			exit(0);
		}
		size = atoi( argv[2] );
	case 2:
		if (strcmp( argv[1], "-help") == 0) {
			usage();
			exit(0);
		}
		strcpy_s( f, 1023, argv[1] );
	}

	cout << "Constructing filename=" << f << " with " << size << " random values" << endl;
	write_file( f, size, max_value );
	delete [] f;
	return 0;
}

void write_file( const char * filename, 
				 const int size,
				 const int max_value ) {
	using namespace cs32;
    using namespace std;
	ofstream fout;
	fout.open( filename );
	if (fout.fail()) {
		cout << "Output file opening failed" << endl;
		exit( 1 );
	}
	Random rMaker = Random( max_value );
	for (int cnt = 0; cnt < size; cnt++) {
		fout << rMaker.random() << endl;
	}
	fout.close();
}

void usage() {
    using namespace std;
	cout << "Datamaker [-help] [filename] [size] [max_value]" << endl;
	cout << "filename will be output.dat, if not provided" << endl;
	cout << "size will be 1000, if not provided" << endl;
	cout << "maxvalue will be 32000, if not provided" << endl;
}

