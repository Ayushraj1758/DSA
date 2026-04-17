// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
        
//     }    bool solve(vector<vector<char>>& board){
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[0].size();j++){
//                 if(board[i][j]=='.'){
//                     for(char c='1';c<='9';c++){
//                     if(isvalid(board,i,j,c)){
//                         board[i][j]=c;
//                         if(solve(board)==true)return true;
//                         // else return false;
//                         board[i][j]='.';

//                     }

//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;

//     }
//     bool isvalid(vector<vector<char>>& board,int i,int j,char c){
//         for(int k=0;k<9;k++){
//         if(board[k][j]==c)return false;
//         if(board[i][k]==c)return false;
//         if(board[3*(i/3)+(k/3)][3*(j/3)+k%3]==c)return false;
//         }
//         return true;
//     }


// };
class Solution {
public:
    bool solve(vector<vector<char>>& board,
               vector<vector<int>>& row,
               vector<vector<int>>& col,
               vector<vector<int>>& box) {

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){

                    for(char c='1'; c<='9'; c++){
                        int num = c - '1';
                        int boxIndex = (i/3)*3 + (j/3);

                        if(row[i][num]==0 && col[j][num]==0 && box[boxIndex][num]==0){

                            board[i][j] = c;
                            row[i][num] = col[j][num] = box[boxIndex][num] = 1;

                            if(solve(board,row,col,box)) return true;

                            // backtrack
                            board[i][j] = '.';
                            row[i][num] = col[j][num] = box[boxIndex][num] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        vector<vector<int>> row(9, vector<int>(9,0));
        vector<vector<int>> col(9, vector<int>(9,0));
        vector<vector<int>> box(9, vector<int>(9,0));

        // pre-fill
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    int boxIndex = (i/3)*3 + (j/3);

                    row[i][num] = 1;
                    col[j][num] = 1;
                    box[boxIndex][num] = 1;
                }
            }
        }

        solve(board, row, col, box);
    }
};