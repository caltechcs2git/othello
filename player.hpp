#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);


    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;

private: 
	Side side; 
	Side side_opp;
	Board board;

	bool CornerMove(Move * move);
	bool edgeMove(Move * move);
	bool nextToCornerMove(Move * move);
	Move *getHeuristicMove(vector<Move*> moves);
	Move * getMinimaxMove(vector<Move*> moves);
	int NaiveHeuristic(Board b);
	int ScoreHeuristic(int nboardscore, Move* move);
};

#endif
