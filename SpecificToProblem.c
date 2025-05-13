/* 
    These functions are compulsory for search algorithms but they are specific
    to problems. More clearly, you must must update their blocks but do not change
    their input and output parameters.
    
    Also, you can add new functions at the end of file by declaring them in GRAPH_SEARCH.h
*/

#include "GRAPH_SEARCH.h"
#include "data_types.h"
#include <stdio.h>
#include <stdlib.h>

#if NUM_JUGS==2
    const int JUG_CAPACITIES[NUM_JUGS] = {5, 3};
    const int TARGET_AMOUNT = 4;
#else
    const int JUG_CAPACITIES[NUM_JUGS] = {8, 5, 3};
    const int TARGET_AMOUNT = 4;
#endif
int choice_of_heuristic=0;

//______________________________________________________________________________
State* Create_State()
{
	State *state = (State*)malloc(sizeof(State));
    if(state==NULL)
    	Warning_Memory_Allocation(); 
   
    for (int i=0; i<NUM_JUGS; i++) {
        state->jug_levels[i] = 0;
    }
    
    printf("Initial status: ");
    Print_State(state);
    printf("\n");

    return state;    
}

//______________________________________________________________________________
void Print_State(const State *const state)
{
    if (state==NULL) {
        printf("NULL_State ");
        return;
    }

    for (int i = 0; i < NUM_JUGS; i++) {
        printf("%d ", state->jug_levels[i]);
    }
    printf("\n");
}

//______________________________________________________________________________
void Print_Action(const enum ACTIONS action)
{
    switch(action){
         case FILL_JUG_0:     printf("FILL_JUG_0"); break;
         case FILL_JUG_1:     printf("FILL_JUG_1"); break;
         case FILL_JUG_2:     printf("FILL_JUG_2"); break; 
         case EMPTY_JUG_0:    printf("EMPTY_JUG_0"); break;
         case EMPTY_JUG_1:    printf("EMPTY_JUG_1"); break;
         case EMPTY_JUG_2:     printf("EMPTY_JUG_2"); break;
         case POUR_0_TO_1:   printf("POUR_0_TO_1"); break;
         case POUR_1_TO_0:   printf("POUR_1_TO_0"); break;
         case POUR_0_TO_2:   printf("POUR_0_TO_2"); break;
         case POUR_1_TO_2:   printf("POUR_1_TO_2"); break;
         case POUR_2_TO_0:   printf("POUR_2_TO_0"); break;
         case POUR_2_TO_1:   printf("POUR_2_TO_1"); break;
    }
}

