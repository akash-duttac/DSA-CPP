#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
} *head = nullptr;
class LinkedList{
public:
    node *create();
    node *display();
    node *insertAtBeginning();
    node *deleteAtBeginning();
    node *insertAtEnd();
    node *deleteAtEnd();
    node *insertAfterNode();
    node *deleteNode();
    node *sortList();
};
int main(){
    LinkedList list;
    int val, choice;
    while (true){
        cout<<"\n\t\t***** MAIN MENU *****"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"1. Create list\t\t\t2. Display List"<<endl;
        cout<<"3. Insert at beginning\t\t4. Delete first node"<<endl;
        cout<<"5. Insert at end\t\t6. Delete last node"<<endl;
        cout<<"7. Insert after given node\t8. Delete a given node"<<endl;
        cout<<"9. Sort the list\t\t0. EXIT"<<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 0: exit(0);
            case 1: head = list.create(); break;
            case 2: head = list.display(); break;
            case 3: head = list.insertAtBeginning(); break;
            case 4: head = list.deleteAtBeginning(); break;
            case 5: head = list.insertAtEnd(); break;
            case 6: head = list.deleteAtEnd(); break;
            case 7: head = list.insertAfterNode(); break;
            case 8: head = list.deleteNode(); break;
            case 9: head = list.sortList();
                    cout<<endl<<"Sorted List: ";
                    head = list.display(); break;
            default: cout<<"Enter valid choice!"<<endl; break;
        }
    }
}
node *LinkedList::create() {
    char ans;
    node *newNode, *ptr;
    do{
        newNode = new node;
        cout<<"Enter data: ";
        fflush(stdin);
        cin>>newNode->data;
        if (head==nullptr){
            newNode->next = nullptr;
            head = newNode;
        }
        else{
            for (ptr=head; ptr->next!=nullptr; ptr=ptr->next)
            {}
            ptr->next = newNode;
            newNode->next = nullptr;
        }
        cout<<"Add more data? (Y/N): ";
        fflush(stdin);
        cin>>ans;
    } while (ans=='y'||ans=='Y');
    return head;
}
node *LinkedList::display() {
    node *ptr;
    cout<<"LINKED LIST:\t";
    for (ptr=head;ptr!= nullptr;ptr=ptr->next)
        cout<<ptr->data<<"\t";
    return head;
}
node *LinkedList::insertAtBeginning() {
    node *newNode = new node;
    cout<<"Enter data: ";
    cin>>newNode->data;
    newNode->next = head;
    head = newNode;
    return head;
}
node *LinkedList::deleteAtBeginning() {
    node *temp;
    temp = head;
    head = head->next;
    cout<<temp->data<<" deleted"<<endl;
    delete temp;
    return head;
}
node *LinkedList::insertAtEnd() {
    node *ptr = head;
    node *newNode = new node;
    cout<<"Enter data: ";
    cin>>newNode->data;
    for (; ptr->next!= nullptr; ptr=ptr->next)
    {}
    ptr->next = newNode;
    newNode->next = nullptr;
    return head;
}
node *LinkedList::deleteAtEnd() {
    node *ptr = head;
    for (; ptr->next!=nullptr; ptr=ptr->next)
    {}
    delete ptr;
    return head;
}
node *LinkedList::insertAfterNode() {
    node *newNode = new node;
    cout<<"Enter data: ";
    cin>>newNode->data;
    int key;
    cout<<"Enter the node(data) after which insertion to be made: ";
    cin>>key;
    node *ptr, *preptr;
    for(ptr=head,preptr=ptr;preptr->data!=key;ptr=ptr->next)
        preptr = ptr;
    preptr->next = newNode;
    newNode->next = ptr;
    return head;
}
node *LinkedList::deleteNode() {
    int key;
    cout<<"Enter the data(node) to be deleted: ";
    cin>>key;
    node *ptr = head;
    if (ptr->data == key)
        head = deleteAtBeginning();
    else{
        node *temp = ptr;
        for (; ptr->data != key; ptr=ptr->next)
            temp = ptr;
        temp->next = ptr->next;
        cout<<ptr->data<<" deleted"<<endl;
        delete ptr;
    }
    return head;
}
node *LinkedList::sortList(){
    node *ptr1, *ptr2;
    int temp;
    for (ptr1=head; ptr1->next!=nullptr; ptr1=ptr1->next)
        for (ptr2=head; ptr2 != nullptr; ptr2=ptr2->next)
            if (ptr1->data > ptr2->data){
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
    return head;
}