#include "console.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    // Variabel global
    Array game;
    HistoryStack gamehistory;
    TabMap scoreboard;
    Queue antrian;
    MakeEmpty(&game);
    CreateEmptyStackHistory(&gamehistory);
    CreateQueue(&antrian);
    MakeEmptyArrayMap(&scoreboard);

    // Initial output
    printf("Selamat datang di BNMO ^w^\n\n");
   
    // Inisiasi input
    char *input;
    char *command;
    char *arg;
    
    // Loop utama
    // (str_comp(command.TabWord, quit))||(str_comp(command.TabWord, help))
    boolean load = false;
    boolean over = false;
    while (!load){
        printf("ENTER COMMAND: ");
        input = READINPUT();

        if (blank_count(input) == 0)
        {
            if (str_comp(input , "START"))
            {
                STARTGAME(&game , &scoreboard);
                load = true;
            }

            else if (str_comp(input, "HELP"))
            {
                HELP();
            }
            else{
                printf("Perintah yang dapat digunakan hanya START, LOAD, atau HELP\n");
            }
            printf("\n");
        }
        else if(blank_count(input) == 1)
        {
            command = KataPertama(input);
            arg = KataKedua(input);

            if (str_comp(command , "LOAD"))
            {
                char * dir;
                    dir = filetodir(arg);
                    LOAD(&game, &gamehistory, &scoreboard, dir);
                    if (game.Neff < 0)
                    {
                        printf("Save file gagal dibaca. Coba lagi\n");
                    }
                    else
                    {
                    printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                    load = true;
                    }
            }
            else{
                printf("Perintah yang dapat digunakan hanya START, LOAD, atau HELP\n");
            }
        }

        else 
        {
            printf("Perintah yang dapat digunakan hanya START, LOAD, atau HELP\n");
        }


        while(load && !over)
        {
            printf("ENTER COMMAND: ");
            input = READINPUT();

            if(blank_count(input) > 1)
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
            else
            {

                if (str_comp(input, "CREATE GAME")){
                    CREATEGAME(&game , &scoreboard);
                }
                else if (str_comp(input, "LIST GAME")){
                    LISTGAME(&game);
                }
                else if (str_comp(input, "DELETE GAME")){
                    DELETEGAME(&game, &antrian , &scoreboard);
                }
                else if (str_comp(input, "QUEUE GAME")){
                    QUEUEGAME(&antrian, game);
                }
                else if (str_comp(input, "PLAY GAME")){
                    PLAYGAME(&antrian, game , &scoreboard , &gamehistory);
                }
                else if (str_comp(input, "SCOREBOARD")){
                    SCOREBOARD(scoreboard , game);
                }
                else if (str_comp(input, "RESET SCOREBOARD")){
                    RESETSCOREBOARD(&scoreboard , game);
                }
                else if (str_comp(input, "RESET HISTORY")){
                    RESETHISTORY(&gamehistory);
                }
               
                else if (str_comp(input, "QUIT")){
                    over =true;
                }
                else if (str_comp(input, "HELP")){
                    HELP();
                }
                else if(blank_count(input)== 1)
                {
                    command = KataPertama(input);
                        arg = KataKedua(input);
                    if(str_comp(command , "SKIPGAME"))
                    { 
                        int num = StrToInt_input(arg, str_len(arg));
                        SKIPGAME(&antrian, num , game , &scoreboard , &gamehistory);
                    }
                    else if (str_comp(command, "SAVE"))
                    {
                        SAVE(game, gamehistory , scoreboard , arg);
                    }
                    else if (str_comp(command, "HISTORY"))
                    {
                        int num = StrToInt_input(arg, str_len(arg));
                        HISTORY(&gamehistory , num);
                    }
                    // else if (str_comp(command , "LOAD"))
                    // {
                    //     char * dir;
                    //         dir = filetodir(arg);
                    //         LOAD(&game, &gamehistory, &scoreboard , dir);
                    //         if (game.Neff < 0)
                    //         {
                    //             printf("Save file gagal dibaca. Coba lagi\n");
                    //         }
                    //         else
                    //         {
                    //         printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n");
                    //         load = true;
                    //         }
                    // }
                    else
                    {
                        printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                    }
                }
                else{
                    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
                }
            }
            printf("\n");   
        }

   
    }
    if(over)
    {
        printf("Anda keluar dari game BNMO.\n");
        printf("Bye bye ...\n");

    }
    return 0;
}