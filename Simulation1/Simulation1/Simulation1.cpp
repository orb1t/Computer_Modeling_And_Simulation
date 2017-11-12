// Simulation1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <chrono>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	int arrivalTime = 0;//A variable to hold the user's input(Inter Araival Time)
	int serviceTime = 0;//A variable to hold the user's input(Service Time)
	int processRows = 2;//A vribale to hold 
	int processColumns = 2;
	int simulationRows = 0;
	int simulationColumns = 5;
	cout << "Enter number of Processes"<<endl;
	cin >> processRows;
	simulationRows = processRows;
	int **processes = 0;
	int **simulation = 0;
	processes = new int *[processRows];
	simulation = new int *[simulationRows];

	for (int i = 0; i < processRows; i++)
	{
		processes[i] = new int[processColumns];
	}
	for (int i = 0; i < simulationRows; i++)
	{
		simulation[i] = new int[simulationColumns];
	}

	for (int i = 0; i < processRows; i++)
	{
		for (int j = 0; j < processColumns; j++)
		{	
			if (j == 0)
			{
				cout << "Enter Process "<<i+1<<" Inter Arival Time?" << endl;
				cin >> arrivalTime;
				processes[i][j] = arrivalTime;
			}
			else
			{
				cout << "Enter Process " << i + 1 << " Service Time?" << endl;
				cin >> serviceTime;
				processes[i][j] = serviceTime;
			}
			
		}
	}

	for (int i = 0; i < processRows; i++)
	{
		for (int j = 0; j < processColumns; j++)
		{
			cout << "| ";
			cout<<processes[i][j];
			cout << " |";
		}
		cout << endl;
	}

	
	
	cin >> x;
	return 0;
}

