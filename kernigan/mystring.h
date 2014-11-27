/* copy 'to' from 'from'; assume it is big enough */
void copy(char to[], char from[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}

void squeeze(char word[], int c) {
    int i, j;

    j = 0;

    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] != c) {
            word[j] = word[i];
            j++;
        }
    }

    // to loop finishes when '\0' is found at the end of the character array
    // so we have to add it ourselves
    word[j] = '\0';

}
