#include "matrix_header.h"
using namespace std;
//#define Lock
int main(){
        cout<<"first matrix"<<endl;
        Matrix A(3,3);
        A.SetParam();
        cout<<"first matrix"<<endl;
        A.setSize(4,4);
        A.print();
        cout<<"first matrix"<<endl;
        A.setSize(3,4);
        A.print();
        cout<<"second matrix\n";
        Matrix B(3,4);
        B.SetParam();
        cout<<"second matrix\n";
        B.print();
        Matrix D(B);
        D = A*B;
        D.print();
        cout<<"second matrix\n";
        B-=A;
        B.print();
        Matrix C(A);
        cout<<"third matrix\n";
        C = A+B;
        C.print();
        cout<<"third matrix\n";
        C = A-B;
        C.print();
        cout<<"third matrix\n";
        C = A*B;
        C.print();
        cout<<"third matrix\n";
        C +=B;
        C.print();
        cout<<"third matrix\n";
        C -=B;
        C.print();
        cout<<"third matrix\n";
        C *=B;
        C.print();
        cout<<"scalar\n";
        C+=2;
        C.print();
        cout<<"scalar\n";
        C -=2;
        C.print();
        cout<<"scalar\n";
        C *=2;
        C.print();
        cout<<"scalar\n";
        C /=2;
        C.print();
        cout<<"scalar\n";
        C +=2;
        C.print();
        cout<<"scalar\n";
        C -=2;
        C.print();
        cout<<"scalar\n";
        C *=2;
        C.print();
        cout<<"scalar\n";
        C /=2;
        C.print();
        cout<<"size\n";
        C.setSize(3,4);
        C.print();
        cout<<"size\n";
        C.setSize(2,4);
        C.print();
        cout<<"size\n";
        C.setSize(3,10);
        C.print();
        cout<<"size\n";
        C.setSize(3,3);
        C.print();
        cout<<"transpose\n";
        C.transpose();
        C.print();
        cout<<"transpose\n";
        C.transpose();
        C.print();
        cout<<"get\n";
        C.getCols();
        C.getRows();
        C.print();
#ifdef Lock
        cout<<"second matrix"<<endl;
        Matrix B(3,3,0);
        Matrix C = A+B;
        cout<<"\nMatrix sum\n";
        C.print();
        Matrix C1 = A-B;
        cout<<"\nMatrix diff\n";
        C1.print();
        Matrix C2 = A*B;
        cout<<"\nMatrix Multiply=\n";
        C2.print();
        int scalar;
        cout<<"\ninput scalar\n"; cin>>scalar;
        Matrix C3 =A+scalar;
        cout<<"\nMatrix+scalar = \n";
        C3.print();
        Matrix C4 =A-scalar;
        cout<<"\nMatrix-scalar = \n";
        C4.print();
        Matrix C5 =A*scalar;
        cout<<"\nMatrix*scalar = \n";
        C5.print();
        Matrix C6 =A/scalar;
        cout<<"\nMatrix/scalar = \n";
        C6.print();
        cout<<"\nTransposed matrix A= \n";
        A.transpose();
        A.print();
        cout<<"\ncopy constructor: \n";
        Matrix D(C);
        D.print();

        cout<<"\ninput i and j\n";
        unsigned i,j;
        cout<<"i=";cin>>i;
        cout<<"j=";cin>>j;
        cout<<"your element is ";
        cout<<A(i,j);
#endif
return 0;}