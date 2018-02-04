#include <iostream>
using namespace std;
int main(void)
{
	int simulate = 0;
	float arrivalTime = 0;
	float serviceTime = 0;
	int processRows = 2;
	int processColumns = 2;
	int simulationRows = 0;
	int simulationColumns = 5;
	float simulationTime = 0;
	float* arrivalTimes = 0;
	float* beginTimes = 0;
	float* endTimes = 0;
	float* waitingTimes = 0;
	float* systemTime = 0;
	float averageSyetemTime = 0;
	cout << "Enter number of Processes" << endl;
	cin >> processRows;
	simulationRows = processRows;
	float **processes = 0;
	float **simulation = 0;
	processes = new float *[processRows];
	simulation = new float *[simulationRows];
	arrivalTimes = new float[processRows];
	beginTimes = new float[processRows];
	endTimes = new float[processRows];
	waitingTimes = new float[processRows];
	systemTime = new float[processRows];

	for (int i = 0; i < processRows; i++)
	{
		processes[i] = new float[processColumns];
	}
	for (int i = 0; i < simulationRows; i++)
	{
		simulation[i] = new float[simulationColumns];
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
	cout << "#############################################" << endl;
	cout << "You Have Entered The Following Process Data" << endl;
	cout << "#############################################"<< endl;
	cout << "# NO  # Inter Arrival Time  # Service Time  #"<< endl;
	for (int i = 0; i < processRows; i++)
	{
		cout << "#";
		cout << " ";
		cout <<i+1;
		cout << "   #";
		for (int j = 0; j < processColumns; j++)
		{
			
			if (j == 0)
			{
				cout << " ";
				cout << processes[i][j];
				cout << "                   #";
			}
			else
			{
				cout << " ";
				cout << processes[i][j];
				cout << "             #";
			}
		}
		cout << endl;
		cout << "#############################################"<<endl;
	}

	for (int i = 0; i < processRows; i++)
	{
		if (i == 0)
		{
			arrivalTimes[i] = processes[i][0];
		}
		else
		{
			arrivalTimes[i] = arrivalTimes[i - 1] + processes[i][0];
		}
	}
	for (int i = 0; i < processRows; i++)
	{
		if (i == 0)
		{
			beginTimes[i] = arrivalTimes[i];
		}
		else
		{
			if (arrivalTimes[i] <= (beginTimes[i - 1] + processes[i - 1][1]))
			{
				beginTimes[i] = beginTimes[i-1] + processes[i - 1][1];
			}
			else
			{
				
				beginTimes[i] = arrivalTimes[i];
			}
		}
	}
	for (int i = 0; i < processRows; i++)
	{
		endTimes[i] = beginTimes[i] + processes[i][1];
	}
	for (int i = 0; i < processRows; i++)
	{
		if (i == 0)
		{
			waitingTimes[i] = 0;
		}
		else
		{
			waitingTimes[i] = beginTimes[i] - arrivalTimes[i];
		}
		
	}
	for (int i = 0; i < processRows;i++)
	{
		systemTime[i] = endTimes[i] - arrivalTimes[i];
	}
	cout << "If you want to simulate press 1"<<endl;
	cin >> simulate;
	if (simulate == 1)
	{
		cout << "Please Enter Simulation Time"<<endl;
		cin >> simulationTime;
		cout << "Simulation Output" << endl;
		//Simulation table output formatting
		cout << "################################################################################" << endl;
		cout << "# No  #" << " Arrival Time  #" << " Begin Time  #" << " End Time  #" << " System Time  #" << " Waiting Time  #" << endl;
		for (int i = 0; i < processRows; i++)
		{
			cout << "# ";
			cout << i + 1 << " ";
			cout << "  # ";
			cout << arrivalTimes[i];
			cout << "             # ";
			cout << beginTimes[i];
			cout << "           # ";
			cout << endTimes[i];
			cout << "         # ";
			cout << systemTime[i];
			cout << "            # ";
			cout << waitingTimes[i];
			cout << "             #";
			cout << endl;
		}
		cout << "################################################################################" << endl;
	}
	int compeletedTasks = 0;
	float completedTasksTotalTime = 0;
	float completedTasksTotalWaitingTime = 0;
	float totalUtlization = 0;
	for (int i = 0; i < processRows; i++)
	{
		if (endTimes[i] <= simulationTime)
		{
			compeletedTasks++;
		}
	}

	for (int i = 0; i < compeletedTasks; i++)
	{
		completedTasksTotalTime += systemTime[i];
	}
	cout << "Average System Time:"<<completedTasksTotalTime/(compeletedTasks)<<endl;

	for (int i = 0; i < compeletedTasks; i++)
	{
		completedTasksTotalWaitingTime += waitingTimes[i];
	}
	cout << "Avarage Queue Time:"<<completedTasksTotalWaitingTime/compeletedTasks<<endl;
	
	for (int i = 0; i < compeletedTasks;i++)
	{
		int residue = 0;
		if (i == compeletedTasks - 1)
		{
			if (endTimes[i] < simulationTime)
			{
				residue = simulationTime - endTimes[i];
				totalUtlization += (endTimes[i] - beginTimes[i])+residue;
			}
		}
		else
		{
			totalUtlization += endTimes[i] - beginTimes[i];
		}
		
	}
	cout << "Resource Utlization:"<<totalUtlization/simulationTime<<endl;
	cin >> simulate;
	return 0;
}

