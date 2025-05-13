#ifndef DATA_TYPES_H
#define DATA_TYPES_H
#include <stdio.h>

#define NUM_JUGS 2 // or 3

enum ACTIONS 
{
    FILL_JUG_0,	//0
    FILL_JUG_1, //1
    FILL_JUG_2, //2
    EMPTY_JUG_0, //3
    EMPTY_JUG_1,//4
    EMPTY_JUG_2,//5
    POUR_0_TO_1,//6
    POUR_1_TO_0, //7
    POUR_0_TO_2, //8
	POUR_1_TO_2, //9
	POUR_2_TO_0, //10
	POUR_2_TO_1,  //11
	
	ACTIONS_COUNT //12
};

typedef struct State
{
    int jug_levels[NUM_JUGS]; //Water level in each jug
    float h_n;
    
} State;

/*For example,
If there is 4 liters of water in the 5-liter jug and 1 liter of water in the 3-liter jug, 
the jug_levels array for the current State will look like {4, 1}. 
That is, the value of jug_levels[0] is 4 and the value of jug_levels[1] is 1.
-Riza
*/

// ================== YOU DO NOT NEED TO CHANGE THIS PART ======================

enum METHODS
{
	BreastFirstSearch = 1,   UniformCostSearch = 2,        DepthFirstSearch = 3,    
	DepthLimitedSearch= 4,   IterativeDeepeningSearch = 5, GreedySearch = 6,
    AStarSearch = 7, GeneralizedAStarSearch = 8  
};

// This struct is used to determine a new state and action in transition model
typedef struct Transition_Model
{
    State new_state;
    float step_cost;
}Transition_Model;

typedef struct Node
{
    State state;
    float path_cost;
    enum ACTIONS action; //The action applied to the parent to generate this node
    struct Node *parent;
    int Number_of_Child; // required for depth-first search algorithms
}Node;

typedef struct Queue  // Used for frontier
{
    Node *node;
    struct Queue *next;
}Queue;



#endif
