#include "mesinkata.h"
#include <stdlib.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}

void STARTWORD()    {
    START();
    IgnoreBlanks();
    if (currentChar == MARK)    {
        EndWord = true;
    }
    else    {
        EndWord = false;
        CopyWord();
    }
}


void ADVWORD()  {
    IgnoreBlanks();
    if (currentChar == MARK)    {
        EndWord = true;
    }
    else    {
        CopyWord();
    }
}

void CopyWord() {
    int i;
    i = 0;  
    while ((currentChar != MARK) && (currentChar != BLANK ) && (i <= NMax-1)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (i > NMax-1) {
        while(currentChar != BLANK) {
            ADV();
        }
    }
    currentWord.Length = i;
}

void SalinWord(Word kata1, Word *kata2){
    kata2->Length = kata1.Length;
    for (int i = 0; i < kata1.Length; i++){
        kata2->TabWord[i] = kata1.TabWord[i];
    }
}

int StrToInt (char * str)
{
    int i=0 , output=0;
    for (int i = 0; i < currentWord.Length; i++)
    {
        output = output * 10 + (str[i] - '0');
    }
    return output;
}

int StrToInt_input(char *str, int length)
{
    int i;
    int res;
    res = 0;
    for (i = 0; i < length; i++)
    {
        res = res * 10 + (str[i] - '0');
    }
    return res;
}

int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
