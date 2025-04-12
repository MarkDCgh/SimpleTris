#include <iostream>
#include <string>
#include "classi.h"

int menu_choice;
std::string namee1, namee2;
int many_games;
player1 p1;
player2 p2;
int i;
char a='1' , b='2' , c='3' , d='4', e='5', f='6', g='7' ,h='8', l='9';
int choice_dg; 
int continue_aftgame_O;
int continue_aftgame_x;


void start_game(){

    many_games = 0;
    std::cout<<"Player1, choose your name: ";
    getline(std::cin, namee1);
    p1.get_name1(namee1);

    system("cls");

    std::cout<<std::endl<<"Welcome Warrior!\tand Player2, what's yours? ";
    getline(std::cin, namee2);
    p2.get_name2(namee2);

    system("cls");

    std::cout<<"\nPerfect, let's start the war! but first choose how many games you are going to play,\n";
    std::cout<<"so nether of you will cheat: ";
    std::cin>>many_games;
    std::cin.ignore();
    i = 0;
    game();
}

void game(){

    while(i < many_games){
        system("cls"); 

        tris::tris_visual();

        if(tris::control_win_game() == 2){
            i++;
            tris::victory_X();
            continue;
        }

        std::cout<<std::endl;
        std::cout<<p1.see_name1()<<",\tO on: ";
        std::cin>>choice_dg;
        tris::change_sym_O(choice_dg);

        system("cls"); 

        tris::tris_visual();

        if(tris::control_win_game() == 1){
            i++;
            tris::victory_O();
            continue;
        }

        std::cout<<std::endl<<p1.see_name1()<<" chose "<<choice_dg<<"\n";
        std::cout<<"It's your turn "<<p2.see_name2()<<", where will you put your X?: ";
        std::cin>>choice_dg;
        tris::change_sym_X(choice_dg);

    }
}

void menu(){

    while(true){    
        a='1' , b='2' , c='3' , d='4', e='5', f='6', g='7' ,h='8', l='9';
        p1.victories_p1 = 0;
        p2.victories_p2 = 0;
        std::cout<<"\nGioca 1."<<std::endl;
        std::cout<<": ";
        
        std::cin>>menu_choice;
        if(menu_choice == 1){
            std::cin.ignore();
            start_game();
        }
    }
}



//CLASSES FUNCTIONS
//player1 CLASS
player1::player1(){
}

player1::player1(std::string username){
    p1.get_name1(username); 
}

void player1::get_name1(std::string name){
    name1 = name;
}

std::string player1::see_name1(){
    return name1;
}


//player2 CLASS
player2::player2(){
}

player2::player2(std::string username){
    p2.get_name2(username);
}

void player2::get_name2(std::string name){
    name2 = name;
}

std::string player2::see_name2(){
    return name2;
}


//tris CLASS
void tris::tris_visual(){
    std::cout<<std::endl<<std::endl<<std::endl<<std::endl;
    std::cout<<"\t"<<a<<" | "<<b<<" | "<<c<<"\n";
    std::cout<<"\t"<<d<<" | "<<e<<" | "<<f<<"\n";
    std::cout<<"\t"<<g<<" | "<<h<<" | "<<l<<"\n";
}

void tris::change_sym_O(int choice){

    switch(choice){
        case 1:
        a = 'O';
        break;

        case 2:
        b = 'O';
        break;

        case 3:
        c = 'O';
        break;

        case 4:
        d = 'O';
        break;

        case 5:
        e = 'O';
        break;

        case 6:
        f = 'O';
        break;

        case 7:
        g = 'O';
        break;

        case 8:
        h = 'O';
        break;

        case 9:
        l = 'O';
        break;

    }
}


void tris::change_sym_X(int choice){

    switch(choice){
        case 1:
        a = 'X';
        break;

        case 2:
        b = 'X';
        break;

        case 3:
        c = 'X';
        break;

        case 4:
        d = 'X';
        break;

        case 5:
        e = 'X';
        break;

        case 6:
        f = 'X';
        break;

        case 7:
        g = 'X';
        break;

        case 8:
        h = 'X';
        break;

        case 9:
        l = 'X';
        break;
    }
}


