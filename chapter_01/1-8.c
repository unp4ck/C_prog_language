#include <stdio.h>

/**
 *
 *  coubt tabs, news lines and blanks
 */

int main()
{
    int count_tabs, count_lines, count_blanks;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            ++count_tabs;
            printf("[*] Qtd tabs: %d\n", count_tabs);
        }

        if (c == ' ')
        {
            ++count_blanks;
            printf("[*] Qtd blanks: %d\n", count_blanks);
        }

        if (c == '\n')
        {
            ++count_lines;
            printf("[*] Qtd  lines: %d\n", count_lines);
        }
    }

    return 0;
}