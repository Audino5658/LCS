#include<iostream>
#include<string> 
#include<stdio.h>
#include<memory.h>

using namespace std;
int shor, lon; 
int *curr;
int *pre;

int LCS_Length(char *X, char *Y)
{
    curr = new int [shor+1];
	pre =  new int [shor+1];

    memset(pre, 0, shor+1);
    curr[0] = 0;

	for(int i=0; i<lon ;i++)
	{

	 for(int j=0;j<shor;j++)
	{

		if(X[i]==Y[j])
        {
			curr[j+1] = pre[j]+1;
		}
		else 
		{
		  if(curr[j]>=pre[j+1])
		  {
			  curr[j+1] = curr[j];
		  }
		  else
		   curr[j+1] = pre[j+1]; 
		}
		
	 }
	  
	    for(int j=0;j<=shor;j++)
			pre[j] = curr[j];
	//	memcpy(pre, curr, shor);
	}
	return curr[shor];
}


int main()
{
	char *X, *Y;
	

	string strx, stry;

	cin >> strx;
	cin >> stry;

	if ( stry.length() > strx.length() ) // x row must be longer than Y row
    {
	   shor = strx.length();
	   lon = stry.length();

	   	X = new char [lon+1];
	    Y = new char [shor+1];

	   	strx.copy(Y,shor);
	    stry.copy(X,lon);

	}
	else
	{
	    lon = strx.length();
	    shor = stry.length();

	    X = new char [lon+1];
	    Y = new char [shor+1];

	    strx.copy(X,lon);
	    stry.copy(Y,shor);
	}
     
	X[lon] ='\0';
	Y[shor]='\0';

	cout << "Length of LCS = " << LCS_Length(X,Y) << endl ;


	 delete[] (X);
	 delete[] (Y);
	 delete[] (curr);
	 delete[] (pre);

	system("pause");
	return 0;
}