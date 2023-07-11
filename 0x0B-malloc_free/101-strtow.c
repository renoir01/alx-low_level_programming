#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str)
{
    int count = 0;
    int i, len;

    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            count++;
        }
    }

    return count;
}

char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
    {
        return NULL;
    }

    int num_words = count_words(str);
    char **words = malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
    {
        return NULL;
    }

    int word_idx = 0;
    int word_len = 0;
    int i, len;

    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            if (word_len == 0)
            {
                int j;
                for (j = i; j < len && str[j] != ' '; j++)
                {
                    word_len++;
                }
                words[word_idx] = malloc((word_len + 1) * sizeof(char));
                if (words[word_idx] == NULL)
                {
                    // Free memory allocated so far
                    for (int k = 0; k < word_idx; k++)
                    {
                        free(words[k]);
                    }
                    free(words);
                    return NULL;
                }
            }
            words[word_idx][i - (len - word_len)] = str[i];
        }
        else if (word_len > 0)
        {
            words[word_idx][word_len] = '\0';
            word_len = 0;
            word_idx++;
        }
    }

    if (word_len > 0)
    {
        words[word_idx][word_len] = '\0';
        word_idx++;
    }

    words[word_idx] = NULL;

    return words;
}

void print_tab(char **tab)
{
    if (tab == NULL)
    {
        printf("NULL\n");
        return;
    }

    int i;
    for (i = 0; tab[i] != NULL; i++)
    {
        printf("%s\n", tab[i]);
    }
}

int main(void)
{
    char **tab;

    tab = strtow("      ALX School         #cisfun      ");
    if (tab == NULL)
    {
        printf("Failed\n");
        return (1);
    }
    print_tab(tab);
    
    // Free memory
    for (int i = 0; tab[i] != NULL; i++)
    {
        free(tab[i]);
    }
    free(tab);

    return (0);
}
