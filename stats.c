#include "stats.h"

/**********************************************************************************************
 * Global variables
 *********************************************************************************************/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength)
{
    struct Stats s;
    int idx = 0;                                //Variable to iterate the numberset
    float sum = 0;                              //Variable to hold the sum
    s.min = 0;
    s.max = 0;
    s.average = 0;
    if(setlength > 0)
    {
        //Initialize the min and max
        s.min = *numberset;
        s.max = *numberset;
        //Determine the min, max and sum of the numberset
        for (idx = 0; idx < setlength; idx++)
            {
                sum += *numberset;
                if (s.min > *numberset)
                {
                    s.min = *numberset;
                }
                else if(s.max < *numberset)
                {
                    s.max = *numberset;
                }
                else
                {
                    //do nothing
                }
                numberset++;
            }
        //Determine the average
        s.average = sum/setlength;
    }
    else
    {
        s.min = s.min/setlength;
        s.max = s.max/setlength;
        s.average = s.average/setlength;
    }

    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    int idx = 0;    //Variable to iterate the funcptr
    //Check for the threshold and update the counters
    if(computedStats.max > maxThreshold)
    {
        //iterate the function pointer
        for(idx = 0; idx < 2; idx++)
        {
            alerters[idx]();
        }
    }
}
