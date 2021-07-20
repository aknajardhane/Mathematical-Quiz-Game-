#include <iostream>
#include<stdio.h>
#include <string.h>
#include <cstdlib>
#include <random>
#include <fstream>
#include <cstdio>
#include <ctime>
FILE  *fip;
using namespace std;


int Ques_No = 1;// variable
int CORRECT = 0;
int WRONG = 0;
int MAX_QUESTIONS = 10;
int ASK_CHECKSUM = ((MAX_QUESTIONS - 1) * ((MAX_QUESTIONS - 1) + 1) / 2);
bool ask[10] = {true,true,true,true,true,true,true,true,true,true};
int max1 = 0;
int max2 = 0;
int max3 = 0;

void display_random_question(); // function
void display_random_question_1(); //to display question
void display_random_question_2();//for the  3 respective levels
void display();//To display levels
int main_screen();//To display modules
void reset_ask();// To reset the bool operator

void question(string question, string a, string b, string c, string d, char correct_answer, int level);
void write_result(const char *result);
int result_for_level_1(char r);// Result for level 1st
int result_for_level_2(char r);// Result for level 2nd
int result_for_level_3(char r);// Result for level 3rd
void view();// To view the score
void help();// To help the player about game
int quit();// To quit the game

void view()
{
    std::ifstream file("text.txt");
    std::string str;
    while (std::getline(file, str)) {
        std::cout << str << "\n";
    }
}

void help()
{
    std::cout << "****************** FOLLOW THE STEPS TO PLAY THE GAME ******************" << std::endl;
    std::cout << "\n\t\t\t             1) Enter your name  " << std::endl;
    std::cout << "\n\t\t\t             2) Four options will be display -> Select the option as per your convenience i) START THE GAME ii) VIEW THE SCORE iii) HELP 4) QUIT THE GAME "            << std::endl;
    std::cout << "\n\t\t\t             3) After starting the game option for levels will be displayed            "                                                       << std::endl;
    std::cout << "\n\t\t\t             4) To play the game player have to follow levels which are given in the game 1st player have to play 1st level after   "          << std::endl;
    std::cout << "\t\t\t                  completing the condition for 1st level player is able to play next level and same for 2nd level                         "       << std::endl;

    std::cout << "\n\t\t\t             5) After playing game player can quit the game "                << std::endl;

}

int quit()
{
     std::cout <<"\n\t\t     THANK YOU!                   " << endl;
     return 0;
}

void display()
{

    int choice1;
    std::cout << "ENTER 0 FOR LEVEL 1" << std::endl << "ENTER 1 FOR LEVEL 2" << std::endl << "ENTER 2 FOR LEVEL 3" << std::endl << "ENTER 3 FOR MAIN SCREEN\n";
    std::cin >> choice1;

    switch(choice1)
    {
    case 0:
        std::cout << "LEVEL 1->(EASY)\n";
        reset_ask();
        display_random_question();
        break;
    case 1:
        std::cout << "LEVEL 2->(MEDIUM)\n";
        reset_ask();
        display_random_question_1();
        break;
    case 2:
        std::cout << "LEVEL 3-> (HARD)\n";
        reset_ask();
        display_random_question_2();
        break;
    case 3:
        main_screen();
        break;
    }

}

void reset_ask() {
    for(int i=0; i < MAX_QUESTIONS; i++) {
        ask[i] = true;
    }
}

int main_screen() {
    int choice;
    do
    {
        std::cout << "\n ENTER 0 TO START" << std::endl << "\n ENTER 1 TO VIEW THE SCORE" << std::endl << "\n ENTER 2 TO HELP" << std::endl << "\n ENTER 3 TO QUIT \n";
        std::cin >> choice;

        switch(choice)
        {
        case 0:
            std::cout << "\n\n\n START THE GAME------------>\n\n";
            break;
        case 1:
            std::cout << "\n\n\n VIEW THE SCORE-------------->\n\n";
            view();
            break;
        case 2:
            std::cout << "\n\n\n HELP------------>\n\n";
            help();
            break;
        case 3:
            std::cout << "\n\n\n QUIT THE GAME-------------->\n\n";
            quit();
            return 0;
            break;
        }
    }
    while(choice !=0);

    display();
}

