#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter a phone number ( (###) ###-#### ):");
    char phone[15];
    gets(phone);

    char* substring = strtok( phone, " " );

    int part = 0;
    int countryCode;
    long int number;
    while ( substring != NULL ) {

        if (part==0) {
            //  country code
            sscanf(substring, "(%d)", &countryCode);
        }
        else {
            char first[8];
            char second[5];
            sscanf(substring, "%3s-%4s", first, second);
            strcat(first,second);
            sscanf(first, "%ld", &number);
        }
        part++;
        substring = strtok( NULL, " " );
    }

    printf("The country is %d and the number is %ld\n", countryCode, number);
    return 0;
}
