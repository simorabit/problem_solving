#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool isFound(vector<vector<char>> &board, string &word, int index, int i, int j)
    {
        if (index == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[index])
            return false;

        // char temp = board[i][j];
        board[i][j] = '+';

        bool found = isFound(board, word, index + 1, i + 1, j) ||  // Down
                     isFound(board, word, index + 1, i - 1, j) ||  // Up
                     isFound(board, word, index + 1, i, j + 1) ||  // Right
                     isFound(board, word, index + 1, i, j - 1);    // Left

        // board[i][j] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // Start backtracking if the first character matches
                if (board[i][j] == word[0] && isFound(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<char> > vec = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
   std::cout << sol.exist(vec,"ABCB") << std::endl;
}