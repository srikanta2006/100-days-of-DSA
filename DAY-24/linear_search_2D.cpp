#include<iostream>
using namespace std;

bool Lsearch(int matrix[][3], int row, int col, int ele){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j]==ele){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int row=3;
    int col=3;
    int ele1=5;
    int ele2=15;

    cout << "Searching for ele1"<<endl;
    cout << Lsearch(matrix, row, col, ele1)<<endl;
    cout << "Searching for ele2"<<endl;
    cout << Lsearch(matrix, row, col, ele2)<<endl;

    return 0;
}