void display_random_question()
 {
     srand(time(0)); // to prevent sequence repetition between runs
    int solved_question = 0;
    while(solved_question < ASK_CHECKSUM) {
        int no = rand()%MAX_QUESTIONS;
        if (ask[no])
        {
            solved_question += no;
            ask[no] = false ;
            switch(no)
            {
            case 0 :
                question("# 3*2","1","6","9","5", 'b', 0);
                break;
            case 1 :
                question("# 96 - 25","69","17","71","65", 'c', 0);
                break;
            case 2 :
                question("# 2:4,6:12,5:10,8:?","16","18","9","20", 'a', 0);
                break;
            case 3:
                question("# 125+45","169","170","166","171", 'b', 0);
                break;
            case 4 :
                question("# 52%17","0","1","5","2", 'b', 0);
                break;
            case 5 :
                question("# 55/5","10","12","11","9", 'c', 0);
                break;
            case 6 :
                question("# 95+21","116","323","121","451", 'a', 0);
                break;
            case 7 :
                question("# 95/15","6.0","6.3333","5","6.396", 'b', 0);
                break;
            case 8 :
                question("# 76+12","46","42","88","89", 'c', 0);
                break;
            case 9 :
                question("# 5*5","125","5","15","25", 'd', 0);
                break;

            }
        }
    }
    result_for_level_1('R');
    std::cout <<"\n\t\t     THANK YOU!                   " << endl;
    display();
 }


 void display_random_question_1()
 {
     srand(time(0));
    int solved_question = 0;
    while(solved_question < ASK_CHECKSUM) {
        int no = rand()%MAX_QUESTIONS;
        if (ask[no])
        {
            solved_question += no;
            ask[no] = false ;
            switch(no)
            {
            case 0 :
                question("# (3*2)/(9*2)","1","1.33333","1.2","1.1", 'b', 1);
                break;
            case 1 :
                question("# (96-26)/2","63","17","35","65", 'c', 1);
                break;
            case 2 :
                question("# 2:4,6:12,5:10,8:?","16","18","9","20", 'a', 1);
                break;
            case 3:
                question("# (125+45)*(52-11)","5246","6970","6958","5482", 'b', 1);
                break;
            case 4 :
                question("# (52%17)*2","0","2","5","1", 'b', 1);
                break;
            case 5 :
                question("# (55/5)+(5*6)","40","51","41","43", 'c', 1);
                break;
            case 6 :
                question("# (95+21)*2","232","323","121","451", 'a', 1);
                break;
            case 7 :
                question("# 95/15","6.0","6.3333","5","6.396", 'b', 1);
                break;
            case 8 :
                question("# 76+12-45","46","42","43","49", 'c', 1);
                break;
            case 9 :
                question("# 5*5*5*5","125","325","1025","625", 'd', 1);
                break;

            }
        }
    }
    result_for_level_2('R');
    std::cout <<"\n\t\t     THANK YOU!                   " << endl;
    display();
 }


 void display_random_question_2()
 {
    srand(time(0));
    int solved_question = 0;
    while(solved_question < ASK_CHECKSUM) {
        int no = rand()%MAX_QUESTIONS;
        if (ask[no])
        {
            solved_question += no;
            ask[no] = false ;
            switch(no)
            {
            case 0 :
                question("# Dan raised 127 sheep. Mason raised 141 sheep. How many sheep did they raise in all?","14","265","268"," 269", 'c', 2);
                break;
            case 1 :
                question("# There are 118 stickers in the drawer. Pamela placed 172 more stickers in the drawer. How many stickers are now there in total?","289","290","291","292", 'b', 2);
                break;
            case 2 :
                question("# Melinda found 328 seashells on the beach. She gave Sarah 209 of the seashells. How many seashells does she now have?","119","120","121","191", 'a', 2);
                break;
            case 3:
                question("# Sally has 149 books. Salma has 218 books. How many books do they have together?","346","364","365","367", 'd', 2);
                break;
            case 4 :
                question("# Dora has 672 purple marbles; she gave Josh 308 of the marbles. How many purple marbles does she now have?","346","364","366","368", 'b', 2);
                break;
            case 5 :
                question("# Ronnie picked 152 plums and Suzanne picked 117 plums .There are 168 pine trees in the park. Workers will plant 122 more pine trees today. How many pine trees will the park have now?ms from a plum tree. How many plums were picked in all?","265","267","268","269", 'd', 2);
                break;
            case 6 :
                question("# Linda has 645 yellow balloons; she gave Cynthia 168 of the balloons. How many yellow balloons does she now have?","467","477","121","451", 'b', 2);
                break;
            case 7 :
                question("# Tim grew 187 cabbages. Dan grew 135 cabbages. How many cabbages did they grow in all?","322","633","512","396", 'a', 2);
                break;
            case 8 :
                question("# Jack has 734 baseball cards. Benny bought 341 of Jack's baseball cards. How many baseball cards does Jack have now?","394","421","393","349", 'c', 2);
                break;
            case 9 :
                question("# There are 168 pine trees in the park. Workers will plant 122 more pine trees today. How many pine trees will the park have now?","125","325","125","290", 'd', 2);
                break;

            }
        }
    }
    result_for_level_3('R');
    std::cout <<"\n\t\t     THANK YOU!                   " << endl;
    display();
 }


