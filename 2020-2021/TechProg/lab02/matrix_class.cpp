#include "matrix_header.h"
using namespace std;

Matrix::Matrix(unsigned rowSize, unsigned colSize)
{
    this->m_rowSize = rowSize;
    this->m_colSize = colSize;
    alloc();
}
Matrix::Matrix(const Matrix &B)
{
    this->m_colSize = B.getCols();
    this->m_rowSize = B.getRows();
    alloc();
    for (unsigned i = 0; i < m_rowSize; i++)
    {
        for (unsigned j = 0; j < m_colSize; j++){
                 this->m_matrix[i][j]=B.m_matrix[i][j];
        }
    }

}
Matrix::Matrix()
{
        this->m_rowSize = 0;
        this->m_colSize = 0;
        alloc();
}
Matrix::Matrix(const char* file)//file opener
{
        ifstream File_One(file); //to open a File
        if(File_One.is_open() && File_One.good())
        {       //unsigned row=0;
                //unsigned col=0;
                double element_One;
                unsigned count =0;
                cout<<"The file is open"<<endl;
                while(!File_One.eof())//count numbers
                {
                        File_One>>element_One;
                        count++;
                }
                File_One.clear();
                File_One.seekg(0, ios::beg);//to the beginning

                unsigned count_spaces=0;
                char symbol;
                while(!File_One.eof())//count all spaces in 1st line
                {
                        File_One.get(symbol);
                        if(symbol==' '){
                                count_spaces++;
                        }
                        if(symbol=='\n'){break;}
                }

                File_One.clear();
                File_One.seekg(0, ios::beg);//to the beginning

                count-=1;
                count_spaces+=1;
                this->m_rowSize=count/count_spaces;
                this->m_colSize=count_spaces;
                alloc();

                for(unsigned i=0; i<m_rowSize;i++)//write numbers
                {
                        for(unsigned j=0; j<m_colSize;j++){
                                File_One>>m_matrix[i][j];
                        }
                }

                for(unsigned i=0; i<m_rowSize;i++)//print numbers
                {
                        for(unsigned j=0; j<m_colSize;j++){
                                cout<<m_matrix[i][j]<<"  ";
                        }
                        cout<<"\n";
                }

                File_One.close();
        }

        else{
                cout<<"file not found\n";
        }

}

Matrix::~Matrix()
{
for(unsigned i=0;i < m_rowSize;i++){
            delete[] m_matrix[i];
}
 delete[] m_matrix;
}

void Matrix::SetParam()
{
        for (unsigned i = 0; i < m_rowSize; i++)
        {
            for (unsigned j = 0; j < m_colSize; j++){
                    cout<<"matrix {"<<i<<"}{"<<j<<"}= "; cin>>m_matrix[i][j];
            }
        }
}
//Matrix operators(by 1 matrix)
#ifdef k
Matrix Matrix::operator+(Matrix &B)
{
Matrix result(m_colSize, m_rowSize);
if(this->m_rowSize == B.getRows()|| this->m_colSize== B.getCols()){
unsigned i,j;
        for( i=0; i<m_rowSize;i++){
                for(j=0; j < m_colSize; j++){
                        result(i,j)=this->m_matrix[i][j]+B(i,j);
                }
        }
}
        return result;
}
Matrix Matrix::operator-(Matrix &B)
{
Matrix result(m_rowSize,m_colSize);
if(this->m_rowSize == B.getRows()|| this->m_colSize== B.getCols()){
unsigned i,j;
        for(i=0;i < m_rowSize;i++){
                for(j=0; j < m_colSize;j++){
                        result(i,j)=this->m_matrix[i][j]-B(i,j);
                }
        }
}
        return result;
}
Matrix Matrix::operator*(Matrix &B)
{
Matrix result(m_rowSize,B.getCols());
if(this->m_colSize==B.getRows()){
    unsigned i,j,k;
    for (i = 0; i < m_rowSize; i++)
    {
        for (j = 0; j < B.getCols(); j++)
        {
            for (k = 0; k < m_colSize; k++)
            {
                result(i,j)+= m_matrix[i][k] * B(k,j);
                }
        }
    }

}
   return result;
}
#endif

Matrix &Matrix::operator +=(const Matrix &B)
{
        if(this->m_rowSize != B.getRows() || this->m_colSize!= B.getCols())
        {
                cout<<"incorrect size, can't do this\n";
                return *this;
        }
        unsigned i,j;
        for( i=0; i<m_rowSize;i++)
         {
                 for(j=0; j < m_colSize; j++){
                         this->m_matrix[i][j]+=B.m_matrix[i][j];
                 }
         }
        return *this;
}

Matrix operator+(const Matrix &A,const Matrix &B)
{
        Matrix temp(A);
        temp+=B;
        return temp;
}

