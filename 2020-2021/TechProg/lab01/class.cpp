#include<iostream>
using namespace std;
#include<string>
class DoublyLinkedList;
class Node {
public:
    int id;
    string name;
    string surname;
    Node* next;
    Node* previous;

    Node() {
        name = "";
        surname = "";
        next = NULL;
        previous = NULL;
    }
    Node(int pid, string pname,string psurname) {
        id = pid;
        name = pname;
        surname = psurname;
    }
    ~Node(){
        cout<<" Node with id "<<id<<" deleted\n";
    }

};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }
    DoublyLinkedList(Node* newNode) {
        head = newNode;
    }
    ~DoublyLinkedList(){
        Node *ptr=head;
        while(ptr!=nullptr){
            Node *del_Node=ptr;
            ptr=ptr->next;
            delete del_Node;
        }
    }

Node* node_Existence_Check_key(int pid) {
        Node* temp = nullptr;
        Node* ptr = head;
        while (ptr != nullptr) {
            if (ptr->id == pid) {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
Node* node_Existence_Check_data(string pname, string psurname) {
        Node* temp = nullptr;
        Node* ptr = head;
        while (ptr != nullptr) {
            if (ptr->name == pname && ptr->surname==psurname) {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
void appendNode(Node* newNode) {
        if (node_Existence_Check_key(newNode->id) != nullptr) {
            cout << "Node with id " << newNode->id<<" already exists" << endl;
            cout << "Enter another id, please"<<endl;
        }
        else {
            if (head == nullptr) {
                head = newNode;
                cout << "Node has been appended as a head node" << endl;
            }
            else {
                Node* ptr = head;
                while (ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
                newNode->previous = ptr;
                cout << "Node has been appended as a newNode" << endl;
            }
        }
    }
void prependNode(Node* newNode) {
        if (node_Existence_Check_key(newNode->id) != nullptr) {
            cout << "Node with id " << newNode->id<<" already exists" << endl;
            cout << "Enter another id, please"<<endl;
        }
        else {
            if (head == nullptr) {
                head = newNode;
                cout << "Node has been prepended as a head node" << endl;
            }
            else {
                head->previous = newNode;
                newNode->next = head;
                head = newNode;
                cout << "Node has been prepended" << endl;
            }
        }
    }
void InsertAfter_by_id(int pid, Node* newNode) {
        Node* ptr = node_Existence_Check_key(pid);
        if (ptr == nullptr) {
            cout << "There is no node with id - "<< pid << endl;
        }
        else if(newNode->id==ptr->id){
            cout<<"Node with id: "<< ptr->id<<" already exists"<<endl;
            cout << "Enter another id, please"<<endl;
        }
        else {
            cout << "inserting" << endl;
            Node* nextNode = ptr->next;
            if (nextNode == nullptr) {
                ptr->next = newNode;
                newNode->previous = ptr;
                cout << "node inserted at the end of the strucure" << endl;
            }
            else {
                newNode->next = nextNode;//newNode->next=ptr->next
                nextNode->previous = newNode;//ptr = newNode
                newNode->previous = ptr;//ptr->previous=ptr
                ptr->next = newNode;//ptr->next=ptr
                cout << "node has been inserted" << endl;
            }
        }
    }
void InsertAfter_by_data(string pname,string psurname, Node* newNode) {
        Node* ptr = node_Existence_Check_data(pname,psurname);
        int id1;
        Node *testnode=head;
        bool similardata;
        while(testnode->next!=nullptr){
            if(testnode->name==testnode->next->name && testnode->surname==testnode->next->surname){
                similardata=true;
                break;
            }
            else{
                similardata=false;
            }
            testnode=testnode->next;
        }
        if (ptr == nullptr) {
            cout << "There is no node with name: "<<pname<<"surname: "<<psurname << endl;
        }
        else if(newNode->id==ptr->id){
            cout<<"Node with id: "<< ptr->id<<" already exists"<<endl;
            cout << "Enter another id, please"<<endl;
        }
        else if(similardata==true){
                Print();
                cout<<"there're two or more similar members, please input id: ";
                cin>>id1;
                cout << "inserting" << endl;
                ptr=head;
                while(ptr->id!=id1){
                    ptr=ptr->next;
                }
                Node* nextNode = ptr->next;
                if (nextNode == nullptr) {
                    ptr->next = newNode;
                    newNode->previous = ptr;
                    cout << "node inserted at the end" << endl;
                }

                else {
                    newNode->next = nextNode;//newNode->next=ptr->next
                    nextNode->previous = newNode;//ptr = newNode
                    newNode->previous = ptr;//ptr->previous=ptr
                    ptr->next = newNode;//ptr->next=ptr
                    cout << "node has been inserted" << endl;
                }
            }
        else {
            cout << "inserting" << endl;
            Node* nextNode = ptr->next;
            if (nextNode == nullptr) {
                ptr->next = newNode;
                newNode->previous = ptr;
                cout << "node inserted at the end" << endl;
            }
            else {
                newNode->next = nextNode;//newNode->next=ptr->next
                nextNode->previous = newNode;//ptr = newNode
                newNode->previous = ptr;//ptr->previous=ptr
                ptr->next = newNode;//ptr->next=ptr
                cout << "node has been inserted" << endl;
            }
        }
    }
void deleteHead() {
        if (head == nullptr) {
            cout << "List is empty, can't delete" << endl;
        }
        else if (head->next == nullptr) {
            Node* temp = head;// head
            head = nullptr;
            delete temp;
            cout<<"Head Node has been deleted, list is empty now"<<endl;
        }
        else {
            Node* temp = head;
            head = head->next;
            head->previous = nullptr;
            delete temp;
            cout<<"Head Node has been deleted"<<endl;
        }
    }
void deleteTail() {
        if (head == nullptr) {
            cout << "List is empty, can't delete" << endl;
        }
        else if (head->next == nullptr) {
            Node* temp = head;// head
            head = nullptr;
            delete temp;
            cout<<"Tail Node has been deleted, structure is empty now"<<endl;
        }
        else {
            Node* ptr = head;
            Node* temp = nullptr;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            temp = ptr;
            ptr = ptr->previous;
            ptr->next = nullptr;
            delete temp;
            cout<<"Tail Node has been deleted"<<endl;
        }
    }
void deleteElement_By_id(int pid) {
        Node* ptr = node_Existence_Check_key(pid);
        if (ptr == nullptr) {
            cout << "There is no node with id - "<< pid << endl;
        }
        else {
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            if (head->id == pid) {
                deleteHead();
            }
            else if (tail->id == pid) {
                deleteTail();
            }
            else {
                ptr = head;
                while (ptr->id != pid) {
                    ptr = ptr->next;
                }
                Node* prev = ptr->previous;
                Node* nxt = ptr->next;
                prev->next = nxt;
                nxt->previous = prev;
                delete ptr;
                cout<<"Node with id: "<<pid<<" deleted"<<endl;
            }
        }
    }
void deleteElement_by_Data(string pname, string psurname) {
        Node* ptr = node_Existence_Check_data(pname, psurname);
        int id1;
        Node *testnode=head;
        bool similardata;
        while(testnode->next!=nullptr){
            if(testnode->name==testnode->next->name && testnode->surname==testnode->next->surname){
                similardata=true;
                break;
            }
            else{
                similardata=false;
            }
            testnode=testnode->next;
        }
        if (ptr == nullptr) {
            cout << "There is no node with name: "<<pname<<" surname: "<<psurname << endl;
        }
        else if(similardata==true){
                Print();
                cout<<"there're two or more similar members, please input id: ";
                cin>>id1;
                cout << "deleting" << endl;
                Node* tail = head;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
                if (head->id==id1) {
                    deleteHead();
                }
                else if (tail->id==id1) {
                    deleteTail();
                }
                else {
                    ptr = head;
                    while (ptr->id!=id1) {
                        ptr = ptr->next;
                    }
                    Node* prev = ptr->previous;
                    Node* nxt = ptr->next;
                    prev->next = nxt;
                    nxt->previous = prev;
                    delete ptr;
                    cout << " node with name: "<<pname<<" surname: "<<psurname <<" deleted"<< endl;
                }
            }

        else {
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            if (head->name == pname && head->surname==psurname) {
                deleteHead();
            }
            else if (tail->name == pname && tail->surname==psurname) {
                deleteTail();
            }
            else {
                ptr = head;
                while (ptr->name != pname && ptr->surname!=psurname) {
                    ptr = ptr->next;
                }
                Node* prev = ptr->previous;
                Node* nxt = ptr->next;
                prev->next = nxt;
                nxt->previous = prev;
                delete ptr;
                cout << " node with name: "<<pname<<" surname: "<<psurname <<" deleted"<< endl;
            }
        }
    }
void move_element(int k1, int k2) {
        Node* node1 = node_Existence_Check_key(k1);// el that we want to move
        Node* node2 = node_Existence_Check_key(k2);// after what el
        if (node1 == nullptr || node2 == nullptr) {
            if (node1 == nullptr) {
                cout << "There is no Node with id " << k1 << endl;
                cout << "Enter another id, please"<<endl;
            }
            else {
                cout << "There is no Node with id " << k2 << endl;
                cout << "Enter another id, please"<<endl;
            }
        }
        else {
            Node* tail = head;
            Node* node1_next = node1->next;
            Node* node2_next = node2->next;
            Node* node2_previous = node2->previous;
            Node* node1_previous = node1->previous;
            int i = 1;
            while (tail->next != nullptr) {
                tail = tail->next;
                i++;
            }
            if (i == 2) {
                if (head->id == k1) {
                    node1->next = nullptr;
                    node2->previous = nullptr;
                    head = node2;
                    node2->next = node1;
                    node1->previous = node2;
                }
                else {//switch
                    cout << "can't move element, try 'switch' option" << endl;
                }
            }
            else if (head->id == k1) {//node1=head ++
                if (tail->id == k2) {//head->tail
                    node1_next->previous = nullptr;
                    head = node1_next;
                    node1->next = nullptr;
                    node1->previous = node2;
                    node2->next = node1;
                    node1 = tail;
                }
                else {
                    node1_next->previous = nullptr;
                    head = node1_next;
                    node2->next = node1;
                    node1->previous = node2;
                    node1->next = node2_next;
                    node2_next->previous = node1;
                }
            cout << "The element with id: "<< k1<<", now, stays after the element with id: "<<k2 << endl;
            }
            else if (tail->id == k1) {//node1=tail
                node1_previous->next = nullptr;
                node1->next = node2_next;
                node2_next->previous = node1;
                node1->previous = node2;
                node2->next = node1;
                cout << "The element with id: "<< k1<<", now, stays after the element with id: "<<k2 << endl;
            }
            else if (tail->id == k2) {//node2=tail++
                node1_previous->next = node1_next;
                node1_next->previous = node1_previous;
                node2->next = node1;
                node1->previous = node2;
                node1->next = nullptr;
                cout << "The element with id: "<< k1<<", now, stays after the element with id: "<<k2 << endl;
            }
            else {
                node1_previous->next = node1_next;
                node1_next->previous = node1_previous;
                node2_next->previous = node1;
                node1->next = node2_next;
                node2->next = node1;
                node1->previous = node2;
                cout << "The element with id: "<< k1<<", now, stays after the element with id: "<<k2 << endl;
            }
        }
    }
void swap_nodes(int k1, int k2) {
        Node* node1 = node_Existence_Check_key(k1);
        Node* node2 = node_Existence_Check_key(k2);
        if (node1 == nullptr || node2 == nullptr) {
            if (node1 == nullptr) {
                cout << "There is no Node with id " << k1 << endl;
                cout << "Enter another id, please"<<endl;
            }
            else {
                cout << "There is no Node with id " << k2 << endl;
                cout << "Enter another id, please"<<endl;
            }
        }
        else {
            Node* node1_next = node1->next;
            Node* node1_previous = node1->previous;
            Node* node2_next = node2->next;
            Node* node2_previous = node2->previous;
            Node* tail = head;
            int i = 1;
            while (tail->next != nullptr) {
                tail = tail->next;
                i++;
            }
            if (i == 2) {//++
                if (head->id == k1) {
                    node1->next = nullptr;
                    node2->previous = nullptr;
                    head = node2;
                    node2->next = node1;
                    node1->previous = node2;
                }
                else {
                    node1->previous = nullptr;
                    node2->next = nullptr;
                    head = node1;
                    node2->previous = node1;
                    node1->next = node2;
                }

            }
            else if (head->id == k1) {
                if (tail->id == k2) {//node1=head node2=tail
                    node2_previous->next = node1;
                    node1->previous = node2_previous;
                    node1->next = nullptr;
                    node2->previous = nullptr;
                    node1_next->previous = node2;
                    node2->next = node1_next;
                    head = node2;
                }
                else {//node1=head node2=everything except tail
                    if (node1->next == node2) {//node2 is after node1
                        node1->next = node2_next;
                        node2_next->previous = node1;
                        //node1_previous->next - node2;
                        node2->previous = nullptr;
                        node2->next = node1;
                        node1->previous = node2;
                        head = node2;
                    }
                    else{//node2 isn't after node1
                        node2_previous->next = node1;
                        node1->previous = node2_previous;
                        node2_next->previous = node1;
                        node1->next = node2_next;
                        node1_next->previous = node2;
                        node2->previous = nullptr;
                        head = node2;
                        node2->next = node1_next;
                    }
                }
            }
            else if (head->id == k2) {
                if (tail->id == k1) {//node2=head node1=tail
                    node1_previous->next = node2;
                    node2->previous = node1_previous;
                    node2->next = nullptr;
                    node1->previous = nullptr;
                    node2_next->previous = node1;
                    node1->next = node2_next;
                    head = node1;
                }
                else {//node2=head node1=everything except tail
                    if (node2->next == node1) {//node1 is after node2
                        node2->next = node1_next;
                        node1_next->previous = node2;
                        //node1_previous->next - node2;
                        node1->previous = nullptr;
                        node1->next = node2;
                        node2->previous = node1;
                        head = node1;
                    }
                    else {//node1 isn't after node2
                        node1_previous->next = node2;
                        node2->previous = node1_previous;
                        node1_next->previous = node2;
                        node2->next = node1_next;
                        node2_next->previous = node1;
                        node1->previous = nullptr;
                        head = node1;
                        node1->next = node2_next;
                    }
                }
            }
            else if (tail->id == k1) {
                if (head->id == k2) {//node2=head node1=tail
                    node1_previous->next = node2;
                    node2->previous = node1_previous;
                    node2->next = nullptr;
                    node1->previous = nullptr;
                    node2_next->previous = node1;
                    node1->next = node2_next;
                    head = node1;
                }
                else {//node1=tail node1=everything except head
                    if (node2->next == node1) {//node1 is after node2
                        node2->next = nullptr;
                        node2->previous = node1;
                        node2_previous->next = node1;
                        node1->previous = node2_previous;
                        node1->next = node2;
                    }
                    else {//node1 isn't after node2
                        node2_previous->next = node1;
                        node2_next->previous = node1;
                        node1->next = node2_next;
                        node1->previous = node2_previous;
                        node1_previous->next = node2;
                        node2->previous = node1_previous;
                        node2->next = nullptr;
                    }
                }
            }
            else if (tail->id == k2) {
                if (head->id == k1) {//node2=tail node1=head
                    node2_previous->next = node1;
                    node1->previous = node2_previous;
                    node1->next = nullptr;
                    node2->previous = nullptr;
                    node1_next->previous = node2;
                    node2->next = node1_next;
                    head = node2;
                }
                else {//node2=tail node1=everything except head
                    if (node1->next == node2) {//node2 is after node1
                        node1->next = nullptr;
                        node1->previous = node2;
                        node1_previous->next = node2;
                        node2->previous = node1_previous;
                        node2->next = node1;
                    }
                    else {//node2 isn't after node1
                        node1_previous->next = node2;
                        node1_next->previous = node2;
                        node2->next = node1_next;
                        node2->previous = node1_previous;
                        node2_previous->next = node1;
                        node1->previous = node2_previous;
                        node1->next = nullptr;
                    }
                }
            }
            else {//if 2 random elements in a structure
                if (node1->next == node2) {//elements are nearby
                    node1->next = node2_next;
                    node2_next->previous = node1;
                    node1->previous = node2;
                    node2->next = node1;
                    node2->previous = node1_previous;
                    node1_previous->next = node2;
                }
                else if (node2->next == node1) {//elements are nearby
                    node2->next = node1_next;
                    node1_next->previous = node2;
                    node2->previous = node1;
                    node1->next = node2;
                    node1->previous = node2_previous;
                    node2_previous->next = node1;
                }
                else {
                    node1->next = node2_next;
                    node2_next->previous = node1;
                    node1->previous = node2_previous;
                    node2_previous->next = node1;

                    node2->next = node1_next;
                    node1_next->previous = node2;
                    node2->previous = node1_previous;
                    node1_previous->next = node2;
                }
            }
            cout << "Elements with id's: "<< k1<<" and "<<k2<<" swapped successfully"<< endl;
    }

}
void Search_Element_By_Id(int k) {
    Node* ptr = node_Existence_Check_key(k);
    if (ptr == nullptr) {
        cout << "There is no Node with id " << k << endl;
        cout << "Enter another id, please"<<endl;
    }
    else {
        cout << "your element id is " << ptr->id << " name: " << ptr->name<<" surname: "<<ptr->surname << endl;
    }
}
void Search_Element_By_Data(string pname, string psurname) {
    Node* ptr = node_Existence_Check_data(pname, psurname);
    int id1;
    Node *testnode=head;
    bool similardata;
    while(testnode->next!=nullptr){
        if(testnode->name==testnode->next->name && testnode->surname==testnode->next->surname){
            similardata=true;
            break;
        }
        else{
            similardata=false;
        }
        testnode=testnode->next;
    }
    if (ptr == nullptr) {
        cout << "There is no node with name: "<<pname<<" surname: "<<psurname << endl;
    }
    else if(similardata==true){
            Print();
            cout<<"there're two or more similar members, please input id: ";
            cin>>id1;
            ptr=head;
            while(ptr->id!=id1){
                ptr=ptr->next;
            }
            cout << "your element id is " << ptr->id << " name: " << ptr->name<<" surname: "<<ptr->surname << endl;
        }
    else {
        cout << "your element id is " << ptr->id << " name: " << ptr->name<<" surname: "<<ptr->surname << endl;
    }
}
void Nodes_Count() {
    Node* ptr = head;
    int i = 0;
    while (ptr != nullptr) {
        ptr = ptr->next;
        i++;
    }
    cout << "there are " << i << " Nodes in that structure" << endl;

}
void Print() {
    Node* ptr = head;
    if (head == nullptr) {
        cout << "there is no nodes, can't print" << endl;
    }
    else {
        int i = 0;
        while (ptr != nullptr) {
            cout << "number in linked structure: " << i << " , personal id: " << ptr->id << ", name: " << ptr->name<<", surname: "<< ptr->surname << endl;
            ptr = ptr->next;
            i++;
        }
    }
}
void reversePrint() {
    Node* tail = head;
    int i = 0;
    while (tail->next != nullptr) {
        tail = tail->next;
        i++;
    }
    Node* ptr = tail;
    if (head == nullptr) {
        cout << "there is no nodes, can't print" << endl;
    }
    else {
        while (ptr != head->previous) {
            cout << "number in linked structure: " << i << " , personal id: " << ptr->id << ", name: " << ptr->name<<", surname: "<< ptr->surname << endl;
            ptr = ptr->previous;
            i--;
        }
    }
}
void Print_from_to(){
    int from;
    int to;
    Nodes_Count();
    cout<<"you want to start with(enter from what number we go): "; cin>>from;
    cout<<"you want to end with(enter to what number we go): "; cin>>to;
    int list_number=0;
    Node *ptr=head;
    while(ptr!=nullptr){
        list_number++;
        ptr=ptr->next;
    }
    int list_id[list_number];
    ptr=head;
    list_number=0;
    while(ptr!=nullptr){
        list_id[list_number]=ptr->id;
        ptr=ptr->next;
        list_number++;
    }
    list_number=from-1;
    to=to-1;
    ptr=head;
    while(list_number<=to){
        if(ptr->id==list_id[list_number]){
            cout << "number in linked structure: " << list_number+1 << " , personal id: " << ptr->id << ", name: " << ptr->name<<", surname: "<< ptr->surname << endl;
            list_number ++;
        }
        ptr=ptr->next;
    }
}

};