int result_for_level_1(char r)
{
    if (r == 'R')
    {
        system("ls");
        std::cout << "\nTotal Question = "<< Ques_No - 1 << endl;
        std::cout << "\nCorrect Answer = " << CORRECT <<endl;
        std::cout << "\nWrong Answer = " << WRONG <<endl;

        std::string temp_result;
        write_result("\nResult for Level 1");
        temp_result = "Total Question = " + std::to_string(Ques_No - 1);
        write_result(temp_result.c_str());

        temp_result = "Correct Answer = " + std::to_string(CORRECT);
        write_result(temp_result.c_str());

        temp_result = "Wrong Answer = " + std::to_string(WRONG);
        write_result(temp_result.c_str());

        if(CORRECT >= 8 || CORRECT == MAX_QUESTIONS) {
            std::cout << "\nYOU ARE ELIGIBLE FOR NEXT LEVEL" << endl;
            write_result("\nYOU ARE ELIGIBLE FOR NEXT LEVEL");
        }
        else {
            std::cout << "\nOoops! YOU CAN DO IT..TRY AGAIN :)" << endl;
            write_result("\nOoops! YOU CAN DO IT..TRY AGAIN :)");
        }
    }

    int score = CORRECT;

    return score;
}

int result_for_level_2(char r)
{

    if (r == 'R')
    {
        system("ls");
        std::cout << "\nTotal Question = "<< Ques_No - 1 << endl;
        std::cout << "\nCorrect Answer = " << CORRECT <<endl;
        std::cout << "\nWrong Answer = " << WRONG <<endl;

        std::string temp_result;
        write_result("\n\nResult for Level 2");
        temp_result = "Total Question = " + std::to_string(Ques_No - 1);
        write_result(temp_result.c_str());

        temp_result = "Correct Answer = " + std::to_string(CORRECT);
        write_result(temp_result.c_str());

        temp_result = "Wrong Answer = " + std::to_string(WRONG);
        write_result(temp_result.c_str());

        if(CORRECT >= 8 || CORRECT == MAX_QUESTIONS) {
            write_result("\nYOU ARE ELIGIBLE FOR NEXT LEVEL");
            std::cout << "\nYOU ARE ELIGIBLE FOR NEXT LEVEL" << endl;
        }
        else {
            write_result("\nOoops! YOU CAN DO IT..TRY AGAIN :)");
            std::cout << "\nOoops! YOU CAN DO IT..TRY AGAIN :)" << endl;
        }
    }

    int score = CORRECT;
    return score;
}

int result_for_level_3(char r)
{
    if (r == 'R')
    {
        system("ls");
        std::cout << "\nTotal Question = "<< Ques_No - 1 << endl;
        std::cout << "\nCorrect Answer = " << CORRECT <<endl;

        std::cout << "\nWrong Answer = " << WRONG <<endl;

        std::string temp_result;
        write_result("\n\nResult for Level 3");
        temp_result = "Total Question = " + std::to_string(Ques_No - 1);
        write_result(temp_result.c_str());

        temp_result = "Correct Answer = " + std::to_string(CORRECT);
        write_result(temp_result.c_str());

        temp_result = "Wrong Answer = " + std::to_string(WRONG);
        write_result(temp_result.c_str());

        if(CORRECT < 5) {
            std::cout << "\nOoops! YOU CAN DO IT..TRY AGAIN :)" << endl;
            write_result("\nOoops! YOU CAN DO IT..TRY AGAIN :)");
        }
        else if(CORRECT >= 8) {
            std::cout << "\nYOU ARE BRILLIANT" << endl;
            write_result("\nYOU ARE BRILLIANT");
        }
        else if(CORRECT == MAX_QUESTIONS) {
            std::cout << "\nYOU ARE GENIUS CONGRALUATION!" << endl;
            write_result("\nYOU ARE GENIUS CONGRALUATION!");
        }
    }

    int score = CORRECT;
    return score;
}

void question(string question , string a, string b, string c, string d, char correct_answer, int level)
{
    std::cout << question << endl;
    std::cout << "A.\t" << a << endl;
    std::cout << "B.\t" << b << endl;
    std::cout << "C.\t "<< c << endl;
    std::cout << "D.\t "<< d << endl;
    char answer;
    char exit;
    std::cin >>answer;
    if (answer == correct_answer)
        CORRECT++;
    else
        WRONG++;
        Ques_No++;
}

void write_result(const char *result) {
    fip = fopen("text.txt", "a+");
    if(fip == NULL)
    {
        printf("\n\tCannot open input file .");
        exit(1);
    }
    fputs("\n", fip);
    fputs(result, fip);
    fclose(fip);
}

int main()
{   std::cout <<"\t\t\t |- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n\n\n";
    std::cout <<"\t\t\t |     ************** MATHEMATICAL QUIZ GAME **************       |\n\n\n";
    std::cout <<"\t\t\t |- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n\n\n";

        std::cout <<"\n\t\t\t\t\t   |*****************************|" << endl;
        std::cout <<"\n\t\t\t\t\t   |    WELCOME TO THE GAME      |" << endl;
        std::cout <<"\n\t\t\t\t\t   |*****************************|" << endl;

    write_result("Game Started");
   char name[50], ch;
    char te[]= {'*','n','a','m','e', ' ', ':', ' ' ,'\0'};

    printf("\n Enter Your Name : ");
    scanf("%s", name);
    write_result(("Name : " + string(name)).c_str());
    main_screen();
    write_result("Game Ended");
    if(rename("text.txt", strcat(name, ".txt")) != 0)
        perror("Error renaming file");
    else
        cout << "File renamed successfully";
    return 0;
}
