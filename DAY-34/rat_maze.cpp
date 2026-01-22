#include<iostream>
#include<vector>
using namespace std;
void getAns(vector<vector<int>> &maze, vector<string> &ans, int r, int c, int n, string path){
    if(r<0 || c<0 || r>=n || c>=n || maze[r][c]==0 ){
        return;
    }
    if(r==n-1 && c==n-1){
        ans.push_back(path);
        path="";
        return;
    }
    maze[r][c]=0;
    
    getAns(maze, ans, r+1, c, n, path+"D");//down
    getAns(maze, ans, r-1, c, n, path+"U");//up
    getAns(maze, ans, r, c+1, n, path+"R");//right
    getAns(maze, ans, r, c-1, n, path+"L");//left

    maze[r][c]=1;


}
int main(){
    vector<vector<int>> maze ={{1,0,0,0}, {1,1,0,1},{1,1,0,0},{0,1,1,1}};
    int n =maze.size();
    vector<string> ans;
    
    getAns(maze, ans, 0, 0, n, "");

    for(string ele : ans){
        cout << ele;
        cout << endl;
    }

    return 0;
}