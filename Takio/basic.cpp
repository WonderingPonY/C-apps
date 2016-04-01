#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

//Node Declaration

struct node
{
  char info;
  int counter;
  struct node *next;
}*start;

//Class Declaration

class self_list
{
  public:
    node* create_node(char);
    void insert_last(char);
    void insert_begin(char);
    void delete_pos(int);
    void display();
    void sort();
    void move_to_front();
    int search(char);
    void transpose();
    void count();
    self_list()
    {
      start = NULL;
    }
};

//Main :contains menu

int main()
{
  int choice, position;
  char element;
  self_list sl;
  start = NULL;
  while (1)
  {
    cout<<endl<<"----------------------------------"<<endl;
    cout<<endl<<"Operations on Self Organising List"<<endl;
    cout<<endl<<"----------------------------------"<<endl;
    cout<<"1.Insert Node at first"<<endl;
    cout<<"2.Insert Node at last"<<endl;
    cout<<"3.Delete a Particular Node"<<endl;
    cout<<"4.Display List"<<endl;
    cout<<"5.Move to Front Organising List"<<endl;
    cout<<"6.Transpose Organising List"<<endl;
    cout<<"7.Count Organising List"<<endl;
    cout<<"8.Exit "<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
      case 1:
        cout<<"Inserting Element at first"<<endl;
        cout<<"Enter the character to be inserted: ";
        cin>>element;
        sl.insert_begin(element);
        cout<<endl;
        break;
      case 2:
        cout<<"inserting Element at last"<<endl;
        cout<<"Enter the character to be inserted: ";
        cin>>element;
        sl.insert_last(element);
        cout<<endl;
        break;
      case 3:
        cout<<"Deleteing element at a given position"<<endl;
        cout<<"Enter the position of the element to be deleted: ";
        cin>>position;
        sl.delete_pos(position);
        cout<<endl;
        break;
      case 4:
        cout<<"Display elements of link list"<<endl;
        sl.display();
        cout<<endl;
        break;
      case 5:
        cout<<"Move to Front Organising List"<<endl;
        sl.move_to_front();
        cout<<endl;
        break;
      case 6:
        cout<<"Transpose Organising List"<<endl;
        sl.transpose();
        cout<<endl;
        break;
      case 7:
        cout<<"Count Organising List"<<endl;
        sl.count();
        break;
      case 8:
        cout<<"Exiting..."<<endl;
        exit(1);
        break;
      default:
        cout<<"Wrong choice"<<endl;
    }
  }
  return 0;
}

//Create Node

node *self_list::create_node(char value)
{
  struct node *temp;
  temp = new(struct node);
  if (temp == NULL)
  {
    cout<<"Memory not allocated"<<endl;
    return 0;
  }
  else
  {
    temp->info = value;
    temp->next = NULL;
    temp->counter = 0;
    return temp;
  }
}

//Inserting Node at Last

void self_list::insert_last(char value)
{
  struct node *temp, *s;
  temp = create_node(value);
  if (start == NULL)
  {
    start = temp;
    return;
  }
  s = start;
  while (s->next != NULL)
  {
    s = s->next;
  }
  temp->next = NULL;
  s->next = temp;
  cout<<"Element Inserted"<<endl;
}

//Inserting Node at begining

void self_list::insert_begin(char value)
{
  struct node *temp, *p;
  temp = create_node(value);
  if (start == NULL)
  {
    start = temp;
    start->next = NULL;
  }
  else
  {
    p = start;
    start = temp;
    start->next = p;
  }
}

//Delete element at a given position

void self_list::delete_pos(int pos)
{
  int i, key = 0;;
  if (start == NULL)
  {
    return;
  }
  struct node *s, *ptr;
  s = start;
  if (pos == 1)
  {
    start = s->next;
  }
  else
  {
    while (s !=NULL)
    {
      s = s->next;
      key++;
    }
    if (pos > 0 && pos <= key)
    {
      s = start;
      for (i = 1;i < pos;i++)
      {
        ptr = s;
        s = s->next;
      }
      ptr->next = s->next;
    }
    free(s);
  }
}

//Searching an element

int self_list::search(char value)
{
  int pos = 0;
  bool flag = false;
  if (start == NULL)
  {
    return 0;
  }
  struct node *s;
  s = start;
  while (s != NULL)
  {
    pos++;
    if (s->info == value)
    {
      flag = true;
      return pos;
    }
    s = s->next;
  }
  if (!flag)
    return 0;
}

//Display Elements

void self_list::display()
{
  struct node *temp;
  if (start == NULL)
  {
    cout<<"The List is Empty, nothing to display"<<endl;
    return;
  }
  temp = start;
  while (temp != NULL)
  {
    cout<<temp->info<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

//Move to Front Self Orginising

void self_list::move_to_front()
{
  if (start == NULL)
  {
    cout<<"The List is Empty, first create the list"<<endl;
    return;
  }
  char stream[100001];
  cout<<"Enter the string of elements searched"<<endl;
  cin>>stream;
  int len, pos;
  len = strlen(stream);
  for (int i = 0;i < len;i++)
  {
    if (search(stream[i]) != 0)
    {
      if (search(stream[i]) != 1)
      {
        pos = search(stream[i]);
        delete_pos(pos);
        insert_begin(stream[i]);
      }
      cout<<stream[i]<<": ";
      display();
    }
  }
}

//Transpose Self Organized

void self_list::transpose()
{
  if (start == NULL)
  {
    cout<<"The List is Empty, first create the list"<<endl;
    return;
  }
  char stream[100001];
  cout<<"Enter the string of elements searched"<<endl;
  cin>>stream;
  int len, pos, temp;
  len = strlen(stream);
  struct node *s;
  for (int i = 0;i < len;i++)
  {
    s = start;
    if (search(stream[i]) != 0)
    {
      if(search(stream[i]) != 1)
      {
        pos = search(stream[i]);
        for (int j = 1;j < pos - 1;j++)
        {
          s = s->next;
        }
        temp = s->info;
        s->info = s->next->info;
        s->next->info = temp;
      }
      cout<<stream[i]<<": ";
      display();
    }
  }
}

// Count Self Organized List

void self_list::count()
{
  if (start == NULL)
  {
    cout<<"The List is Empty, first create the List"<<endl;
    return;
  }
  char stream[100001];
  cout<<"Enter the string of elements searched"<<endl;
  cin>>stream;
  int len,pos;
  len = strlen(stream);
  struct node *s;
  for (int i = 0;i < len;i++)
  {
    s = start;
    if (search(stream[i]) != 0)
    {
      pos = search(stream[i]);
      for (int j = 0;j < pos - 1;j++)
        {
          s = s->next;
        }
        (s->counter)++;
        sort();
        cout<<stream[i]<<": ";
        display();
    }
  }
}
