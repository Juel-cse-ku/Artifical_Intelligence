#include<bits/stdc++.h>

using namespace std;

#define inf 10

int board_status(vector < vector < int > > game_board)
{
    int i,j;
    int player_1 = 0;
    int player_2 = 0;
    int winner = 0;

    for(i=0;i<3;i++)
    {
        if(game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2] && game_board[i][1] != 0)
        {
            winner = game_board[i][0];
            break;
        }
    }

    for(i=0;i<3;i++)
    {
        if(game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i] && game_board[0][i] != 0)
        {
            winner = game_board[0][i];
            break;
        }
    }
    if(game_board[0][0] == game_board[1][1] && game_board[1][1] ==game_board[2][2] && game_board[0][0] != 0)
    {
        winner = game_board[0][0];
    }
    if(game_board[0][2] == game_board[1][1] && game_board[1][1] ==game_board[2][0] && game_board[0][2] != 0)
    {
        winner = game_board[0][2];
    }

    if(winner == 1)
    {
        return 2;
    }
    else if(winner == 2)
    {
        return -2;
    }

    int empty_place = 0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(game_board[i][j] == 0)
            {
                empty_place++;
            }
        }
    }

    if(empty_place == 0)
    {
        return 0;
    }
    else
    {
        return -10;
    }

}

int alpha_beta_pruning(int active_player, int alpha, int beta, vector < vector < int > > game_board)
{
    if( board_status(game_board) != -10)
    {
        return board_status(game_board);
    }

    int i,j;
    int best_play;
    int current_play;
    if(active_player == 1)
    {
        best_play = -inf;
    }
    else if(active_player == 2)
    {
        best_play = inf;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(game_board[i][j] == 0)
            {
                vector < vector < int > > new_board = game_board;
                new_board[i][j] = active_player;
                current_play = alpha_beta_pruning(active_player == 1 ? 2:1,alpha,beta,new_board);

                if(active_player == 1)
                {
                    best_play = max(best_play, current_play);
                    alpha = max(alpha, best_play);
                }
                else if(active_player == 2)
                {
                    best_play = min(best_play, current_play);
                    beta = min(beta, best_play);
                }

                if(alpha >= beta)
                {
                    return best_play;
                }
            }
        }
    }
}

int player_turn(vector < vector < int > > intial_board)
{
    int i,j;
    int player_1 = 0;
    int player_2 = 0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(intial_board[i][j] == 1)
                player_1++;

            else if(intial_board[i][j] == 2)
                player_2++;
        }
    }

    if(player_1 == player_2)
        return 1;
    else if(abs(player_1 - player_2)==1)
    {
        if(player_1 < player_2)
            return 1;
        else
            return 2;
    }
    else
        return 0;
}

int main()
{
    vector < vector < int > > initial_board;
    int i,j,n;
    int winner;
    int active_player;

    cout << "0 = Blank" << endl << "1 = player_1" << endl << "2 = player_2" << endl << endl << "Table Data: " << endl;
    for(i=0;i<3;i++)
    {
        vector < int > row_board;
        for(j=0;j<3;j++)
        {
            cin >> n;
            row_board.push_back(n);
        }
        initial_board.push_back(row_board);
    }

    active_player =  player_turn(initial_board);

    if(active_player == 0)
    {
        printf("Invalid Board");
    }
    else
    {
         winner = alpha_beta_pruning(active_player, -inf, inf, initial_board);

          if(winner == 2)
            cout << "*** Player_1 won the game***" ;
          else if(winner == -2)
            cout << "*** Player_2 won the game***" ;
          else
            cout << "*** Game Draw***";
    }
    return 0;
}