Matrix &Matrix::operator -=(const Matrix &B)
{
        if(this->m_rowSize != B.m_rowSize || this->m_colSize!= B.m_colSize)
        {
                cout<<"incorrect size, can't do this"<<endl;
                return *this;
        }
        unsigned i,j;
        for( i=0; i<m_rowSize;i++)
        {
                for(j=0; j < m_colSize; j++){
                        this->m_matrix[i][j]-=B.m_matrix[i][j];
                }
        }
        return *this;
}

Matrix operator-(const Matrix &A,const Matrix &B)
{
        Matrix temp(A);
        temp-=B;
        return temp;
}

Matrix &Matrix::operator *=(const Matrix &B)
{
Matrix result(m_rowSize,B.getCols());
        if(this->m_colSize!=B.getRows()){
            cout<<"incorrect size, can't do this\n";
            return *this;
        }
         unsigned i,j,k;
         for (i = 0; i < m_rowSize; i++)
         {
             for (j = 0; j < B.getCols(); j++)
             {
                 for (k = 0; k < m_colSize; k++)
                 {
                     result.m_matrix[i][j]+= (m_matrix[i][k] * B.m_matrix[k][j]);
                  }
             }
         }
         *this=result;
         return *this;
}

Matrix operator*(const Matrix &A,const Matrix &B)
{
        Matrix temp(A);
        temp*=B;
        return temp;
}

Matrix &Matrix::operator=(const Matrix &B)
{
        if(&B==this)
        {
                return *this;
        }
        else if(m_rowSize!=B.m_rowSize || m_colSize!=B.m_colSize)
        {
                for(unsigned i=0; i<m_rowSize;i++){
                        delete[] m_matrix[i];
                }
                delete[] m_matrix;
                m_rowSize=B.m_rowSize;
                m_colSize=B.m_colSize;
                alloc();
                for (unsigned i = 0; i < m_rowSize; i++)
                {
                    for (unsigned j = 0; j < m_colSize; j++){
                             this->m_matrix[i][j]=B.m_matrix[i][j];
                    }
                }
        }
        else
        {
        for (unsigned i = 0; i < m_rowSize; i++)
        {
            for (unsigned j = 0; j < m_colSize; j++){
                     this->m_matrix[i][j]=B.m_matrix[i][j];
            }
        }
        }
        return *this;
}

//scalar

Matrix &Matrix::operator+=(double scalar)
{
unsigned i,j;
for( i=0; i<m_rowSize;i++){
        for(j=0;j < m_colSize;j++){
                m_matrix[i][j]+=scalar;
        }
}
        return *this;
}
Matrix operator+(const Matrix &A, double scalar)
{
        Matrix temp(A);
        temp+=scalar;
        return temp;;
}

Matrix &Matrix::operator-=(double scalar)
{
unsigned i,j;
for( i=0; i<m_rowSize;i++){
        for(j=0;j < m_colSize;j++){
                m_matrix[i][j]-=scalar;
        }
}
        return *this;
}
Matrix operator-(const Matrix &A, double scalar)
{
        Matrix temp(A);
        temp-=scalar;
        return temp;;
}

Matrix &Matrix::operator*=(double scalar)
{
unsigned i,j;
for( i=0; i<m_rowSize;i++){
        for(j=0;j < m_colSize;j++){
                m_matrix[i][j]*=scalar;
        }
}
        return *this;
}
Matrix operator*(const Matrix &A, double scalar)
{
        Matrix temp(A);
        temp*=scalar;
        return temp;
}

Matrix &Matrix::operator/=(double scalar)
{
unsigned i,j;
for( i=0; i<m_rowSize;i++){
        for(j=0;j < m_colSize;j++){
                m_matrix[i][j]/=scalar;
        }
}
        return *this;
}
Matrix operator/(const Matrix &A, double scalar)
{
        Matrix temp(A);
        temp/=scalar;
        return temp;
}

double& Matrix::operator()( const unsigned &rowNum,const  unsigned &colNum)
{
return this->m_matrix[rowNum][colNum];
}

void Matrix::setSize(unsigned rowSize, unsigned colSize)
{
        Matrix temp(rowSize,colSize);
        if (rowSize>m_rowSize && colSize>m_colSize){
                for (unsigned i = 0; i <m_rowSize; i++)
                {
                    for (unsigned j = 0; j <m_colSize; j++){
                             temp.m_matrix[i][j]=m_matrix[i][j];
                    }
                }
        //if(temp.m_rowSize>m_rowSize || temp.m_colSize>m_colSize){
                for(unsigned i=0; i<rowSize-1;i++)//added cols
                {
                        for(unsigned j=m_colSize;j<colSize;j++){
                                temp.m_matrix[i][j]=0;
                        }
                }
                for (unsigned i = m_rowSize; i < temp.m_rowSize; i++)//added rows
                {
                    for (unsigned j = 0; j < temp.m_colSize; j++){
                             temp.m_matrix[i][j]=0;
                    }
                }
                for(unsigned i=0;i < m_rowSize;i++){
                            delete[] m_matrix[i];
                }
                delete[] m_matrix;
        }
        else{
                for (unsigned i = 0; i < rowSize; i++)
                {
                    for (unsigned j = 0; j < colSize; j++){
                             temp.m_matrix[i][j]=m_matrix[i][j];
                    }
                }
                for(unsigned i=0;i < m_rowSize;i++){
                            delete[] m_matrix[i];
                }
                delete[] m_matrix;
        }
        m_rowSize=rowSize;
        m_colSize=colSize;
        alloc();
        for(unsigned i=0; i<m_rowSize;i++){
                for(unsigned j=0;j<m_colSize;j++){
                        m_matrix[i][j]=temp.m_matrix[i][j];
                }
        }
        // for(unsigned i=0;i < m_rowSize;i++){
        //             delete[] temp.m_matrix[i];
        // }
        // delete[] temp.m_matrix;
}

