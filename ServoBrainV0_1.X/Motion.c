#include "Motion.h"

struct AccelTable accelTable;
struct State currentState;
struct State targetState;

signed long MoveAbsolute(const struct State *const current, const struct State *const target)
{
    signed long stoppingDistance = AccelDistance(current, target);
    signed long distanceToTarget = target->s - current->s;
    if(distanceToTarget > 0)
    {
        if(distanceToTarget > stoppingDistance)
        {
            
        }
        else
        {
            
        }
    }
    else
    {
        if(distanceToTarget < stoppingDistance)
        {
           
        }
        else
        {
            
        }

    }




    return 0;
}

signed long AccelDistance(const struct State*const current, const struct State *const target)
{
    // Simulate from current.v to target.v and find elapsed distance
    signed long deltaV = target->v - current->v;
    struct State predicted;
    predicted.s = 0;
    predicted.v = (current->v<<8);      // Calcs are scaled up by 2^8
    if(deltaV > 0)
    {
        // Accelerate (use PositiveAccelTable)
        while(predicted.v < (target->v<<8))   // Step until up to target velocity
        {
            unsigned int tableIndex = ((((predicted.v) / STEP) + ((QTY_ENTRIES<<8)/2)) >> 8);
            //printf("Velocity: "); printf("%ld", predicted.v);  printf(" ");
            signed long A = accelTable.Positive[tableIndex];
            //printf("Accel: ");  printf("%ld", A);  printf(" ");
            predicted.v += A;
            //printf("Position: ");  printf("%ld", predicted.s);  printf("\n");
            predicted.s += predicted.v;
        }
        //printf("DistanceCovered: "); printf("%ld", (predicted.s>>8)); printf("\n");
        return (predicted.s>>8);
    }
    else
    {
        // Deccelerate (use NegativeTable)
        while(predicted.v > (target->v<<8))   // Step until up to target velocity
        {
            unsigned int tableIndex = (( (predicted.v>>8) / STEP) + (QTY_ENTRIES/2));
            //printf("Velocity: "); printf("%ld", predicted.v);  printf(" ");
            signed long A = accelTable.Negative[tableIndex];
            //printf("Accel: ");  printf("%ld", A);  printf(" ");
            predicted.v += A;
            //printf("Position: ");  printf("%ld", predicted.s);  printf("\n");
            predicted.s += predicted.v;
        }
        //printf("DistanceCovered: "); printf("%ld", (predicted.s>>8)); printf("\n");
        return (predicted.s>>8);
    }
}
