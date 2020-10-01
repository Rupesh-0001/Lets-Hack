#include<iostream>
using namespace std;

struct car
{
	int price;
};

int main()
{
	int testCases;
	int n;
	int profit[25];

	cin>>testCases;											//taking input number of test cases
	for (int i = 0; i < testCases; i++)						// setting all profit values to zero
	{
		profit[i] = 0;
	}

	for (int i = 0; i < testCases; i++)
	{
		cin>>n;												//taking input number of cars in this test case
		struct car c[n+1];
		for (int j = 0; j < n; j++)							//taking input price 
			{
				cin>>c[j].price;
			}	
		for (int i = 0; i < n; i++)							//arranging in ascending order
		{
			for (int j = i+1; j < n; j++)
			{	
				if(c[i].price != 0 && c[j].price != 0 && c[i].price > c[j].price)
				{
					c[n] = c[i];
					c[i] = c[j];
					c[j] = c[n];
					i = 0;

				}
				if(c[i].price == 0 && c[i+1].price != 0)
				{
					c[n] = c[i];
					for (int l = 0; l < n; l++)
					{
						c[l] = c[l+1];
					}
				}
			}
		}
		for (int i = 0; i < n; i++)							//calculating price of all the cars
		{	
			if(c[i].price > i)
			c[i].price = c[i].price - i; 
			else if(c[i].price == 0)
			continue;
			else
			c[i].price = 0;
		}
		for(int j = 0; j < n; j++)
		{
			profit[i] += c[j].price;
			if(profit[i] > 1000000007)
			{
				profit[i] = 1000000007;
				break;
			}	
		}			
		
	}
	for (int i = 0; i < testCases; i++)
	{
		cout<<profit[i]<<endl;
	}

	return 0;
}