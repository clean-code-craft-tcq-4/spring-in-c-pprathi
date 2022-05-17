#include "stats.h"
#include "Alert.h"

void emailAlerter(void)
{
    //Increment the counter
    emailAlertCallCount += 1;
}

void ledAlerter(void)
{
    //Increment the counter
    ledAlertCallCount += 1;
}
