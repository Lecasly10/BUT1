#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *my_substr(char *str1, int final, int begin)
{
    char *sortie = malloc(sizeof(char) * (final - begin + 1));

    for (int i = begin; i < final; i++)
        sortie[i - begin] = str1[i];
    sortie[final - begin] = '\0';
    return sortie;
}

int skip(char *str, int i, char sep1)
{
    for (; str[i + 1] != '\0' && str[i] != sep1; i++);
    return i;
}

static int count_space(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t'){
            count++;
            skip(str, i, ' ');
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

int arr_len(char **arr)
{
    int i = 0;

    for(; arr[i] != NULL; i++);
    return i;
}

void my_putstr(char *str)
{
    char c = '\n';

    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    write(1, &c, 1);
}

void print_revserse_word_array(char **arr)
{
    int l = arr_len(arr);

    for (int i = l - 1; i > 0; i--)
        my_putstr(arr[i]);
}

int main(int argc, char **argv)
{
    char **sw = NULL;
    int res = 0;
    if (argc == 2) {
        int fl = open(argv[1], O_RDWR);
        int size = taille(argv[1] + 1);
        char buffer[size];
        int re = read(fl, buffer, size);
        
        close(fl);
        buffer[size] = '\0';
        sw = my_str_to_word_array_upgrade(buffer, '\n');
        res = 1;
    }
    print_revserse_word_array(sw);
    return res;
}
