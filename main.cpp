#include <iostream>
#include<math.h>

using namespace std;

void Enter (int mat[10][10],int row ,int col);
void addition (int result [10][10] , int matA [10][10], int matB[10][10],int row ,int col );
void print (int matrix [10][10],int row ,int col);
void sub (int result [10][10] , int matA [10][10], int matB[10][10],int row ,int col );
void multi (int matA[10][10] ,int matB[10][10] ,int row1,int  col2 ,int col1, int result[10][10]);
void factor (int mat [10][10],int wanted_i,int wanted_j, int store[10][10], int square_no );
int det (int mat[10][10], int square_no );





int main()
{
    int matrixA [10][10] ,result [10][10] , matrixB [10][10] ,  store[10][10] ,opration , rowA ,colA ,rowB , colB,adj[10][10],trans[10][10] ;
   // float inverse[10][10];
    cout << "Please enter dimensions of Matrix A:" << endl;
    cin >> rowA >> colA ;
    cout << "Please enter dimensions of Matrix B:" << endl;
    cin >> rowB >> colB ;
    cout << "Please enter values of Matrix A:"<<endl;
    Enter(matrixA ,rowA , colA);
    cout << "Please enter values of Matrix B:"<<endl;
    Enter(matrixB , rowB , colB);

    do
    {
        cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
        cin >> opration;
        if (opration==1||opration==2)
        {
            if (rowA==rowB&&colA==colB)
            {
                switch (opration)
                {
                case 1 : //addition
                    addition(result,matrixA,matrixB,rowA,colA);
                    print(result,rowA,colA);

                    break;
                default://substraction
                    sub(result,matrixA,matrixB,rowA,colA);
                    print(result,rowA,colA);


                }
            }
            else
            {
                cout << "The operation you chose is invalid for the given matrices."<<endl;
            }
        }
        else if ( opration==7 )
        {
            cout<< "Thank you!";
            break;
        }
        else if ((opration==3)&&(colA==rowB))
        {
            multi(matrixA,matrixB,rowA,colB,colA,result);
            print(result,rowA,colB);

        }
        else if (opration==5 && rowA==colA)
        {
           cout<< det(matrixA,rowA)<<endl;
        }
        else if (opration==6 && rowB==colB)
        {
           cout<< det(matrixB,rowB)<<endl;
        }
        else if (opration==4 )
        {
            float inverse[10][10];
                float s=det(matrixB,rowB);
                //&& (s!=0)
                if ((rowB==colB)&&(s!=0))
                {
                    if (rowB==1)
                    {
                        adj[0][0]=1;
                    }
                    else
                    {
                        for(int k =0 ; k < rowB ; k ++)
                            for(int h=0 ; h< rowB ; h++)
                            {
                                factor(matrixB,k , h ,store ,rowB);
                                adj[k][h]=pow(-1,(k+h))*det(store,rowB-1);
                            }


                              for (int i = 0; i < rowB; i++) {
                                for (int j = 0; j < colB; j++) {
                                  trans[i][j] = adj[j][i];
                                 inverse[i][j] = trans[i][j]/s;
                                }

                                }


                    }
                    if (rowB!=colA)
                    {
                        cout << "The operation you chose is invalid for the given matrices."<<endl;
                    }
                    else
                    {
                        float sum , multiplication[10][10];
                        int u [10][10];
                        for (int i=0 ; i < rowA ; i++)
                            for(int j=0 ; j<colB ; j++)
                                {
                                    sum =0;
                                    for (int h=0 ; h<colA ;h++ )
                                    {
                                        sum += (matrixA[i][h]*inverse[h][j]);
                                    }
                                    multiplication[i][j]=sum ;
                                    u[i][j]= round(multiplication[i][j]);
                                }
                         print(u,rowA,colB);

                    }

                }
        else
        {
            cout << "The operation you chose is invalid for the given matrices."<<endl;
        }
        }

        else
        {
            cout << "The operation you chose is invalid for the given matrices."<<endl;
        }

    }while( 1 );


    return 0;
}
void Enter (int mat[10][10],int row ,int col)
{
     for(int k = 0; k < row ; k++)
     {
       for(int h = 0; h < col; h++)
       {
           cin >> mat[k][h];
       }
     }
}


void addition (int result [10][10] , int matA [10][10], int matB[10][10],int row ,int col )
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j < col ; j++)
        {
            result[i][j]=matA[i][j]+matB[i][j];
        }
    }
}


void print (int matrix [10][10],int row ,int col)
{
    int i=0,j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if (matrix[i][j] !=-0)
            {
                cout<< matrix[i][j] << "\t";
            }
            else

            {
                cout << '0'<< "\t";
            }

        }
        cout << endl;
    }
}

void sub (int result [10][10] , int matA [10][10], int matB[10][10],int row ,int col )
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j < col ; j++)
        {
            result[i][j]=matA[i][j]-matB[i][j];
        }
    }
}

void multi (int matA[10][10] ,int matB[10][10] ,int row1,int  col2 ,int col1, int result[10][10])
{
   int sum ;
   for(int i=0 ; i < row1 ; i++)
   {
       for(int j=0 ; j<col2 ; j++)
       {
           sum = 0;
           for(int h=0 ; h<col1 ; h++)
           {
               sum=sum+(matA[i][h]*matB[h][j]);

           }
           result[i][j]=sum;
       }
   }
}

void factor (int mat [10][10],int wanted_i,int wanted_j, int store[10][10], int square_no )
{
    int k=0 , h=0 ;
    for(int r=0 ; r<square_no ; r++)
    {
        for(int c=0 ; c< square_no ; c++ )
        {
            if (r!= wanted_i && c!= wanted_j)
            {
                store[k][h++]=mat[r][c];
                //h++;
                if (h==(square_no-1))
                {
                    h=0;
                    k++;
                }
            }

        }
    }
}




int det (int mat[10][10], int square_no )
{
    int determinant=0;
    int store [10][10];
    int sign = 1;
        if (square_no==1)
        return mat[0][0];

            for (int c=0 ; c<square_no ; c++ )
            {
                factor(mat,0,c,store,square_no);
                determinant+=sign * mat[0][c]*det(store,square_no-1);
                sign=-sign;
            }
            return determinant;



}
