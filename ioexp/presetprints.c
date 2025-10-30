#include <stdio.h>

int main(void)
{
    char *fileLib[] = {"file1.txt", "file2.txt", "file3.txt"};
    char *userStr;
    FILE *file_ptr;

    int i = 0;

    printf("Please choose a save file.\n");
    printf("File 1\nFile 2\nFile 3\n");

    scanf("%d", &i);

    printf("Please enter some text.\n");

    scanf("%s", &*userStr);

    file_ptr = fopen(fileLib[i], "w");
    fprintf(file_ptr, "%s\n", userStr);
    fclose(file_ptr);
    return 0;
}