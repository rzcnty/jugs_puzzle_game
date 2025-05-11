#ifndef TREE_SEARCH_H
#define TREE_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_types.h"

// ==================== CONFIG FOR JUGS PUZZLE ===========================
#define PREDETERMINED_GOAL_STATE  1
#define ACTIONS_NUMBER            6
#define MAX_SEARCHED_NODE         100000

#define NO_ACTION  0
#define TRUE       1
#define FALSE      0
#define FAILURE    NULL

#define JUG_A_CAPACITY 3
#define JUG_B_CAPACITY 5
#define GOAL_AMOUNT    4  // Change as needed

// ============== STRUCTURE FOR JUG PUZZLE ===============================
// Should be defined in data_types.h:
// typedef struct {
//     int jugA;
//     int jugB;
// } State;
//
// typedef enum ACTIONS {
//     FILL_A,
//     FILL_B,
//     EMPTY_A,
//     EMPTY_B,
//     POUR_A_TO_B,
//     POUR_B_TO_A
// } ACTIONS;

// ============= FUNCTION DECLARATIONS AND DEFINITIONS ==================

// --- 1. Create Initial State (both jugs empty) ---
State* Create_State() {
    State* state = (State*)malloc(sizeof(State));
    if (state == NULL) {
        printf("Memory allocation failed in Create_State()\n");
        exit(EXIT_FAILURE);
    }
    state->jugA = 0;
    state->jugB = 0;
    return state;
}

// --- 2. Print State (visual format) ---
void Print_State(const State *const state) {
    printf("Jug A: %d L, Jug B: %d L\n", state->jugA, state->jugB);
}

// --- 3. Print Action ---
void Print_Action(const enum ACTIONS action) {
    switch(action) {
        case FILL_A:      printf("Fill Jug A\n"); break;
        case FILL_B:      printf("Fill Jug B\n"); break;
        case EMPTY_A:     printf("Empty Jug A\n"); break;
        case EMPTY_B:     printf("Empty Jug B\n"); break;
        case POUR_A_TO_B: printf("Pour A -> B\n"); break;
        case POUR_B_TO_A: printf("Pour B -> A\n"); break;
        default:          printf("Unknown Action\n");
    }
}

// --- 4. Goal Test (is any jug at GOAL_AMOUNT?) ---
int Goal_Test(const State *const state, const State *const goal_state) {
    return (state->jugA == GOAL_AMOUNT || state->jugB == GOAL_AMOUNT);
}

// --- 5. Apply Action (Result Function) ---
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model) {
    State* new_state = (State*)malloc(sizeof(State));
    if (new_state == NULL) {
        printf("Memory allocation failed in Result()\n");
        exit(EXIT_FAILURE);
    }

    new_state->jugA = parent_state->jugA;
    new_state->jugB = parent_state->jugB;

    switch(action) {
        case FILL_A:
            new_state->jugA = JUG_A_CAPACITY;
            break;
        case FILL_B:
            new_state->jugB = JUG_B_CAPACITY;
            break;
        case EMPTY_A:
            new_state->jugA = 0;
            break;
        case EMPTY_B:
            new_state->jugB = 0;
            break;
        case POUR_A_TO_B: {
            int pour = fmin(new_state->jugA, JUG_B_CAPACITY - new_state->jugB);
            new_state->jugA -= pour;
            new_state->jugB += pour;
            break;
        }
        case POUR_B_TO_A: {
            int pour = fmin(new_state->jugB, JUG_A_CAPACITY - new_state->jugA);
            new_state->jugB -= pour;
            new_state->jugA += pour;
            break;
        }
        default:
            free(new_state);
            return FALSE;
    }

    trans_model->new_state = new_state;
    return TRUE;
}

// --- 6. Heuristic (how close we are to the goal amount) ---
float Compute_Heuristic_Function(const State *const state, const State *const goal) {
    int hA = abs(state->jugA - GOAL_AMOUNT);
    int hB = abs(state->jugB - GOAL_AMOUNT);
    return (float)(hA < hB ? hA : hB);
}

// ===================== OTHER DECLARATIONS FROM TEMPLATE ======================
Node* First_GoalTest_Search_TREE(const enum METHODS method, Node *const root, State *const goal_state);
Node* First_InsertFrontier_Search_TREE(const enum METHODS method, Node *const root, State *const goal_state, float alpha);
Node* DepthType_Search_TREE(const enum METHODS method, Node *const root, State *const goal_state, const int Max_Level);
Node* Child_Node(Node *const parent, const enum ACTIONS action);
Queue* Start_Frontier(Node *const root);
int Empty(const Queue *const frontier);
Node* Pop(Queue **frontier);
void Insert_FIFO(Node *const child, Queue **frontier);
void Insert_LIFO(Node *const child, Queue **frontier);
void Insert_Priority_Queue_UniformSearch(Node *const child, Queue **frontier);
void Insert_Priority_Queue_GreedySearch(Node *const child, Queue **frontier);
void Insert_Priority_Queue_A_Star(Node *const child, Queue **frontier);
void Insert_Priority_Queue_GENERALIZED_A_Star(Node *const child, Queue **frontier, float alpha);
void Print_Frontier(Queue *const frontier);
void Show_Solution_Path(Node *const goal);	
void Print_Node(const Node *const node);
int Level_of_Node(Node *const node);
void Clear_All_Branch(Node *node, int *Number_Allocated_Nodes);
void Clear_Single_Branch(Node *node, int *Number_Allocated_Nodes);
void Warning_Memory_Allocation();
int Compare_States(const State *const state1, const State *const state2);
Node* Frontier_search(Queue *const frontier, const State *const state);
void Remove_Node_From_Frontier(Node *const old_child, Queue **const frontier);

#endif

