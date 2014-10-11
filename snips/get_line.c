#include <stdio.h>

#define MAXLINE  1000

int get_line(char line[], int maxline);

int main(int argc, char **argv)
{
        
        char buff[MAXLINE];

        int i;


        //printf("Hello world\n");

        i = get_line(buff, MAXLINE);        

        printf("buffer is %d characters long\n", i);

        printf("line is: %s", buff);
        
        
        return 0;        
}

int get_line(char line[], int maxline) 
{
        char c;
        int i;

        for (i = 0; i < maxline-1 && c != '\n' && ( c = getchar()) != 'EOF' && c != '\n'; ++i)

                line[i] = c;
      
        if (c == '\n') {
                line[i] = c;
                ++i;
        }


        line[i] = '\0';

        return i;

                
}
