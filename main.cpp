// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	//adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	vector::<Slav>::iterator itr;
	for(int i=0;i<n;i++){
		vectorOfSlavs.push_back(slavs[i]);
			}

/*	for(itr=vectorOfSlavs.begin();itr<=n;++itr){
		vectorOfSlavs.insert(itr, slavs[itr]);

	}*/		
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	itr=vectorOfSlavs.begin();
	for (itr;itr!=vectorOfSlavs.end();++itr){
		//cout<<  vectorOfSlavs[itr].description()<<endl;
		cout<<(*itr)->description()<<endl;
	}


	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	setOfSlavs(make_move_iterator(begin(vectorOfSlavs)),make_move_iterator(end(vectorOfSlavs)));
	vectorOfSlavs.clear();

	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
/*	set::<Slav>::iterator itr2;
	for (itr2=setOfSlavs.begin(); itr2!=setOfSlavs.end(); )
		{
			mapOfSlavs[itr]=itr2+1;
			itr2+=2;
		}
	setOfSlavs.clear();
	*/
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
/*	map::<Slav, Slav>::iterator itr3;
	for (itr3=mapOfSlavs.begin(); itr3!=mapOfSlavs.end(); ++itr3)
	{
		cout<<itr3->first->description()<<itr3->second->description()<<endl;
	}
	mapOfSlavs.clear();*/
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	
/*	for (int i = 0; i < n; ++i)
	{
		queueOfSlavs.push(slavs[i]);
	}*/
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
/*	for (int i = 0; i < n; ++i)
	{
		stackOfSlavs.push(queueOfSlavs[i]);
	}
		for (int i = 0; i < n; ++i)
	{
		queueOfSlavs.pop();
	}*/

	REPORT_ADAPTERS;

/*	// Wyświetl Słowian zdejmowanych ze stosu.
	for (int i = 0; i < n; ++i)
	{
		stackOfSlavs.top.description();
		stackOfSlavs.pop();
	}*/

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
