#include <string>
#ifndef LIST_HEADER_H
#define LIST_HEADER_H
class Node;
class DoublyLinkedList{
Node* node_Existence_Check_key(int pid);
Node* node_Existence_Check_data(std::string pname, std::string psurname);
void appendNode(Node* newNode);
void prependNode(Node* newNode);
void InsertAfter_by_id(int pid, Node* newNode);
void InsertAfter_by_data(std::string pname,std::string psurname, Node* newNode);
void deleteHead();
void deleteTail();
void deleteElement_By_id(int pid);
void deleteElement_by_Data(std::string pname,std::string psurname);
void move_element(int k1, int k2);
void swap_nodes(int k1, int k2);
void Search_Element_By_Id(int k);
void Search_Element_By_Data(std::string pname,std::string psurname);
void Nodes_Count();
void Print();
void reversePrint();
};
#endif
