#include<iostream>
#include<limits>
using namespace std;

struct node
{
	char name[100];
	char prn[10];
	char position[50];
	struct node* nxt;
};
class Pinnacle_Club
{
	node *head,*list1,*list2,*temp,*old;
public:
	Pinnacle_Club()
	{
		head = NULL;
		list1 = NULL;
		list2 = NULL;
		temp = NULL;
		old = NULL;
	}
public:
	node *create(char name1[],char prn1[],char position[]);
	void add(char name1[],char prn1[],char position[]);
	void del(char prn[]);
	void display();
	void counter();
	void concat();
};

node *Pinnacle_Club::create(char name1[],char prn1[],char position1[])
{
	node *p = new(struct node);
	strcpy(p->name,name1);
	strcpy(p->prn,prn1);
	strcpy(p->position,position1);
	p->nxt = NULL;
	return p;
}

void Pinnacle_Club::display()
{
	temp = head;
	if(head == NULL)
	cout<<"Database Empty"<<endl;
	while(temp != NULL)
	{
		cout<<temp->name<<"\t"<<temp->prn<<"\t"<<temp->position<<endl;
		temp = temp->nxt;
	}

}

void Pinnacle_Club::add(char name1[],char prn1[],char position1[])
{
	if(strcmp(position1,"PRESIDENT") == 0)
	{
		if(head == NULL)
		{
			head = create(name1,prn1,position1);
		}
		else
		{
			node *p = create(name1,prn1,position1);
			p->nxt = head;
			head = p;
		}
	}
	else if(strcmp(position1,"SECRETARY") == 0)
	{
		if(head == NULL)
		{
			head = create(name1,prn1,position1);
		}
		else
		{
			node *p = create(name1,prn1,position1);
			temp = head;
			while(temp->nxt != NULL)
			{
				temp = temp->nxt;
			}
			temp->nxt = p;
		}
	}
	else
	{
		if(head == NULL)
		{
			head = create(name1,prn1,position1);
		}
		else
		{
			if(strcmp(head->position,"PRESIDENT") == 0)
			{
				node *p = create(name1,prn1,position1);
				p->nxt = head->nxt;
				head->nxt = p;
			}
			else if(strcmp(head->position,"SECRETARY") == 0)
			{
				node *p = create(name1,prn1,position1);
				p->nxt = head;
				head = p;
			}
		}
	}
	cout<<"Record created"<<endl;

}

void Pinnacle_Club::del(char prn1[])
{
	bool flag = false;
	temp = head;
	if(strcmp(temp->prn,prn1) == 0)
	{
		head = head->nxt;
		free(temp);
		flag = true;
	}
	else
	{

		while(temp->nxt != NULL)
		{
			old = temp;
			temp = temp->nxt;
			if(strcmp(temp->prn,prn1) == 0){
				old->nxt = temp->nxt;
				free(temp);
				flag = true;
			}



		}
		if(strcmp(temp->prn,prn1) == 0)
		{
			flag = true;
			old->nxt = NULL;
			free(temp);
		}
	}

	if(!flag)
	{
		cout<<"No such PRN Number in the database."<<endl;
	}
	else
	cout<<"Record deleted"<<endl;
}

void Pinnacle_Club::counter()
{
	temp = head;
	int cnt=0;
	if(head == NULL)
	cout<<"Database Empty"<<endl;
	while(temp != NULL)
	{
		cnt++;
		temp = temp->nxt;
	}
	cout<<"The number of members are : "<<cnt<<endl;
}

void Pinnacle_Club::concat(){
	int n1,n2;
	char name[100],prn[10],position[50];
	cout<<"Enter the number of elements of list1 : "<<endl;
	cin >> n1;
	cin.ignore();
	for(int i = 0;i<n1;i++)
	{

		cout<<"Enter the name : "<<endl;
		cin.getline(name,100);
		cout<<"Enter the PRN : "<<endl;
		cin>>prn;
		cout<<"Enter the position : "<<endl;
		cin.ignore();
		cin.getline(position,50);
		if(list1 == NULL)
		{
			list1 = create(name,prn,position);
		}
		else

		{
			node *p = new(struct node);
			p = create(name,prn,position);
			temp = list1;
			while(temp->nxt != NULL)
			{
				temp = temp->nxt;
			}
			temp->nxt = p;
		}

	}
	cout<<"Enter the number of elements of list2 : "<<endl;
		cin >> n2;
		cin.ignore();
		for(int i = 0;i<n2;i++)
		{
			cout<<"Enter the name : "<<endl;
			cin.getline(name,100);
			cout<<"Enter the PRN : "<<endl;
			cin>>prn;
			cout<<"Enter the position : "<<endl;
			cin.ignore();
			cin.getline(position,50);

			if(list2 == NULL)
			{
				list2 = create(name,prn,position);
			}
			else

			{
				node *p = new(struct node);
				p = create(name,prn,position);
				temp = list2;
				while(temp->nxt != NULL)
				{
					temp = temp->nxt;
				}
				temp->nxt = p;
			}

		}

		cout<<"Concatenating two lists : "<<endl;
		temp = list1;
		while(temp->nxt != NULL)
		{
			temp = temp->nxt;
		}
		temp->nxt = list2;

		temp = list1;
		while(temp != NULL)
		{
			cout<<temp->name<<"\t"<<temp->prn<<"\t"<<temp->position<<endl;
			temp = temp->nxt;
		}
		free(list1);
		free(temp);
}





int main()
{
	Pinnacle_Club PC;
	int c;
	char name[100],prn[10],position[50];
	do
	{
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Press 1 to add members."<<endl;
		cout<<"Press 2 to delete members."<<endl;
		cout<<"Press 3 to display."<<endl;
		cout<<"Press 4 to concatenate."<<endl;
		cout<<"Press 0 to Exit."<<endl;
		cout<<"-------------------------------------------------------"<<endl;
		cin >> c;
		switch(c)
		{
		case 1:

			cout<<"Enter the name : "<<endl;
			cin.ignore();
			cin.getline(name,100);
			cout<<"Enter the PRN Number : "<<endl;
			cin >> prn;
			cout<<"Enter the position : "<<endl;
			cin.ignore();
			cin.getline(position,50);
			int l = strlen(position);
			for(int i = 0;i<l;i++)
				position[i] = toupper(position[i]);

			PC.add(name,prn,position);

			break;
		case 2:
			cout<<"Enter the PRN number : "<<endl;
			cin >> prn;
			PC.del(prn);
			break;
		case 3:
			PC.display();
			break;
		case 4:
			PC.concat();
			break;
		case 0:
			cout<<"Exited"<<endl;
			break;
		default:
			cout<<"Invalid choice!!!"<<endl;
		}
	}while(c != 0);

	return 0;
}
