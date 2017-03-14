Othello Short Answers

Descrive how and what each group member contributed for the past two weeks. 

We worked on most of the questions together, from the planning step to implementing
the code to debugging and testing. The first task we aimed to complete was getting
familiar with Git - both of us did this step on our own and then checked if we achieved
the desired results at the end. Then, we implemented a basic, working AI that determined
the current legal moves and chose a random move to execute. Asta wrote out the code and 
Ishani helped debug and make changes as necessary. The code was tested throughout
the process. We worked in the same way on the simple heuristic function. We ran into 
some problems during this portion, for example with writing seperate cases for
the edge and corner  cases. For the second week, we decided to update our simple 
heuristic function by having our AI "look into the future" using a simple minimax 
algorithm. To achieve this, we decided to split up the work. Asta worked on writing 
the code framework and Ishani helped suggest improvements and update the readme
documents. 

Document the improvements that your group made to your AI to make it tournament-
worthy. 

Our old AI utilized a simple heuristic format - a running score was kept which took
into account special cases such as corners and edges. The heuristic we used relied on 
calculating the board position score (the number of stones the player's opponent has
subtracted from the number of stones the player has). To improve on this heuristic, 
we first fixed our modifiers so that scores calculated reflected if the move was favorable
or not more accurately. We did this by changing the multipliers to better account for
edge cases. Furthermore, a new method was added to return the score for easier use in a minimax function.
Then, we attempted to make a minimax, using heuristic scoring to decide the move returned because our algorith
as it stood calculated the best move in the short room, but its greedy nature left
us susceptible to lose by large amounts in a tournament setting. To implement a 
simple minimax algorithm, we decided to use two levels of branches calculating the
score for all of the different possibilities. Then, we chose the branch which returned
the highest lowest score. We had difficulties finding out how to store the updated
scores throughout each loop. 


Explain why you think your strategy(s) will work. 

We think our strategy will work because if our opponent is intelligent (which we are
assuming it is), a minimax algorithm will make our AI less vulnerable to "critical hits"
whereas the simple heuristic only outputs immediate, short-term moves. 





