#include "player.hpp"

using namespace std;
// This is a test comment I am adding 

//Small change by Asta


/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) 
{
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    this->side = side;
    std::cerr << (side == WHITE) << std::endl;

    if(side == BLACK)
    {
    	this->side_opp = WHITE;
    }
    else
    {
    	this->side_opp = BLACK;
    }
}

/*
 * Destructor for the player.
 */
Player::~Player() 
{

}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) 
{
	Move * move;
	vector<Move*> moves;
	
	if(board.hasMoves(side))
	{
		//update the board with the opponent's move first
		board.doMove(opponentsMove, side_opp);
		moves = board.getMoves(side);

		if (testingMinimax)
		{
			move = getMinimaxMove(moves);
		}
		else
		{
			move = getHeuristicMove(moves);
		}

		board.doMove(move, side);
		return move;
	}
    return nullptr;
}

/*
@brief Calculates which move with a Minimax
@return returns the calculated move
*/
Move * Player::getMinimaxMove(vector<Move*> moves)
{
	Move* minimax;
	int nnboardScore;
	int max = -1000;

	for(unsigned int i = 0; i < moves.size(); i++)
	{
		Board copy1 = *(board.copy());
		copy1.doMove(moves[i], side);
		
		vector<Move*> moves_n = copy1.getMoves(side);

		for(unsigned int j = 0; j < moves_n.size(); j++)
		{
			Board copy2 = *(copy1.copy());
			copy2.doMove(moves_n[i], side);
			nnboardScore = NaiveHeuristic(copy2) - NaiveHeuristic(copy1);
			int score = ScoreHeuristic(nnboardScore, moves_n[i]);

			if (score > max)
			{
				max = score;
				minimax = moves[i];
			}
		}
	}
	return minimax;
}

/*
@brief Calculates which move with a simple heuristic
@return the move that results in the greatest boardscore.
*/
Move * Player::getHeuristicMove(vector<Move*> moves)
{
	Move * move;
	int bboardScore = NaiveHeuristic(board);
	int nboardScore;
	int max_score = -1000;

	for(unsigned int i = 0; i < moves.size(); i++)
	{
		Board copy = *(board.copy());
		copy.doMove(moves[i], side);
		nboardScore = NaiveHeuristic(copy) - bboardScore;

		int score  = ScoreHeuristic(nboardScore, moves[i]);

		if (score > max_score)
		{
			max_score = score;
			move = moves[i];
		}
		
	}
	return move; 
}

/*
@brief  Will calculate the score of a given move with weighted square spaces
@return  returns the calculated score.
*/
int Player::ScoreHeuristic(int nboardscore, Move* move)
{
	int n = nboardscore;
	if(CornerMove(move))
	{
		n = n * 10;
	}
	if(nextToCornerMove(move))
	{
		if(n)
			n = n * -3;
	}
	if(edgeMove(move))
	{
		n = n * 2;
	}
	return n;
}

/*
@brief calculates the naive board score: player's stones - opponent's stones
		after a move is performed
@return the integer representing the score
*/
int Player::NaiveHeuristic(Board b)
{
	return b.count(side) - b.count(side_opp);
}

/*
@brief This method checks to see if a move is in a board corner.
@return Returns true if move is in the corner
*/
bool Player::CornerMove(Move * move)
{
	if((move -> getX() == 0) && (move -> getY() == 0))
	{
		return true;
	}
	else if((move -> getX() == 7) && (move -> getY() == 7))
	{
		return true;
	}
	else if((move -> getX() == 0) && (move -> getY() == 7))
	{
		return true;
	}
	else if((move -> getX() == 7) && (move -> getY() == 0))
	{
		return true;
	}
	return false;
}

/*
@brief checks to see if a move is an edge move
@return  Returns true if it is an edge move
*/
bool Player::edgeMove(Move * move)
{
	if(!(CornerMove(move) || nextToCornerMove(move)))
	{
		if(move -> getX() == 0)
		{
			return true;
		} 
		else if (move -> getX() == 7)
		{
			return true;
		}
		else if (move->getY() == 0)
		{
			return true;
		}
		else if (move->getY() == 7)
		{
			return true;
		}
	}
	return false;
}

/*
@brief  This method checks to see if a move is next to a corner
@return  Returns true if the move is next to a corner
*/
bool Player::nextToCornerMove(Move * move)
{
	//upperleft
	if((move -> getX() == 0) && (move -> getY() == 1))
	{
		return true;
	}
	else if((move -> getX() == 1) && (move -> getY() == 0))
	{
		return true;
	}
	else if((move -> getX() == 1) && (move -> getY() == 1))
	{
		return true;
	}

	//lowerright
	else if((move -> getX() == 7) && (move -> getY() == 6))
	{
		return true;
	}
	else if((move -> getX() == 6) && (move -> getY() == 7))
	{
		return true;
	}
	else if((move -> getX() == 6) && (move -> getY() == 6))
	{
		return true;
	}

	//lowerleft
	else if((move -> getX() == 0) && (move -> getY() == 6))
	{
		return true;
	}
	else if((move -> getX() == 1) && (move -> getY() == 7))
	{
		return true;
	}
	else if((move -> getX() == 1) && (move -> getY() == 6))
	{
		return true;
	}

	//upperright
	else if((move -> getX() == 6) && (move -> getY() == 0))
	{
		return true;
	}
	else if((move -> getX() == 7) && (move -> getY() == 1))
	{
		return true;
	}
	else if((move -> getX() == 6) && (move -> getY() == 1))
	{
		return true;
	}

	return false;
}