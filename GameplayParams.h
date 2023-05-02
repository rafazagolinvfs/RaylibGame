#pragma once

/*Since we don't have an editor, we will place parameters from gameplay aspects here.
Things like rows and columns amount, actors size (collision boundaries), distance offset position*/

#define COLUMNS_AMOUNT 5 //Enemy or breakable actors columns amount per row
#define ROWS_AMOUNT 5
#define OFFSET_X 1.4f
#define OFFSET_Y 150.f
#define MOV_SPEED 350.f
#define INITIAL_Y_POS -800.f

/*this will determine how many actors(obstacles or breakables) we will have available to poll from the list
* the reason why we are not simply multiplying the columns by rows amount is because the grid level cannot
* be entirely filled with actors. There always have to be at least one empty spot per row so that the player
* can passthrough
*/
#define ACTORS_AMOUNT 20 