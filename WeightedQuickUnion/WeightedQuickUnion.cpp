// hw1.cpp : Defines the entry point for the console application.
//

#include "iostream"

using namespace std;
class quickUnion
{
public:
	int*id;
	int*weight;
	quickUnion();
	quickUnion(int n);
	int root(int i);
	bool connected(int p, int q);
	void Union(int p, int q);

};

quickUnion::quickUnion()
{
	id = new int[0];
	weight = new int[0];
}
quickUnion::quickUnion(int n)
{
	id = new int[n];
	weight = new int[n];
	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		weight[i] = 0;
	}
}
int quickUnion::root(int i)
{
	while (i != id[i])
	{
		i = id[i];
	}
	return i;
}
bool quickUnion::connected(int p, int q)
{
	return (root(p) == root(q));
}
void quickUnion::Union(int p, int q)
{
	if (connected(p, q))
	{
		cout << "Connected" << endl;
	}
	else
	{
		int i = root(p);
		int j = root(q);
		if (weight[i]< weight[j])
		{
			id[j] = i;
			weight[i] += weight[j];
		}
		else if (weight[i] == weight[j])
		{
			id[i] = j;
			weight[j]++;
		}
		else
		{
			id[i] = j;
			weight[j] += weight[i];

		}


	}
}
int main()
{

	int dataNum;
	int runtime;
	while (cin >> dataNum)
	{
		quickUnion node(dataNum);
		for (int i = 0; i < dataNum; i++)
		{

			if (i == dataNum - 1)
			{
				cout << i << endl;
			}
			else
				cout << i << " ";
		}
		for (int i = 0; i < dataNum; i++)
		{

			if (i == dataNum - 1)
			{
				cout << node.id[i];
				cout << endl;
			}
			else
				cout << node.id[i] << " ";
		}
		for (int i = 0; i < dataNum; i++)
		{

			if (i == dataNum - 1)
			{
				cout << node.weight[i];
				cout << endl;
			}
			else
				cout << node.weight[i] << " ";
		}
		cin >> runtime;

		for (int i = 0; i < runtime; i++)
		{
			int p, q;
			cin >> p >> q;
			node.Union(p, q);

			for (int i = 0; i < dataNum; i++)
			{

				if (i == dataNum - 1)
				{
					cout << i << endl;
				}
				else
					cout << i << " ";
			}
			for (int i = 0; i < dataNum; i++)
			{

				if (i == dataNum - 1)
				{
					cout << node.id[i];
					cout << endl;
				}
				else
					cout << node.id[i] << " ";
			}
			for (int i = 0; i < dataNum; i++)
			{

				if (i == dataNum - 1)
				{
					cout << node.weight[i];
					cout << endl;
				}
				else
					cout << node.weight[i] << " ";
			}
		}
	}

	return 0;
}

