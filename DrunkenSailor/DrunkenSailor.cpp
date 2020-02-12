/*
CSCI 182 - Assignment 3
DrunkenSailor.cpp
Randomly moves a "drunken sailor" throught a 2 dimensional array for a given amount of steps and tracks the amount of time each square is occupied

Landon Reekstin
v1.0 2/12/2020
*/

// defines the global variables
#define ARRAY_WIDTH 20
#define ARRAY_HEIGHT 20
#define MAX_STEPS 1000
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

// type to be used with the "sailor" movement 
enum Direction { NORTH, SOUTH, EAST, WEST };

int nMapArray[ARRAY_WIDTH][ARRAY_HEIGHT];


int main()
{
	// initializes random number generator for direction, no of steps the "sailor" will take, and the starting position
	srand(time(NULL));
	int x = ARRAY_WIDTH / 2;
	int y = ARRAY_HEIGHT / 2;
	int nStepCount = 0;

	// sets all values of the array to 0
	for (int i = 0; i < ARRAY_WIDTH; i++)
	{
		for (int j = 0; j < ARRAY_HEIGHT; j++)
		{
			nMapArray[i][j] = 0;
		}
	}


	// moves the sailor 1 block in a random direction
	while (nStepCount < MAX_STEPS)
	{
		Direction nNextStep = static_cast<Direction>(rand() % 4);
		switch(nNextStep)
		{
case NORTH:
	if (y > 0)
	{
		y--;
	}
	break;
case SOUTH:
	if (y < ARRAY_HEIGHT - 1)
	{
		y++;
	}
	break;
case EAST:
	if (x < ARRAY_WIDTH - 1)
	{
		x++;
	}
	break;
case WEST:
	if (x > 0)
	{
		x--;
	}
	break;

		}

		// increments the step count and the value of the array at the new position after making 1 move
		nStepCount++;
		nMapArray[x][y] = nMapArray[x][y]++;
	}


	// pretty prints values of the array
	for (int i = 0; i < ARRAY_WIDTH; i++)
	{
		for (int j = 0; j < ARRAY_HEIGHT; j++)
		{
			cout << nMapArray[i][j] << "   ";
		}
		cout << endl;
	}

}

