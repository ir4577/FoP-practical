#include <stdio.h>

int main()
{
    FILE *source,*destination;
    char ch;
    source=fopen("source.txt","w");
    fprintf(source,"Hello World\n");
    fprintf(source,"Welcome to Pune\n");
    fclose(source);
    source=fopen("source.txt","r");
    destination=fopen("destination.txt","w");
    while ((ch=fgetc(source))!=EOF)
    {
        fputc(ch,destination);
    }
    fclose(source);
    fclose(destination);
    printf("File copied successfully.\n");
    destination=fopen("destination.txt","r");
    printf("Destination file will contain:\n");
    while ((ch=fgetc(destination))!=EOF)
    {
        putchar(ch);
    }
    fclose(destination);
}