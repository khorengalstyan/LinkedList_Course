#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct usanox
{
	char azganun[20];
	int gnahatakan;
	int bacakayutyun;
};

struct node
{
	usanox x; 
	node* next; 
	node* prev;
};

class list
{
	node* head;
public:list() :head(NULL) {}

	  void add_last();
	  void add_first();
	  void add_med();
	  void del_first();
	  void del_med();
	  void del_last();
	  void show();
	  int length();
	  void info();
	  void swap();
	  double average();
	  void newlist_average();
	  usanox read();
	  void menu();
	  ~list();
};
void list::menu()

{
	cout << endl;
	cout << "              ՄԵՆՅՈՒ      " << endl;
	cout << "1.Ցուցակի տպում" << endl;
	cout << "2.Ցուցակի սկզբից ցուցակի միավորի ավելացում" << endl;
	cout << "3.Ցուցակի վերջից ցուցակի միավորի ավելացում" << endl;
	cout << "4.Ցուցակի տրված տեղում ցուցակի միավորի ավելացում" << endl;
	cout << "5.Ցուցակի սկզբից ցուցակի միավորի հեռացում" << endl;
	cout << "6.Ցուցակի վերջից ցուցակի միավորի հեռացում" << endl;
	cout << "7.Ցուցակի տրված տեղից ցուցակի միավորի հեռացում" << endl;
	cout << "8.Ցուցակի երկու կամայական միավորի փոխանակում" << endl;
	cout << "9.Միավորի փնտրում" << endl;
	cout << "10.Ուսանողների միջին գնահատական" << endl;
	cout << "11.Միջինից ցածր գնահատական ունեցողների տվյալ" << endl;
	cout << "12.Ելք" << endl;
}

int list::length()
{
	node* temp = head;
	int l = 0;
	while (temp != NULL)
	{
		l++;
		temp = temp->next;
	}

	return l;
}

usanox list::read()
{
	usanox  y;
	cout << "Ազգանուն:";
	cin >> y.azganun;

	do
	{
		cout << "Բացակայություն:";
		cin >> y.bacakayutyun;
	} while (y.bacakayutyun < 0);

	do
	{
		cout << "Գնահատական:";
		cin >> y.gnahatakan;
	} while (y.gnahatakan < 0 || y.gnahatakan>100);

	return y;
}

double list::average()
{
	node* temp = head;
	double mij = 0;
	int erk = length();
	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			mij += temp->x.gnahatakan;
			temp = temp->next;
		}
		mij += temp->x.gnahatakan;
		cout << "Միջին գնահատական = " << mij / erk << endl;

		return mij / erk;
	}
	else
	{
		cout << "Դատարկ է" << endl;
		return NULL;
	}
}
void list::newlist_average()
{
	{
		node* temp = head;
		int qanak = 0;
		double gnah = average();
		if (temp != NULL)
		{
			while (temp->next != NULL)
			{
				if (temp->x.gnahatakan < gnah)
				{
					cout << temp->x.azganun << "  " << temp->x.bacakayutyun << endl;
					qanak++;
				}
				temp = temp->next;
			}
			if (temp->x.gnahatakan < gnah)
			{
				cout << temp->x.azganun << "  " << temp->x.bacakayutyun << endl;
				qanak++;
			}
			if (qanak == 0)
			{
				cout << "Այդպիսիք չկան" << endl;
			}
		}
	}
}

