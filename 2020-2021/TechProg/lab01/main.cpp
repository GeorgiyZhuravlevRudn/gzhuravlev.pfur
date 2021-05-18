#include <iostream>
using namespace std;
#include "class.cpp"
int main() {
    DoublyLinkedList s;
    int option;
    string pname,psurname,newName,newSurname;
    int pid,newId;
    Node *node1= new Node(1, "A","A");
    Node *node2 = new Node(2, "A","A");
    Node *node3 = new Node(3, "A","A");
    Node *node4 = new Node(4, "A","A");
    Node *node5 = new Node(5, "A","A");
    Node *node6= new Node(6, "A","A");
    Node *node7 = new Node(7, "A","A");
    Node *node8 = new Node(8, "A","A");
    Node *node9 = new Node(9, "A","A");
    Node *node10 = new Node(10, "A","A");
    s.appendNode(node1);
    s.appendNode(node2);
    s.appendNode(node3);
    s.appendNode(node4);
    s.appendNode(node5);
    s.appendNode(node6);
    s.appendNode(node7);
    s.appendNode(node8);
    s.appendNode(node9);
    s.appendNode(node10);
    do {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Append node operation" << endl;
        cout << "2. Prepend node operation" << endl;
        cout << "3. Insert After a node by_data" << endl;
        cout << "4. InsertAfter a node by_id" << endl;
        cout << "5. Delete head node" << endl;
        cout << "6. Delete tail node" << endl;
        cout << "7. Delete node by_id" << endl;
        cout << "8. Delete node by_Data" << endl;
        cout << "9. Move node after another" << endl;
        cout << "10. Swap nodes" << endl;
        cout << "11. Search node by_id" << endl;
        cout << "12. Search node by_Data" << endl;
        cout << "13. Count nodes" << endl;
        cout << "14. Print nodes" << endl;
        cout << "15. ReversePrint nodes" << endl;
        cout << "16. from to function" << endl;
        cout << "17. Clear Screen" << endl;
        cout << "0. exit" << endl;
        cin >> option;
        Node* n1 = new Node();

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \n" << endl;
            cout << "id: "; cin >> pid;
            cout << "name: "; cin >> pname;
            cout<<"surname: "; cin>>psurname;
            n1->id = pid;
            n1->name = pname;
            n1->surname=psurname;
            s.appendNode(n1);
            break;

        case 2:
            cout << "Prepend Node Operation \n" << endl;
            cout << "id: "; cin >> pid;
            cout << "name: "; cin >> pname;
            cout<<"surname: "; cin>>psurname;
            n1->id = pid;
            n1->name = pname;
            n1->surname=psurname;
            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After by Data Operation \n" << endl;
            cout<<"After which member do you want to insert \nname: ";
            cin>>newName;
            cout<<" surname: ";
            cin>>newSurname;
            cout << "Enter id & data of the New Node " << endl;
            cout << "id: "; cin >> pid;
            cout << "name: "; cin >> pname;
            cout<<"surname: "; cin>>psurname;
            n1->id = pid;
            n1->name = pname;
            n1->surname=psurname;
            s.InsertAfter_by_data(newName,newSurname, n1);
            break;

        case 4:
            cout << "Insert Node After by id Operation \n" << endl;
            cout<<"After which member do you want to insert \nid: ";
            cin>>newId;
            cout << "Enter id & data of the New Node " << endl;
            cout << "id: "; cin >> pid;
            cout << "name: "; cin >> pname;
            cout<<"surname: "; cin>>psurname;
            n1->id = pid;
            n1->name = pname;
            n1->surname=psurname;
            s.InsertAfter_by_id(newId, n1);
            break;

        case 5:
            cout << "delete head node operation \n" << endl;
            s.deleteHead();
            break;

        case 6:
            cout << "delete tail node operation \n" << endl;
            s.deleteTail();
            break;

        case 7:
            cout << "delete Element by id operation \n" << endl;
            cout << "id: "; cin >> pid;
            s.deleteElement_By_id(pid);
            break;

        case 8:
            cout << "delete Element by data operation \n" << endl;
            cout<<"Which member do you want to delete \nname: ";
            cin>>newName;
            cout<<"surname: ";
            cin>>newSurname;
            s.deleteElement_by_Data(newName,newSurname);
            break;

        case 9:
            cout << "move element after another operation \n" << endl;
            cout << "id of element which you want to move: "; cin >> pid;
            cout << "After which element id: "; cin >> newId;
            s.move_element(pid, newId);
            break;

        case 10:
            cout << "swap nodes operation \n" << endl;
            cout << "id of 1st element: "; cin >> pid;
            cout << "id of 2nd element: "; cin >> newId;
            s.swap_nodes(pid, newId);
            break;

        case 11:
            cout << "Search by id operation \n" << endl;
            cout << "id: "; cin >> pid;
            s.Search_Element_By_Id(pid);
            break;

        case 12:
            cout << "Search by data operation \n" << endl;
            cout << "Enter data of a node you want to find" << endl;
            cout << "name: "; cin >> pname;
            cout<<"surname: "; cin>>psurname;
            s.Search_Element_By_Data(pname,psurname);
            break;

        case 13:
            cout << "Count nodes operation \n" << endl;
            s.Nodes_Count();
            break;

        case 14:

            cout << "Print nodes operation \n" << endl;
            s.Print();
            break;

        case 15:

            cout << " Reverse print nodes operation \n" << endl;
            s.reversePrint();
            break;

        case 16:
            cout<< " from one to other function\n";
            s.Print_from_to();
            break;

        case 17:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
