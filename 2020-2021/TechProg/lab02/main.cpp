#include "matrix_header.h"
using namespace std;

int main(){
        string m_name;
        unsigned option;
        unsigned i,j;
        unsigned usr_rows,usr_cols;
        Matrix A;
        Matrix B;
        Matrix C;
        double scalar;
        do {
            cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
            cout << "1. Create Matrix" << endl;
            cout << "2. Create copy of a Matrix" << endl;
            cout << "3. Matrix + Matrix" << endl;
            cout << "4. Matrix - Matrix" << endl;
            cout << "5. Matrix * Matrix" << endl;
            cout << "6. Matrix += Matrix" << endl;
            cout << "7. Matrix -= Matrix" << endl;
            cout << "8. Matrix *= Matrix" << endl;
            cout << "9. Matrix + scalar" << endl;
            cout << "10. Matrix - scalar" << endl;
            cout << "11. Matrix * scalar" << endl;
            cout << "12. Matrix / scalar" << endl;
            cout << "13. Matrix += scalar" << endl;
            cout << "14. Matrix -= scalar" << endl;
            cout << "15. Matrix *= scalar" << endl;
            cout << "16. Matrix /= scalar" << endl;
            cout << "17. Get element[i][j]" << endl;
            cout << "18. Set element[i][j]"<<endl;
            cout << "19. getRow() getCol()"<< endl;
            cout << "20. SetRow()"<< endl;
            cout << "21. SetCol()"<< endl;
            cout << "22. Transpose a Matrix" << endl;
            cout << "23. Print Matrix" << endl;
            cout << "24. SetParam" << endl;
            cout << "25. Open with a file"<<endl;
            cout << "26. "<<endl;
            cout << "0. exit" << endl;
            cin >> option;
switch(option){
        case 0:
                break;
        case 1:{
                cout<<"Operation Create a Matrix\n"<<endl;
                //cout<<"Matrix name: "; cin>>m_name;
                cout<<"Number of Rows: "; cin>>usr_rows;
                cout<<"Number of Cols: "; cin>>usr_cols;
                //cout<<"Copy Matrix name: "; cin>>m_name;
                A.setSize(usr_rows,usr_cols);
                A.SetParam();
                cout<<"Matrix has been created successfully"<<endl;
                A.print();
                break;
        }
        case 2:{
                cout<<"Operation Copy a Matrix\n"<<endl;
                //cout<<"Copy Matrix name: "; cin>>m_name;
                //cout<<"New matrix name"; cin>>new_mat;
                B=A;
                B.print();
                break;
        }
        case 3:{
                cout<<"Matrix + Matrix\n"<<endl;
                //cout<<"first matrix: "; cin>>m_name;
                //cout<<"second matrix: "; cin>>new_mat;
                Matrix C;
                C = A+B;
                cout<<"A=\n";
                A.print();
                cout<<"\nB=\n";
                B.print();
                cout<<"A+B"<<endl;
                C.print();
                break;
        }
        case 4:{
                cout<<"Matrix - Matrix\n"<<endl;
                Matrix C;
                cout<<"A=\n";
                A.print();
                cout<<"\nB=\n";
                B.print();
                C = A-B;
                cout<<"A-B"<<endl;
                C.print();
                break;
        }
        case 5:{
                cout<<"Matrix * Matrix\n"<<endl;
                Matrix C;
                cout<<"A=\n";
                A.print();
                cout<<"\nB=\n";
                B.print();
                C = B*A;
                cout<<"A*B"<<endl;
                C.print();
                break;
        }
        case 6:{
                cout<<"Matrix += Matrix\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nB=\n";
                B.print();
                A+=B;
                cout<<"A+=B"<<endl;
                A.print();
                break;
        }
        case 7:{
                cout<<"Matrix -= Matrix\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nB=\n";
                B.print();
                A-=B;
                cout<<"A-=B"<<endl;
                A.print();
                break;
        }
        case 8:{
                cout<<"Matrix *= Matrix\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nB=\n";
                B.print();
                A*=B;
                cout<<"A*=B"<<endl;
                A.print();
                break;
        }
        case 9:{
                cout<<"Matrix + scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                Matrix C;
                C=A+scalar;
                cout<<"A+scalar"<<endl;
                C.print();
                break;
        }
        case 10:{
                cout<<"Matrix - scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                Matrix C;
                C=A-scalar;
                cout<<"A-scalar"<<endl;
                C.print();
                break;
        }
        case 11:{
                cout<<"Matrix * scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                Matrix C;
                C=A*scalar;
                cout<<"A*scalar"<<endl;
                C.print();
                break;
        }
        case 12:{
                cout<<"Matrix / scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                Matrix C;
                C=A/scalar;
                cout<<"A/scalar"<<endl;
                C.print();
                break;
        }
        case 13:{
                cout<<"Matrix += scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                A+=scalar;
                cout<<"A+=scalar"<<endl;
                A.print();
                break;
        }
        case 14:{
                cout<<"Matrix -= scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                A-=scalar;
                cout<<"A-=scalar"<<endl;
                A.print();
                break;
        }
        case 15:{
                cout<<"Matrix *= scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                A*=scalar;
                cout<<"A*=scalar"<<endl;
                A.print();
                break;
        }
        case 16:{
                cout<<"Matrix /= scalar\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\nscalar: "; cin>>scalar;
                A/=scalar;
                cout<<"A/=scalar"<<endl;
                A.print();
                break;
        }
        case 17:{
                cout<<"Get element\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"\ni= "; cin>>i;
                cout<<"j= "; cin>>j;
                bool what=A.El_exists(i,j);
                if(what==true){
                double value=A.Get_element(i,j);
                cout<<"A["<<i<<"]["<<j<<"]="<<value<<endl;
                }
                else{
                        cout<<"there's no element with that index"<<endl;
                }
                break;
        }
        case 18:{
                cout<<"Set element\n";
                cout<<"row: "; cin>>i;
                cout<<"col: "; cin>>j;
                double value;
                cout<<"Matrix["<<i<<"]["<<j<<"]= "; cin>>value;
                A.Set_element(i,j,value);
                break;

        }
        case 19:{
                cout<<"getRow getCol\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"rows: "<<A.getRows()<<endl;
                cout<<"cols: "<<A.getCols()<<endl;
                break;
        }
        case 20:{
                cout<<"SetRow\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"rows= "; cin>> usr_rows;
                A.Set_rows(usr_rows);
                A.print();
                break;
        }
        case 21:{
                cout<<"SetCol\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"cols= "; cin>> usr_cols;
                A.Set_cols(usr_cols);
                A.print();
                break;
        }
        case 22:{
                cout<<"Transpose\n"<<endl;
                cout<<"A=\n";
                A.print();
                cout<<"Transposing "<<endl;
                A.transpose();
                A.print();
                break;
        }
        case 23:{
                cout<<"Print\n"<<endl;
                cout<<"Printing "<<endl;
                A.print();
                break;
        }
        case 24:{
                cout<<"Set Parameters\n"<<endl;
                cout<<"Before setting\n";
                A.print();
                A.SetParam();
                cout<<"After setting\n";
                A.print();
                break;
        }
        case 25:{
                char file[256];
                cout<<"input a name:"; cin>>file;
                Matrix File(file);
                A = File;
                break;
        }
        case 26:{
                //+ out of class
                C.Setparam();
                B.SetParam();
                A=
        }
}

}while(option!=0);}
