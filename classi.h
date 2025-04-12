#pragma once



class player1{

    private:
        std::string name1;
        const char symbol = 'X';

    public:

        int victories_p1 = 0;

        player1();

        player1(std::string username);

        void get_name1(std::string name);

        std::string see_name1();

};


class player2{

    private:
        std::string name2;
        const char symbol = 'O';

    public:

        int victories_p2 = 0;

        player2();

        player2(std::string username);

        void get_name2(std::string name);

        std::string see_name2();
    
};


class tris{

    public:
    static void tris_visual();

    static void change_sym_O(int choice);

    static void change_sym_X(int choice);

    static int control_win_game();

    static void victory_O();

    static void victory_X();

    static void control_winner_sess();

};



void game();
void menu();
void start_game();

