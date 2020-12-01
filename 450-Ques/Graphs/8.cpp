#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>&image, int row, int col, int newColor, int colorToReplace) {
    if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != colorToReplace) {
        return;
    }
    
        image[row][col] = newColor;

        helper(image, row + 1, col, newColor, colorToReplace);
        helper(image, row - 1, col, newColor, colorToReplace);
        helper(image, row, col + 1, newColor, colorToReplace);
        helper(image, row, col - 1, newColor, colorToReplace);
}

vector<vector<int>> solve(vector<vector<int>>& image, int sr, int sc, int newColor) {
   helper(image, sr, sc, newColor, image[sr][sc]); 
    
    return image;
}


int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> res = solve(image, 1, 1, image[1][1]);

    for(auto arr : res) {
        for(int x : arr) cout << x << " ";
        cout << endl;
    }
    return 0;    
}
