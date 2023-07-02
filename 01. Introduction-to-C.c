/*
TASK 1. Geometric progression
*/

#include <stdio.h>
#include <math.h>

int main() {
    int first_term, third_term;
    scanf("%d %d", &first_term, &third_term);
    int common_ratio = (int) sqrt(third_term / first_term);
    int second_term = first_term * common_ratio;
    printf("%d %d\n", second_term, common_ratio);
    return 0;
}

/*
TASK 2. The sum of the digits of a five-digit number
*/

#include <stdio.h>

int main()
{
    int input_number = 0, sum_of_digits = 0;
    scanf("%d", &input_number);
    for (int i = 0; i < 5; i++)
    {
        sum_of_digits += input_number % 10;
        input_number /= 10;
    }
    printf("%d", sum_of_digits);
    return 0;
}

/*
TASK 3. An inverted five-digit number
*/

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int digits[5] = {0};
    int i = 0;
    while (N > 0) {
        digits[i++] = N % 10;
        N /= 10;
    }
    printf("%d\n", digits[0] * 10000 + digits[1] * 1000 + digits[2] * 100 + digits[3] * 10 + digits[4]);
}

/*
TASK 4. Time in seconds
*/

#include <stdio.h>

int main() {
    int hours = 0, minutes = 0, seconds = 0;
    scanf("%d%d%d", &hours, &minutes, &seconds);
    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    printf("%d", totalSeconds);
    return 0;
}

/*
TASK 5. Time in format
*/

#include <stdio.h>

int main() {
    int totalSeconds = 0;
    scanf("%d", &totalSeconds); 
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds / 60) % 60; 
    int seconds = totalSeconds % 60; 
    printf("%02d:%02d:%02d", hours, minutes, seconds); 
    return 0;
}






























