#include <iostream>
using namespace std;

int main(){
    int matrix[3][4]={{1,2,3,5},{4,5,6,8},{7,8,9,10}};
    int max_sum=0;
    for(int j=0; j<4; j++){
        int col_sum=0;
        for(int i=0; i<3; i++){
            cout<< matrix[i][j] << " ";
            col_sum+=matrix[i][j];
        }
        max_sum=max(max_sum,col_sum);
        cout << endl;
    }
    cout << "The maximum column sum is "<<max_sum << endl;
    return 0;
}