#include <stdio.h>

int hoursToSecs(int hours) {
    return hours * 3600;
}

int minutesToSecs(int minutes) {
    return minutes*60;
}

int vreme(int hours, int minutes, int seconds) {
    int secs12hr = hoursToSecs(12);
    int currentSecs = hoursToSecs(hours) + minutesToSecs(minutes) + seconds;
    int secsToMidnight = secs12hr - currentSecs;
    return secsToMidnight;
}

int main()
{
    int hours, minutes, seconds;
    printf_s("What time is it now? (in format hh:mm:ss)");
    scanf_s("%d:%d:%d", &hours, &minutes, &seconds);
    printf_s("There are %d seconds to midnight", vreme(hours, minutes, seconds));
    return 0;
}