//______________________________________________________________________________
int Result(const State *const parent_state, const enum ACTIONS action, Transition_Model *const trans_model)
{
    State next_state;
    next_state=*parent_state;
    
	int amount_to_pour;
    int empty_space_in_target;
    
    if ((action==FILL_JUG_2 || action==EMPTY_JUG_2 || action==POUR_0_TO_2 ||action==POUR_2_TO_0 || action==POUR_1_TO_2 || action==POUR_2_TO_1) && (NUM_JUGS<3)) {    	
            return 0;
        }

    switch(action) {

        case FILL_JUG_0:
            if (next_state.jug_levels[0]==JUG_CAPACITIES[0]) return 0;
            next_state.jug_levels[0]=JUG_CAPACITIES[0];
            break;
        case FILL_JUG_1:
            if (next_state.jug_levels[1]==JUG_CAPACITIES[1]) return 0;
            next_state.jug_levels[1]=JUG_CAPACITIES[1];
            break;
        case FILL_JUG_2:
            if (next_state.jug_levels[2]==JUG_CAPACITIES[2]) return 0;
            next_state.jug_levels[2]=JUG_CAPACITIES[2];
            break;
        case EMPTY_JUG_0:
            if (next_state.jug_levels[0]==0) return 0;
            next_state.jug_levels[0]=0;
            break;
        case EMPTY_JUG_1:
            if (next_state.jug_levels[1]==0) return 0;
            next_state.jug_levels[1]=0;
            break;
        case EMPTY_JUG_2:
            if (next_state.jug_levels[2]==0) return 0;
            next_state.jug_levels[2]=0;
            break;
        case POUR_0_TO_1:
            if (next_state.jug_levels[0]==0 || next_state.jug_levels[1]==JUG_CAPACITIES[1]) return 0;
            amount_to_pour=next_state.jug_levels[0];
            empty_space_in_target=JUG_CAPACITIES[1]-next_state.jug_levels[1];
            if (amount_to_pour>empty_space_in_target) amount_to_pour=empty_space_in_target;
            next_state.jug_levels[0]-=amount_to_pour;
            next_state.jug_levels[1]+=amount_to_pour;
            break;
        case POUR_1_TO_0:
            if (next_state.jug_levels[1]==0 || next_state.jug_levels[0]==JUG_CAPACITIES[0]) return 0;
            amount_to_pour=next_state.jug_levels[1];
            empty_space_in_target=JUG_CAPACITIES[0]-next_state.jug_levels[0];
            if (amount_to_pour>empty_space_in_target) amount_to_pour=empty_space_in_target;
            next_state.jug_levels[1]-=amount_to_pour;
            next_state.jug_levels[0]+=amount_to_pour;
            break;
        case POUR_0_TO_2:
            if (next_state.jug_levels[0]==0 || next_state.jug_levels[2]==JUG_CAPACITIES[2]) return 0;
            amount_to_pour=next_state.jug_levels[0];
            empty_space_in_target=JUG_CAPACITIES[2]-next_state.jug_levels[2];
            if (amount_to_pour>empty_space_in_target) amount_to_pour=empty_space_in_target;
            next_state.jug_levels[0]-=amount_to_pour;
            next_state.jug_levels[2]+=amount_to_pour;
            break;
        case POUR_2_TO_0:
            if (next_state.jug_levels[2]==0 || next_state.jug_levels[0]==JUG_CAPACITIES[0]) return 0;
            amount_to_pour=next_state.jug_levels[2];
            empty_space_in_target=JUG_CAPACITIES[0]-next_state.jug_levels[0];
            if (amount_to_pour>empty_space_in_target) amount_to_pour=empty_space_in_target;
            next_state.jug_levels[2]-=amount_to_pour;
            next_state.jug_levels[0]+=amount_to_pour;
            break;
        case POUR_1_TO_2:
            if (next_state.jug_levels[1]==0 || next_state.jug_levels[2]==JUG_CAPACITIES[2]) return 0;
            amount_to_pour=next_state.jug_levels[1];
            empty_space_in_target=JUG_CAPACITIES[2]-next_state.jug_levels[2];
            if (amount_to_pour>empty_space_in_target) amount_to_pour=empty_space_in_target;
            next_state.jug_levels[1]-=amount_to_pour;
            next_state.jug_levels[2]+=amount_to_pour;
            break;
        case POUR_2_TO_1:
            if (next_state.jug_levels[2]==0 || next_state.jug_levels[1]==JUG_CAPACITIES[1]) return 0;
            amount_to_pour=next_state.jug_levels[2];
            empty_space_in_target=JUG_CAPACITIES[1]-next_state.jug_levels[1];
            if (amount_to_pour>empty_space_in_target) amount_to_pour=empty_space_in_target;
            next_state.jug_levels[2]-=amount_to_pour;
            next_state.jug_levels[1]+=amount_to_pour;
            break;
        default:
             printf("ERROR in Result Func");
             return 0;
    }
    trans_model->new_state=next_state;
    trans_model->step_cost = 1.0f;
    return 1;                                      
}

//______________________________________________________________________________
float Compute_Heuristic_Function(const State *const state, const State *const goal)
{
      (void)goal;
    switch(choice_of_heuristic) {
        case 0:
            return 0.0f;

        case 1:
            for (int i=0; i<NUM_JUGS; i++) {
                if (state->jug_levels[i]==TARGET_AMOUNT) {
                    return 0.0f;
                }
            }
            return 1.0f;

        case 2:
            {
                int min_diff=1000000;
                int current_diff;
                int goal_found=0;
                for(int i=0; i<NUM_JUGS; ++i){
                    if (state->jug_levels[i]== TARGET_AMOUNT) {
                        goal_found=1;
                        break;
                    }
                    current_diff=abs(state->jug_levels[i]-TARGET_AMOUNT);
                    if(current_diff<min_diff) {
                        min_diff=current_diff;
                    }
                }
                return goal_found ? 0.0f : (float)min_diff;
            }
            break;

        default:
            printf("ERROR in Heuristic\n");
            return 0.0f;
    }
}

//_______________ Update if your goal state is not determined initially ___________________________________
int Goal_Test(const State *const state, const State *const goal_state)
{
	(void)goal_state;

    int i;
    for (i= 0; i<NUM_JUGS; i++) {
        if (state->jug_levels[i] == TARGET_AMOUNT) {
            return 1;
        }
    }
    return 0;
}

// ==================== WRITE YOUR OPTIONAL FUNCTIONS (IF REQUIRED) ==========================

int Get_Actions(const State *const state, enum ACTIONS applicable_actions[]) {
    int count=0;
    enum ACTIONS action_to_test;
    Transition_Model temp_trans_model;

    for (action_to_test=FILL_JUG_0; action_to_test<ACTIONS_COUNT; action_to_test++) {
        if (Result(state,action_to_test,&temp_trans_model)==1) {
            if (count<ACTIONS_COUNT) {
                applicable_actions[count]=action_to_test;
                count++;
            } else {
                printf("ERROR in Get Act");
                break;
            }
        }
    }
    return count;
}

/*
The main purpose of this function is to find all applicable actions that can be taken at that moment 
for a current water container state and save them in an array (applicable_actions). 
Finally, it returns how many valid actions there are.
-riza
*/

// TR: Uygulanabilir eylemleri diziye atar ve kac eylem gerektigini verir.
