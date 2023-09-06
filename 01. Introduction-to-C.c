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

    printf("%d %d", second_term, common_ratio);

    return 0;
}

/*
TASK 2. The sum of the digits of a five-digit number
*/

#include <stdio.h>

int main() {
    int input_number = 0;
    scanf("%d", &input_number);

    int digit_sum = 0;
    digit_sum += input_number % 10;
    input_number /= 10;
    digit_sum += input_number % 10;
    input_number /= 10;
    digit_sum += input_number % 10;
    input_number /= 10;
    digit_sum += input_number % 10;
    input_number /= 10;
    digit_sum += input_number;

    printf("%d\n", digit_sum);

    return 0;
}

/*
TASK 3. An inverted five-digit number
*/

#include <stdio.h>
#include <math.h>

int main() {
    int input_number;
    scanf("%d", &input_number);

    int second_digit, third_digit, fourth_digit, fifth_digit;
    fifth_digit = input_number % 10;
    input_number/=10;
    fourth_digit = input_number % 10;
    input_number/=10;
    third_digit = input_number % 10;
    input_number/=10;
    second_digit = input_number % 10;
    input_number/=10;

    printf("%d\n", fifth_digit * 10000 + fourth_digit * 1000 + 
            third_digit * 100 + second_digit * 10 + input_number);

    return 0;
}

/*
TASK 4. Time in seconds
*/

#include <stdio.h>

int main() {
    int hours = 0, minutes = 0, seconds = 0;
    scanf("%d %d %d", &hours, &minutes, &seconds);

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