void list::info()
{
	node* temp = head;

	if (temp != NULL)
	{
		int l;
		char pnt[50]; int gnah, bacaka;
		do
		{
			cout << "1.Փնտրում ըստ ազգանվան" << endl;
			cout << "2.Փնտրում ըստ գնահատականի" << endl;
			cout << "3.Փնտրում ըստ բացակայության" << endl;
			cout << "4.Ելք" << endl;
			cin >> l;
			switch (l)
			{
			case 1:
			{
				int  qanak = 0;
				cout << "Փնտրվող ազգանուն:"; cin >> pnt;
				temp = head;
				while (temp != NULL)
				{
					if (strcmp(temp->x.azganun, pnt) == 0)
					{
						cout << temp->x.azganun << " " << temp->x.bacakayutyun << " " << temp->x.gnahatakan << endl;
						qanak++;
					}
					temp = temp->next;
				}

				if (qanak == 0) cout << "Այդպիսի մարդ չկա" << endl;
				break;
			}
			case 2:
			{
				int qanak1 = 0;
				temp = head;
				do
				{
					cout << "Փնտրվող գնահատական:"; cin >> gnah;
				} while (gnah < 0 || gnah>100);
				while (temp != NULL)
				{
					if (temp->x.gnahatakan == gnah)
					{
						cout << temp->x.azganun << " " << temp->x.bacakayutyun << " " << temp->x.gnahatakan << endl;
						qanak1++;
					}
					temp = temp->next;
				}

				if (qanak1 == 0) cout << "Այդպիսի մարդ չկա" << endl; break;
			}
			case 3:
			{
				int qanak2 = 0;
				temp = head;
				cout << "Փնտրվող բացակայություն: "; cin >> bacaka;
				while (temp != NULL)
				{
					if (temp->x.bacakayutyun == bacaka)
					{
						cout << temp->x.azganun << " " << temp->x.bacakayutyun << " " << temp->x.gnahatakan << endl;
						qanak2++;
					}
					temp = temp->next;
				}

				if (qanak2 == 0) cout << "Այդպիսի մարդ չկա" << endl; break;
			}
			case 4:
			{   cout << "Փնտրումն ավարտվեց" << endl;
			return;
			}
			default:
			{
				cout << "Սխալ հրաման" << endl; break;
			}
			}
		} while (l != 4);
	}

	else
		cout << "Դատարկ է" << endl;
}

void list::add_first()
{
	node* temp = new node;
	temp->x = read();
	temp->prev = NULL;
	if (head != NULL)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		temp->next = NULL;
		head = temp;
	}
}

void list::add_last()
{
	node* temp = new node;
	node* temp1 = head;
	node* temp2 = head;
	temp->x = read();
	temp->next = NULL;
	if (temp2 != NULL)
	{
		while (temp1 != NULL)
		{
			temp1 = temp1->next;
		}
		temp->prev = temp1;
		temp1 = head;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}

		temp1->next = temp;
	}
	else
	{
		temp->prev = NULL;
		head = temp;
	}
}
void list::add_med()

{
	node* head1 = head;
	node* head2 = head;
	if (head != NULL)
	{
		int hasce;
		do
		{
			cout << "Հասցե=";
			cin >> hasce;
		} while (hasce<1 || hasce>length() + 1);
		if (hasce == 1)
		{
			add_first();
			return;
		}
		if (hasce == length() + 1)
		{
			add_last();

			return;
		}
		{
			for (int i = 1; i < hasce - 1; i++)
				head1 = head1->next;
			node* temp = new node;

			node* head2 = head1->next;
			head1->next = temp;
			temp->prev = head1;
			temp->next = head2;
			head2->prev = temp;
			temp->x = read();
			return;
		}
	}
	else
	{
		node* temp = new node;
		temp->next = NULL;
		temp->prev = NULL;
		temp->x = read();
		head = temp;
	}

	{
		return;
	}
}

void list::del_first()
{
	int erk = length();
	node* temp = head;
	if (temp != NULL)
	{
		if (erk == 1)
		{
			cout << "Ցուցակը դատարկվեց" << endl;
			head = NULL;
			delete head;
			return;
		}
		temp = head->next;
		temp->prev = NULL;
		delete head;
		head = temp;
	}
	else cout << "Դատարկից ջնջել չի կարելի" << endl;
}

