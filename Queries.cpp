#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node(int val){
            this->val=val;
            this->next=NULL;
        }
};
void insert_head(Node* &head,int val){

        Node *newNode = new Node(val);
       if (head == NULL)
        {
        head = newNode;
        return;
        }
            newNode->next=head;
            head =newNode;

}
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}
void delete_position(Node *head, int pos)
{
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}
void delete_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}
void print_link_list(Node *head){
    Node *tmp=head;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
int link_list_size(Node *head){
    Node * temp=head;
    int size = 0;
    while(temp != NULL){
        size++;
        temp=temp->next;
    }
    return size;
}
int main()
{
    
    int q;
    cin>>q;
    Node *head =NULL;
    while(q--){
        
        int x;
        int v;
       cin>>x>>v;
       if(x==0){
        int size=link_list_size(head);
            insert_head(head,v);
       }
       else if(x==1){
        
        insert_at_tail(head,v);
       }
       else if(x==2){
        int size=link_list_size(head);
        
       if(v== 0 && head != NULL){
            delete_head(head);
        }
        else if(v<size){
            delete_position(head,v);
        }
        
       }
    print_link_list(head);
    }
    return 0;
}