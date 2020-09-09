#include <iostream>
#include <set>
#include <string>
using namespace std;

struct train
{
	int number = 0;
	string name = "";
	float time = 0;
	train* next = nullptr;
};

class TrainRivne
{
public:
	train* Add(train* Head, int Number)
	{
		Number--;
		train* NewItem = new(train);
		cout << "Enter number train: ";
		while (!(cin >> NewItem->number) || Find(Head, NewItem->number) == true)
		{
			cout << "This number is already listed!" << endl;
			cout << "Enter number again: ";
		}
		cout << "Destination: ";
		cin >> NewItem->name;
		cout << "Arrival time: ";
		while (!(cin >> NewItem->time) || Time(Head, NewItem->time) == true)
		{
			cout << "Time is entered incorrectly!!!" << endl;
			cout << "Enter time again: ";
		}
		NewItem->next = nullptr;
		if (Head == nullptr)
		{
			Head = NewItem;
		}
		else
		{
			train* Curr = Head;
			for (int i = 1; i < Number&& Curr->next != nullptr; i++)
			{
				Curr = Curr->next;
			}
			if (Number == 0)
			{
				NewItem->next = Head;
				Head = NewItem;
			}
			else
			{
				if (Curr->next != nullptr)
				{
					NewItem->next = Curr->next;
				}
				Curr->next = NewItem;
			}
		}
		return Head;
	}
	bool Find(train* Head, int NumberItem)
	{
		train* ptr;
		ptr = Head;
		while (ptr != nullptr)
		{
			if (NumberItem == ptr->number)
			{
				return 1;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		return 0;
	}

	bool Time(train* Head, float TimeItem)
	{
		float n1, n2;
		n1 = modf(TimeItem, &n2);
		if ((n2 > 24) || (n1 > 0.60) || (TimeItem < 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void Print(train* Head)
	{
		if (Head == nullptr)
		{
			cout << "List is empty!" << endl;
		}
		else
		{
			while (Head != nullptr)
			{
				cout << "Number\t" << "Destination\t" << "Arrival time" << endl;
				cout << Head->number << "\t" << Head->name << "\t\t" << Head->time << endl;
				Head = Head->next;
			}
		}
	}
	void Show(train* Head)
	{
		cout << "Number\t" << "Destination\t" << "Arrival time" << endl;
		cout << Head->number << "\t" << Head->name << "\t\t" << Head->time << endl;
	}
	void Delete(train* Head)
	{
		if (Head != nullptr)
		{
			Delete(Head->next);
			delete Head;
		}
	}
	void FindNumber(train* Head)
	{
		train* ptr = Head;
		int NumberItem = 0;
		cout << "Input train number: ";
		cin >> NumberItem;
		while (ptr != nullptr)
		{
			if (NumberItem == ptr->number)
			{
				Show(ptr);
				return;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		cout << "No such train was found" << endl;
	}
	void FindNameStation(train* Head)
	{
		train* ptr = Head;
		string name = "";
		cout << "Input station name: ";
		cin >> name;
		while (ptr != nullptr)
		{
			if (name == ptr->name)
			{
				Show(ptr);
				return;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		cout << "No such station was found" << endl;
	}

	void FindTime(train* Head)
	{
		train* ptr = Head;
		int NumberItem = 0;
		cout << "Input train number: ";
		cin >> NumberItem;
		while (ptr != nullptr)
		{
			if (NumberItem == ptr->time)
			{
				Show(ptr);
				return;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		cout << "No such train was found" << endl;
	}
};



int main()
{

	TrainRivne tra;
	train* Head = nullptr;
	int n = 1;
	int d = 0;
	do
	{
		cout << "1 - Add train info to DB" << endl;
		cout << "2 - Show DB" << endl;
		cout << "3 - Show info about train for number" << endl;
		cout << "4 - Show info about train for name station" << endl;
		cout << "5 - Show info about train for time" << endl;
		cout << "6 - Exit!" << endl;
		cout << "Please select: ";
		cin >> d;
		switch (d)
		{
		case 1:
		{
			Head = tra.Add(Head, n);
			n++;
		}break;
		case 2:
		{
			tra.Print(Head);
		}break;
		case 3:
		{
			tra.FindNumber(Head);
		}break;
		case 4:
		{
			tra.FindNameStation(Head);
		}break;
		case 5:
		{
			tra.FindTime(Head);
		}break;
		case 6:
		{
			cout << "Goodbye" << endl;
			tra.Delete(Head);
			exit(0);
		}break;

		default:
			cout << "Error" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (d != 6);

	return 0;
}