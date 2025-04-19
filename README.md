# jugs_puzzle_game
# Details of the Project

C source code given in the attachment include various heuristic and blind search methods for the path problem from a starting point to a destination point on the Romanian map, which was handled in the course. The details of code will also be discussed in the lectures on 18.04.2025 and 25.04.2025. For the project assignment Each group will be assigned one of the following topics. Based on the assigned topic, you should develop a new C program by updating the necessary places (related to the topic of the problem and generalized A* search) in the C source code. Information about the places that need to be updated is given in the table below. The names, number, and types of the input and output parameters of the functions in the source code must remain unchanged. You should only update the function blocks where modifications are required.

## Update Table

| File Name             | Update                                                                                                                               |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| `GRAPH_SEARCH.c`      | -                                                                                                                                    |
| `HashTable.c`         | 1. `Generate_HashTable_Key()`                                                                                                        |
| `Standart_Search.c`   | 1. `First_InsertFrontier_Search_TREE()` <br> 2. `Insert_Priority_Queue_GENERALIZED_A_Star()`                                            |
| `SpecificToProblem.c` | All functions (New functions can be added if necessary.)                                                                          |
| `data_types.h`        | ~~1. `enum ACTIONS` <br> 2. `typedef struct State` <br> *(New variables and data types can be added if necessary.)* ~~                      | ~~-~~
| `GRAPH_SEARCH.h`      | 1. `PREDETERMINED_GOAL_STATE` <br> 2. `ACTIONS_NUMBER` <br> 3. `MAX_SEARCHED_NODE` <br> *(New variables and data types can be added if necessary.)* |
| `HashTable.h`         | 1. `HASH_TABLE_BASED_SIZE` <br> 2. `HASH_TABLE_INCREASING_RATE` <br> 3. `MAX_KEY_SIZE`                                                |

## The following information should be included in the project report:

1.  The definition of the problem with all details (states, initial state, actions, transition model, etc.)
2.  The definition of the heuristic function or heuristic functions that will be used
3.  As a result of performing several simulations (for different problem sizes and initial states), the results obtained for each algorithm (the solution path, path cost, number of nodes produced, number of nodes in memory, computation time, etc.)


The developed **C source codes (not including the exe file)**, the prepared **report** and the **presentation file** should be compressed and uploaded to online.yildiz.edu.tr before the deadline.

## Jugs Puzzle Game:

There are 1 tap, 1 drain and 2 jugs in this game. When the jugs are filled
from the tap, the entire jug is filled, and when the jug is emptied into the drain, the entire jug is
emptied. When transferring water from one jug to another, the suitable amount of water is
transferred, and the water is not wasted. The aim is to hold the exact amount of water in the
larger jug. For example, in the example below, the aim is to hold exactly 2 liters of water in the
larger jug when there are 5- and 3-liter jugs. Find solutions for two separate problems where
there are 2 jugs and 3 jugs.
(https://www.mathsisfun.com/games/jugs-puzzle.html)
