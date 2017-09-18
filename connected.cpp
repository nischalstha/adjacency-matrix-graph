/**
* a program to determine whether an undirected graph is connected 
* assumes vertices labled 0, 1, 2 ...
* uses adjacency matrix representation of a graph
*/

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include "matrix.h"

using namespace std;

/**
* a function to determine if the hardcoded unweighted graph is 
* connected when the graph is stored in the adjacency matrix format 
* @param adjacency matrix
* @return boolean true if connected false if not.
*/

bool is_connected ( const Matrix < bool > & graph )
{
	// Creates an array of boolean declared as all false. 
	vector < bool > reached ( graph.numrows(), false );

	// Creates a queue and pushses the first vertex in it.
	queue < uint8_t > to_be_explored;
	to_be_explored.push( 0 );

	reached.at( 0 ) = true;

	// While the queue is not empty.
	while ( !to_be_explored.empty() )
	{	
		uint8_t current = to_be_explored.front();

		// Pop the vertex from queue.
		to_be_explored.pop();

		for ( uint8_t i = 0 ; i < 4 ; ++i )
		{
			// Check if the current vertex is connected to at least one 
			// other vertex.
			if ( ( graph.at( current , i ) ) && ( !reached.at( i ) ) )
			{
				reached.at( i ) = true;
				to_be_explored.push( i );
			}
		}
	}

	return find ( reached.begin(), reached.end(), false ) == reached.end();
}


int main ()
{	
	// Declaring a matrix of 4 rows and 4 columns.
	Matrix < bool > graph(4, 4);

	// Hardcoded matrix
	graph.at(0, 0) = false;
	graph.at(0, 1) = false;
	graph.at(0, 2) = true;
	graph.at(0, 3) = true;
	graph.at(1, 0) = false;
	graph.at(1, 1) = false;
	graph.at(1, 2) = true;
	graph.at(1, 3) = false;
	graph.at(2, 0) = true;
	graph.at(2, 1) = true;
	graph.at(2, 2) = false;
	graph.at(2, 3) = false;
	graph.at(3, 0) = true;
	graph.at(3, 1) = false;
	graph.at(3, 2) = false;
	graph.at(3, 3) = false;

	// Calls the function and prints "true" if connected, "false" if not.
	cout << boolalpha << is_connected( graph ) << endl;
}