void Matrix::Set_element(const unsigned i, const unsigned j,const double value)
{
        m_matrix[i][j]=value;
}

double& Matrix::Get_element(const unsigned i, const unsigned j)
{
        return m_matrix[i][j];
}

void Matrix::Set_rows(unsigned rowSize)
{
        Matrix temp(rowSize,m_colSize);
        if (rowSize > m_rowSize){
                for (unsigned i = 0; i <m_rowSize; i++)
                {
                    for (unsigned j = 0; j <m_colSize; j++){
                             temp.m_matrix[i][j]=m_matrix[i][j];
                    }
                }
                for (unsigned i = m_rowSize; i < temp.m_rowSize; i++)//added rows
                {
                    for (unsigned j = 0; j < temp.m_colSize; j++){
                             temp.m_matrix[i][j]=0;
                    }
                }
                for(unsigned i=0;i < m_rowSize;i++){
                            delete[] m_matrix[i];
                }
                delete[] m_matrix;
        }
        else{
                for (unsigned i = 0; i < temp.m_rowSize; i++)
                {
                    for (unsigned j = 0; j < temp.m_colSize; j++)
                    {
                             temp.m_matrix[i][j]=m_matrix[i][j];
                    }
                }
                for(unsigned i=0;i < m_rowSize;i++){
                            delete[] m_matrix[i];
                }
                delete[] m_matrix;
        }
        m_rowSize=rowSize;
        alloc();
        for(unsigned i=0; i<m_rowSize;i++){
                for(unsigned j=0;j<m_colSize;j++){
                        m_matrix[i][j]=temp.m_matrix[i][j];
                }
        }
}

void Matrix::Set_cols(unsigned colSize)
{
        Matrix temp(m_rowSize,colSize);
        if (colSize>m_colSize){
                for (unsigned i = 0; i <m_rowSize; i++)
                {
                    for (unsigned j = 0; j <m_colSize; j++){
                             temp.m_matrix[i][j]=m_matrix[i][j];
                    }
                }
        //if(temp.m_rowSize>m_rowSize || temp.m_colSize>m_colSize){
                for(unsigned i=0; i<m_rowSize;i++)//added cols
                {
                        for(unsigned j=m_colSize;j<colSize;j++){
                                temp.m_matrix[i][j]=0;
                        }
                }
                for(unsigned i=0;i < m_rowSize;i++){
                            delete[] m_matrix[i];
                }
                delete[] m_matrix;
        }
        else{
                for (unsigned i = 0; i <temp.m_rowSize; i++)
                {
                    for (unsigned j = 0; j <temp.m_colSize; j++){
                             temp.m_matrix[i][j]=m_matrix[i][j];
                    }
                }
                for(unsigned i=0;i < m_rowSize;i++){
                            delete[] m_matrix[i];
                }
                delete[] m_matrix;
        }
        m_colSize=colSize;
        alloc();
        for(unsigned i=0; i<m_rowSize;i++){
                for(unsigned j=0;j<m_colSize;j++){
                        m_matrix[i][j]=temp.m_matrix[i][j];
                }
        }
}

unsigned Matrix::getRows()const
{
        return this->m_rowSize;
}

unsigned Matrix::getCols() const
{
        return this->m_colSize;
}

void Matrix::print()
{
unsigned i,j;
        for(i=0;i<m_rowSize;i++){
                for(j=0;j<m_colSize;j++){
                        cout<<"["<<m_matrix[i][j]<<"]\t";
                }
                cout<<"\n";
        }
}

Matrix Matrix::transpose()
{
Matrix result(m_colSize,m_rowSize);
unsigned i,j;
for( i=0; i < m_rowSize;i++){
        for(j=0;j < m_colSize;j++){
                result.m_matrix[j][i]=m_matrix[i][j];
        }
}
                *this=result;
                return *this;
}

void Matrix::alloc()
{
        m_matrix=new double *[m_rowSize];
        for(unsigned i=0;i<m_rowSize;i++){
                m_matrix[i]=new double[m_colSize];
        }
}
