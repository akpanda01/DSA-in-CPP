#include<iostream>
using namespace std;

//Implementing Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

    public:
        List(){
            head = tail =NULL;
        }

//Push_front function implementation
        void push_front(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = tail = newNode;
                return;
            }else{
                newNode->next=head;
                head = newNode;
            }

        }

//Push_back function implementation
        void push_back(int val){
            Node* newNode = new Node(val);
            if(head== NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }

//Pop_front function implementation
        void pop_front(){
            if(head == NULL){
                cout<<"Empty";
                return;
            }
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

//Pop_back function implementation
        void pop_back() {
            if (head == NULL) { 
                cout << "Empty" << endl;
                return;
            }
        
            if (head == tail) { 
                delete head;
                head = tail = NULL;
                return;
            }
        
            Node* temp = head;  
            while (temp->next != tail) {
                temp = temp->next;
            }
        
            delete tail;    
            tail = temp;  
            tail->next = NULL; 
        }

//Insert_pos function implementation
        void insert_pos(int val, int pos) {
            if (pos <= 1 || head == NULL) {
                push_front(val);
                return;
            }
        
            Node* temp = head;
            int count = 1;
        
            while (temp != NULL && count < pos - 1) {
                temp = temp->next;
                count++;
            }
        
            if (temp == NULL) { 
                push_back(val);
                return;
            }
        
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        
            if (newNode->next == NULL) {
                tail = newNode;
            }
        }

//Search function implementation
        int search(int key){
            Node* temp = head;
            int idx = 0;

            while(temp!= NULL){
                if(temp->data ==key){
                    return idx;
                }
                temp = temp->next;
                idx++;
            }
            return -1;
        }
        
//Print linked list function implementation
        void printLL(){
            Node* temp = head;

            while(temp !=NULL){
                cout<< temp->data <<" -> ";
                temp = temp->next;
            }
            cout<< "NULL"<<endl;
        }

};

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_front(0);

    ll.push_front(0);
    ll.pop_back();
    ll.pop_front();
    ll.insert_pos(2,7);
    ll.printLL();

    cout<<ll.search(2);
    
    return 0;
}
