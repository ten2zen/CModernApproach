/* The program uses a loop to search the array of departure times
for the one closest to the time entered by user. Departure and
arrival times should be stored in arrays. */

#include <stdio.h>

int main(void)
{
	/* Store departure times in an array */
    int departures[8] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19,
                       12 * 60 + 47, 14 * 60, 14 * 60 + 45,
                       19 * 60, 21 * 60 + 45};

    /* Store arrival times in an array */
    int arrivals[8] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31,
                     15 * 60, 16 * 60 + 8, 17 * 60 + 55,
                     21 * 60 + 20, 23 * 60 + 58};

    int i, x, y, delta;
	int hour, minute;
	int enteredTimeSinceMidnight;
	int closestDeparture = departures[0];
	int closestArrival = arrivals[0];

	/* Prompt user for desired departure time */
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minute);

	/* Calculate entered time to time since midnight */
	enteredTimeSinceMidnight = (hour * 60) + minute;

	/* Calculate delta */
	delta = enteredTimeSinceMidnight - departures[0];

	printf("Closest departure time is ");

	/* Search for the closest departure time */
    for (i = 0; i < 8; i++)
    {
        if ((enteredTimeSinceMidnight - departures[i]) < delta)
        {
            closestDeparture = departures[i];
            closestArrival = arrivals[i];
            delta = enteredTimeSinceMidnight - departures[i];
        }
    }

	printf("%.2d:%.2d", closestDeparture / 60, closestDeparture % 60);

	if (closestDeparture / 60 < 12)
		printf("am");
	else
		printf("pm");
	printf("\nArriving at %d:%.2d", closestArrival / 60, closestArrival % 60);

	if (closestArrival / 60 < 12)
		printf("am");
	else
		printf("pm");

    putchar('\n');


	return 0;
}
