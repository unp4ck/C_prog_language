#include <stdio.h>

#define IN_WORD     1   /* point in word */
#define OUT_WORD    0   /* point out of word */
#define MAX_LEN     20  /* max word length to consider */

/*
 * Reset the histogram to all 0's too clear it out
 */
void init_histogram(int histogram[], size_t histogram_length)
{
    int i;

    for (i = 0; i < histogram_length; ++i) {
        histogram[i] = 0;
    }
}

/*
 * Read input, character by character, and divide into
 * words which are counted the length of (up until the max
 * max length specified in histogram_length). If word is
 * actually longer, the histogram records is at max length.
 *
 * Count characters, a-z and A-Z, and increase length of word,
 * and add to histogram if length>0 when we hit a non-character
 */
void create_histogram_from_input(int histogram[], size_t histogram_length)
{
    int len=0;       /* length of current word */
    int c;           /* current character */
    int diffChars = 0; /*Diff chars*/

    /* Keep reading character until end of file */
    while ((c = getchar()) != EOF) {

         // Check if it is an character ...
         if ( ( c >= 'a' && c <= 'z') ||
              ( c >= 'A' && c <= 'Z') ||
              c == '-' ) {

            ++len; /* Increase length of current word */

        } else {
            /* ... it was not a character, so check if we have
             * a positive word length
             */
            ++diffChars;
            if (len > 0) {
                /* increment histogram entry for current word length */
                if (len >= histogram_length) {
                    len = histogram_length;
                }

                histogram[len - 1]++;
                
                len = 0; /* Reset length of current word */
            }
        }
    }
}

/* Pretty print the histogram vertically, with numbered x-
 * and y-axis. Only print as many columns as we have word lengths
 */
void print_histogram(int histogram[], size_t histogram_length)
{
    int i, j, c;
    const int y_axis_width = 4;

    int top_count = 0; /* Highest count of a given length */
    int max_length = 0; /* The longest word in histogram */

    /* Find the highest count, and longest word */
    for (i = histogram_length; i > 0; --i) {

       /* If max_length is not set, and we find a positive length
        * whilst going backwards, it is the longest word
        */
       if (max_length == 0 && histogram[i-1] > 0) {
           max_length = i;
       }

       /* Scan entire histogram to find the highest count of that length */
       if (histogram[i-1] > top_count) {
           top_count = histogram[i-1];
       }
    }

    /* print histogram from top to bottom */
    for (i = top_count; i > 0; i--) {

        /* print Y-axis */
        printf("%3d|", i); /* If this changes, change y_axis_width */

        /* print entries for each word length */
        for (j = 0; j < max_length; j++) {
            if (histogram[j] < i) {
                printf("   ");
            } else {
                printf(" # ");
            }
        }
        printf("\n");
    }

    /* print X-axis separator*/
    printf("%*s", y_axis_width, " ");
    for (i = 0; i < max_length; i++) {
        printf("---");
    }
    printf("\n");

    /* print X-axis numbers */
    printf("%*s", y_axis_width, " ");
    for (i = 0; i < max_length; i++) {
        printf("%2d ", i+1);
    }
    printf("\n");
}

int main()
{
    int histogram[MAX_LEN];

    /* Reset histogram */
    init_histogram(histogram, MAX_LEN);

    /* Read input, and fill out the histogram */
    create_histogram_from_input(histogram, MAX_LEN);

    /* Print out the histogram */
    print_histogram(histogram, MAX_LEN);

    return 0;
}