int tris::control_win_game(){
//ordini da seguire: 1 4 7      2 5 8       3 6 9       1 2 3       4 5 6       7 8 9       1 5 9       3 5 7      
//variabili form     /a d g      /b e h       /c f l       a b c       d e f       g h l       /a e l       /c e g

    //O PLAYER1
    if((a == 'O' && d == 'O' && g == 'O') || (c == 'O' && f == 'O' && l == 'O') || (a == 'O' && e == 'O' && l == 'O')){
        return 1;
    }
    if((b == 'O' && e == 'O' && h == 'O') || (c == 'O' && e == 'O' && g == 'O')){
        return 1;
    }
    if((a == 'O' && b == 'O' && c == 'O') || (d == 'O' && e == 'O' && f == 'O') || (g == 'O' && h == 'O' && l == 'O')){
        return 1;
    }

    //X PLAYER2
    if((a == 'X' && d == 'X' && g == 'X') || (c == 'X' && f == 'X' && l == 'X') || (a == 'X' && e == 'X' && l == 'X')){
        return 2;
    }
    if((b == 'X' && e == 'X' && h == 'X') || (c == 'X' && e == 'X' && g == 'X')){
        return 2;
    }
    if((a == 'X' && b == 'X' && c == 'X') || (d == 'X' && e == 'X' && f == 'X') || (g == 'X' && h == 'X' && l == 'X')){
        return 2;
    }
    return 3;
}


void tris::victory_O(){
    p1.victories_p1++;
    std::cout<<std::endl;
    if(i == many_games){
        control_winner_sess();
    }
    std::cout<<"\nCongratulazioni "<<p1.see_name1()<<", hai battuto "<<p2.see_name2();
    std::cout<<"\nContinuate la gara o "<<p2.see_name2()<<" si arrende? Bisogna arrivare a "<<many_games<<" partite";
    std::cout<<"\n 1.Continua\t2.Arrenditi\t: ";
    std::cin>>continue_aftgame_O;
    if(!(continue_aftgame_O == 1)){
        std::cout<<"Hai perso l'intera guerra "<<p2.see_name2()<<", "<<p1.see_name1()<<" e il VINCITORE!!!\n\n\n\n";
        p1.victories_p1 = 0;
        p2.victories_p2 = 0;
        menu();
    }

    a='1' , b='2' , c='3' , d='4', e='5', f='6', g='7' ,h='8', l='9';
    game();
}


void tris::victory_X(){
    p2.victories_p2++;
    std::cout<<std::endl;
    if(i == many_games){
        control_winner_sess();
    }
    std::cout<<"Congratulazioni "<<p2.see_name2()<<", hai battuto "<<p1.see_name1();
    std::cout<<"\nContinuate la gara o "<<p1.see_name1()<<" si arrende? Bisogna arrivare a "<<many_games<<" partite";
    std::cout<<"\n 1.Continua\t2.Arrenditi\t: ";
    std::cin>>continue_aftgame_x;

    if(!(continue_aftgame_x == 1)){
        std::cout<<"Hai perso l'intera guerra "<<p1.see_name1()<<", "<<p2.see_name2()<<" e il VINCITORE!!!\n\n\n\n";
        p1.victories_p1 = 0;
        p2.victories_p2 = 0;
        menu();
    }
    a='1' , b='2' , c='3' , d='4', e='5', f='6', g='7' ,h='8', l='9';
    game();
}


void tris::control_winner_sess(){

    if(p1.victories_p1 > p2.victories_p2){
        std::cout<<p1.see_name1()<<" ha vinto la sessione con punti: "<<p1.victories_p1<<" - "<<p2.victories_p2;
        std::cout<<"\nImpegnati di piu la prossima volta "<<p2.see_name2();
        menu();
    }
    else if(p2.victories_p2 > p1.victories_p1){
        std::cout<<p2.see_name2()<<" ha vinto la sessione con punti: "<<p2.victories_p2<<" - "<<p1.victories_p1;
        std::cout<<"\nImpegnati di piu la prossima volta "<<p1.see_name1();
        menu();
    }
    else{
        std::cout<<"PAREGGIO!! con punti: "<<p1.victories_p1<<" - "<<p2.victories_p2;
        std::cout<<"\tSiete stati bravi!";
        menu();
    }
}