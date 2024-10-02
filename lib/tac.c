#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int count_space(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t'){
            count++;
            skip(str, i, ' ', '\t');
        }
    }
    return count;
}

static char *get_word(char *str, int i, int i_min)
{
    if (str[i] == ' ' || str[i] == '\t')
        return my_substr(str, i, i_min);
    if (str[i + 1] == '\0')
        return my_substr(str, i + 1, i_min);
    return my_substr(str, i, i_min);
}

char **my_str_to_word_array_upgrade(char *str, char sep1)
{
    char **result = malloc(sizeof(char *) * (count_space(str) + 2));
    int i_min;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            i_min = i;
            i = skip(str, i, sep1);
            result[j] = get_word(str, i, i_min);
            j++;
        }
    }
    result[j] = NULL;
    return result;
}

int taille(char *filepath)
{
    struct stat fileInfo;

    stat(filepath, &fileInfo);
    return fileInfo.st_size;
}

int my_len(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *swap(char *str)
{
    int t = my_len(str);
    char *res = malloc(sizeof(char) * (t + 1));

    for (int i = 0; str[i] != '\0'; i++)
        res[t - i -1] = str[i];
    res[t] = '\0';
    return res;
}

int main(int argc, char **argv)
{
    int res = 0;
    if (argc == 2) {
        int fl = open(argv[1], O_RDWR);
        int size = taille(argv[1] + 1);
        char buffer[size];
        int re = read(fl, buffer, size);
        char **sw = NULL;
        
        buffer[size] = '\0';
        sw = my_str_to_word_array_upgrade(buffer, '\n');
        sw = swap(buffer);
        printf("%s\n", sw);
        res = 1;
    }
    printf("res = %d\n", res);
}
