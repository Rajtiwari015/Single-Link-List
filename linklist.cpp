#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node * next;

    node(int data)
    {
        this->data=data;
        next= NULL;
    }
};

node *create()
{
    node * head=NULL;
    node * temp=NULL;
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    while (data!=-1)

    {
        node *newNode=new node(data);
        if(head==NULL)
        {
            head=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=temp->next ;
        }
        cin>>data;
       
    }
    return head;
    

}

node * insert (node * head,int data,int pos)
{
    
    
    node * temp=head;
    node * newnode =new node(data);
    int count=0;
    if (pos==0)
    {
        newnode->next=head;
        head=newnode;
        return head;

    }
    while(temp!=NULL && count<pos-1 )
    {
        temp=temp->next;
        count++;

    }
    if(temp!=NULL){
        node *ptr = temp->next;
   temp->next =newnode;
   newnode->next=ptr;
    temp=temp->next;
    }
    return head;
    
}
    node * delete_y (node *head,int pos)
{
    node *currentNode = head;
    node * temp=NULL;
    int count =0;
    if(pos==0)
    {
        head=head->next;
        delete currentNode;
 
        return head;
    }
    while(currentNode !=NULL && count<pos)
    {
        temp=currentNode;
        currentNode=currentNode->next;
        count++;


    }
    if(currentNode!=NULL )
    {
        temp->next=currentNode->next;
        delete currentNode;
    
    }
    return head;


    
}
void print(node * head)
{
    node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;


    }
    cout<<endl;
}
void ithNode( node *head,int position)
{
    node * temp=head;
  
   for(int i=1;i<position;i++)
   {
       temp=temp->next;
   }  
    cout<<temp->data<<endl;

  
}





int main()
{
   node * head=create();

    print(head);
        
    head=insert(head,16,5);
     print(head);
    
    head=delete_y(head,5);
     print(head);

    ithNode(head,3);
    
   

  

    return 0;
}