void list::del_last()
{
	int l = 0;
	node* temp = head;
	node* temp1 = head;

	if (head != NULL) {
		if (length() == 1)
		{
			cout << "Ցուցակը դատարկվեց" << endl;
			head = NULL;
			delete head;
			return;
		}

		do
		{
			temp1 = temp1->next;
			l++;
		} while (temp1->next != NULL);

		for (int i = 1; i < l; i++)
			temp = temp->next;

		temp->next = NULL;
		delete temp->next;
	}
	else
	{
		cout << "Դատարկից ջնջել չի կարելի" << endl; return;
	}
}

void list::del_med()
{
	int tex;

	if (head != NULL)
	{
		if (length() == 1)
		{
			head = NULL;
			delete head;
			cout << "Ցուցակը դատարկվեց" << endl; return;
		}
		do
		{
			cout << "Դիրք=";
			cin >> tex;
		} while (tex<1 || tex>length());

		node* temp = head;
		node* temp1 = head;
		node* temp2 = head;
		if (tex == 1)
		{
			del_first();
			return;
		}
		if (tex == length())
		{
			del_last();
			return;
		}

		{
			for (int i = 1; i < tex; i++)
				temp = temp->next;
			for (int i = 1; i < tex - 1; i++)
				temp1 = temp1->next;
			for (int i = 1; i < tex + 1; i++)
				temp2 = temp2->next;
		}
		temp1->next = temp2;
		temp2->prev = temp1;
		delete temp;
	}
	else cout << "Դատարկից ջնջել չի կարելի" << endl;
}

void list::show()
{
	node* temp = head;
	if (temp != NULL) {
		while (temp != NULL)
		{
			cout << temp->x.azganun << " " << temp->x.bacakayutyun << " " << temp->x.gnahatakan << endl;
			temp = temp->next;
		}
	}
	else cout << "Դատարկ է" << endl;
}

void list::swap()
{
	int l, k;
	node* temp = head;
	node* temp1 = head;
	if (length() >= 2)
	{
		do
		{
			cout << "l=";
			cin >> l;
			cout << "k=";
			cin >> k;
		} while (l<1 || l>length() || k<1 || k>length());
		if (l < k)
		{
			for (int i = 1; i < l; i++)
				temp = temp->next;
			for (int i = 1; i < k; i++)
				temp1 = temp1->next;

			usanox t;
			t = temp->x;
			temp->x = temp1->x;
			temp1->x = t;
		}
		else
		{
			for (int i = 1; i < k; i++)
				temp = temp->next;
			for (int i = 1; i < l; i++)
				temp1 = temp1->next;

			usanox t;
			t = temp->x;
			temp->x = temp1->x;
			temp1->x = t;
		}
		if (l == k) cout << "Բան չփոխվեց" << endl;
	}
	else cout << "Բավական տարրեր չկան";
}
list::~list()
{
	while (head != NULL)
	{
		node* temp = head->next;
		delete head;
		head = temp;
	}
};

int main()

{
	int l;
	list ob;
	do {
		ob.menu();

		{
			cin >> l;
			switch (l)

			{
				
			case 1:
			{
				ob.show();
				break;
			}

			case 2:
			{
				ob.add_first();
				break;
			}

			case 3:
			{
				ob.add_last();
				break;
			}

			case 4:
			{
				ob.add_med();
				break;
			}

			case 5:
			{
				ob.del_first();
				break;
			}

			case 6:
			{
				ob.del_last();
				break;
			}

			case 7:
			{
				ob.del_med();
				break;
			}
			case 8:
			{
				ob.swap();
				break;
			}

			case 9:
			{
				ob.info();
				break;
			}
			case 10:
			{
				ob.average();
				break;
			}
			case 11:
			{
				ob.newlist_average();
				break;
			}
			case 12:
			{
				cout << "Ավարտ";
				break;
			}
			default:
			{
				cout << "Սխալ է ընտրվել" << endl;
				break;
			}
			}
		}
	} while (l != 12);

	return 0;
}