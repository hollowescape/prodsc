// CPP program for array implementation of queue 
#include <string>
#include <iostream>
#include <cstdio> 
#include <unistd.h>
#include <math.h>
#define MAX 10

using namespace std; 



class Queue
{
      int front,rear;
      string queue[MAX];
 
      public:
  
      Queue()
      {
              front=rear=-1;
      }
 
       void qinsert(string item)
       {
              if(rear==MAX-1)
             {
                      cout<<"\nQUEUE OVERFLOW";
             }
             else if(front==-1 && rear==-1)
             {
                      front=rear=0;
                      queue[rear]=item;
                      cout<<"\nITEM INSERTED: ";
                      cout<<item;
             }
             else
             {
                      rear++;
                      queue[rear]=item;
                      cout<<"\nITEM INSERTED: ";
                      cout<<item;
             }
       }
  
       string qdelete()
       {
              string item;
  
              if(rear==-1)
             {
                       return "exit";
             }
             else if(front==0 && rear==0)
             {
                       item=queue[front];
                       front=rear=-1;
                       return item;
             }
             else
             {
                      item=queue[front];
                      front++;
                      return item;
             }
       }
 
       void qtraverse()
       {
              if(front==-1)
              {
                      cout<<"\n\nQUEUE IS EMPTY\n";
              }
              else
              {
                      cout<<"\n\nQUEUE ITEMS\n";
                      for(int i=front;i<=rear;i++)
                      {
                               cout<<queue[i];
                               cout<<" ";
                      }
                      cout<<endl;
              }
        }
};
class disk1{
	public:
	Queue disk1_queue;
	void pop()
	{
		string n;
		n=disk1_queue.qdelete();
		cout<<n;
		cout<<" the operation is over\n";
		sleep(1000);
	}
	void push(string n)
	{
		disk1_queue.qinsert(n);
		sleep(10000);
		pop();
	}
	
};
class disk2{
	public:
	Queue disk2_queue;
	void pop()
	{
		string n;
		n=disk2_queue.qdelete();
		cout<<n;
		cout<<" the operation is over\n";
		sleep(1000);
	}
	void push(string n)
	{
		disk2_queue.qinsert(n);
		sleep(10000);
		pop();
	}
	
};

class process{
	int process_id=0;
	string process_name[10];
public:
	Queue memqueue;

	void enqueue(string n)
	{	
		memqueue.qinsert(n);

	}
	void dequeue()
	{		string r;
			disk1 d;
			disk2 d2;
		  r=memqueue.qdelete();
		  if(r!="exit")
		  {
		  	cout<<r;
		  cout<<" process is going on";
		  if(strcmp(r,"disk1")==0)
		  {
               d.push(r);
		  }
		  else if(strcmp(r,"disk2")==0)
		  	{
		  		d2.push(r);
		  	}
		  else
		  {
		  	cout<<" no such disk exists";
		  }
		}
		else
		{
			cout<<" all the operation are over\n";
		}
	}
	void setter(int n)
	{	
		for(int i=0;i<n;i++)
		{
		process_id++;
		cout<<" enter the disk_name\n";
		cout<<" disk1 or disk2";
		cin>>(process_name[i]);
		enqueue(process_name[i]);
		}
	}
	void getter(int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<"process_id is"<<i+1<<"disk_name is";
			cout<<(process_name[i]);
			cout<<"\n";
		}
	}
};

int main()
{	process p;	
      int n;
      cout<<" enter the number of processes\n";
      cin>>n;
      p.setter(n);
      p.dequeue();
      cout<<" the details of processes are \n";
      p.getter(n);

      return 0;
}
