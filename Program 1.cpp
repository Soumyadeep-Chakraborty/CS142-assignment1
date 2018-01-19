//creating a linked list performing some basic operations on the linked list

#include <iostream>

using namespace std;
//declaring a class called node
class node
{
	public:
	int data;            //node contains a data
	node *next;			 //node also contains a pointer pointing to the next node 
};

class linkedlist{
	private:
		node *head, *tail;       //declaring the first and last element of a linked list
		public:
			linkedlist() {				//initializing head and tail using a constructor
				head = NULL;
				tail = NULL;
			}
			void addnode(int value){      		//function to addnode to the linked list
				node *temp=new node;            //delaring temp as pointer to a node
				temp->data=value;
				temp->next=NULL;
				if (head==NULL){
					head=temp;
					tail=temp;
				}
				else {
				
					tail->next=temp;
					tail=temp;
				}
				
				
				}
				void insertmid(int position, int value){				//function to insert a node in the middle of a linked list
					node *temp=new node;
					node *pre=new node;
					node *cur=new node;
					cur=head;
					for(int i=0;i<position-1;i++){						//loop allows us to reach the position where a new node is to be added
						pre=cur;
						cur=cur->next;
					}
					temp->data=value;
					pre->next=temp;
					temp->next=cur;
				}
				void display(){												//function to display the elements of a linked list
					node *temp=new node;
					temp=head;
					while(temp!=NULL){
						cout<<"\t------------"<<temp->data<<"----------\t";
						temp = temp->next;
					}
				}
				void deletefirst(){												//function to delete the first element of a linked list
					node *temp=new node;
					temp=head;
					head=head->next;
					delete temp;
				}
				void deletemid(int position){									//function to delete an element in the middle of a linked list
					node *pre =new node;
					node *cur=new node;
					cur=head;
					for (int i=0;i<position-1;i++){
						pre=cur;
						cur=cur->next;
					}
					pre->next=cur->next;
					delete cur;
				}
				void deleteend(){ 												//function to delete an element in the end of a linked list
					node *temp = head;
					while(temp->next->next != NULL){
						temp=temp->next;
					}
					temp->next=NULL; //here temp points to the second-last element, so the following algorithm makes the second last element of the loop point to NULL
				}
				void countnode(){												//function the count the number of elements of alinked list
					node *temp=new node;
					int count=0;
					temp=head;
					while(temp!=NULL){
						temp=temp->next;
						count++;
					}
					cout<<"The total number of elements in the node is : "<<count;
				}


};

//main function, declaring M as a class object of class linkedlist
int main()

{

  linkedlist M;
  cout<<"\nAdding the first node with value 30 : \n";
  M.addnode(30);
  M.display();
  cout<<"\nAdding a node to the end with value 11 : \n";
  M.addnode(11);
  M.display();
  cout<<"\nAdding another node to the end with value 23 : \n";
  M.addnode(23);
  M.display();
  cout<<"\nAdding a node in the second position with value 67 : \n";
  M.insertmid(2,67);
  M.display();
  cout<<"\ncounting the number of nodes : \n";
  M.countnode();
  cout<<"\ndeleting a node in the second position : \n";
  M.deletemid(2);
  M.display();
  cout<<"\ndeleting a node in the end : \n";
  M.deleteend();
  M.display();
  cout<<"\ndeleting the first node : \n" ;
  M.deletefirst();
  M.display();

  return 0;

}
