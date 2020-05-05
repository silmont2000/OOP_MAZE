/*
 * Created by Silmont
 * 2019/11/23--27
 * OOP PROJECT II
 */
#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include "RoomType.h"

using namespace std;

// set varieties
int s_n;                // check if this room has turned into a normal room from special ones
int god_mode = 0;       // 0: normal mode    1:god mode

extern default_random_engine gen;                       // rand number engine
extern int monster_blood;                               // blood needed to kill current monster
extern int princess_needed;                             //blood needed to wake the princess up
extern int monster_floor, monster_x, monster_y;         // position of the monster
extern int princess_floor, princess_x, princess_y;      // position of the princess
extern int total_floor, total_x, total_y;               // information of the building

basic_room *building[MAX][MAX][MAX];

/*
 * =====================================================
 * NAME: set_NPC
 * FUNCTION: set the NPC position(s) randomly
 *           and mark involved rooms
 * =====================================================
 */
void set_NPC(int if_set_princess = 1) {
    cout << "if you want to kill the monster, you need " << monster_blood << " blood!" << endl;
    int a = 0, b = total_floor - 1, c = total_x - 1, d = total_y - 1;
    uniform_int_distribution<int> dis1(a, b);                                   // limit the arrange of floor
    uniform_int_distribution<int> dis2(a, c);                                   // limit the arrange of x
    uniform_int_distribution<int> dis3(a, d);                                   // limit the arrange of y
    monster_floor = dis1(gen);                                                  // generate monster_floor
    do {
        monster_x = dis2(gen);                                                  // generate monster_x
        monster_y = dis3(gen);                                                  //generate monster_y
    } while (monster_x + monster_y == 0);                                       // if monster is in the hall, regenerate
    building[monster_floor][monster_x][monster_y]->set_monster(1);              // mark the monster room
    cout << "    " << "Init Monster :  !FINISHED!" << endl;

    if (if_set_princess) {
        princess_floor = dis1(gen);                                             // generate princess_floor
        do {
            princess_x = dis2(gen);                                             // generate princess_x
            princess_y = dis3(gen);                                             // generate princess_y
        } while (princess_x + princess_y == 0 ||
                 (princess_floor == monster_floor &&                            // if the princess is in the hall or
                  princess_x == monster_x && princess_y == monster_y));         // the monster room, regenerate
    }
    building[princess_floor][princess_x][princess_y]->set_princess(1);          // mark the princess room
    cout << "    " << "Init Princess :  !FINISHED!" << endl;
}

/*
 * ========================================================================
 * NAME: set_building
 * FUNCTION: build a castle with the user input
 *           distinguish the rooms using index [floor][x][y]
 *           if(x+y)%2==0, build a normal room; otherwise a special one
 *           at the meantime set key_point(s)
 *           for a normal room it's the blood you can get from the bread
 *           for a special room it's the answer of the question
 * ========================================================================
 */
void set_building(basic_room *building[MAX][MAX][MAX]) {
    for (int i = 0; i < total_floor; ++i) {
        for (int j = 0; j < total_x; ++j) {
            for (int k = 0; k < total_y; ++k) {
                if ((j + k) % 2) {                                          // special room
                    string name = "s";
                    building[i][j][k] = new special_room(name, i, j, k);
                } else {                                                    // normal room
                    int a = 1, b = 5;
                    uniform_int_distribution<int> dis(a, b);                // limit the arrange of the blood point
                    int point = dis(gen);
                    point *= 10;                                            // generate blood point randomly
                    string name = "n";
                    building[i][j][k] = new normal_room(name, i, j, k, point);
                }
            }
        }
    }

    if (god_mode) {                                                         // if god mode
        for (int l = 0; l < total_floor; ++l) {                             // print the building information
            for (int i = 0; i < total_x; ++i) {
                for (int j = 0; j < total_y; ++j) {
                    cout << "    " << l << ", " << i << ", " << j << ": ";
                    building[l][i][j]->print();
                    cout << "    " << "    key_point: " << building[l][i][j]->get_point() << endl;
                }
            }
        }
    }
    cout << "    " << "Init Rooms :  !FINISHED!" << endl;
}

/*
 * ===========================================================
 * NAME: welcome
 * FUNCTION: show welcome message Box
 *           receive user input and set building information
 * ===========================================================
 */
void welcome() {
    cout << "    " << "================================" << endl;               // print welcome massage box
    cout << "    " << "|           WELCOME            |" << endl;
    cout << "    " << "================================" << endl;
    cout << "    " << "| *directions*                 |" << endl;
    cout << "    " << "|u: upstairs      d:downstairs |" << endl;
    cout << "    " << "|l: left          r:right      |" << endl;
    cout << "    " << "|f: forward       b:backward   |" << endl;
    cout << "    " << "|------------------------------|" << endl;
    cout << "    " << "| *modes*                      |" << endl;
    cout << "    " << "|  normal(a)   god mode(g)     |" << endl;
    cout << "    " << "|------------------------------|" << endl;
    cout << "    " << "|uppercase letters are allowed |" << endl;
    cout << "    " << "|------------------------------|" << endl;
    cout << "    " << "|          !CAUTION!           |" << endl;
    cout << "    " << "|DO NOT TRY WRONG DIRECTIONS.  |" << endl;
    cout << "    " << "|                     --monster|" << endl;
    cout << "    " << "================================" << endl;
    cout << "    " << "|input your choice with a or g |" << endl;
    cout << "    " << "================================" << endl << endl;

    char mode_choice;
    do { mode_choice = getchar(); } while (mode_choice == '\n');                // get user's choice
    if (mode_choice == 'a' || mode_choice == 'A') {                             // normal mode
        god_mode = 0;
        cout << "    " << "you chose the normal mode." << endl << endl;
    } else if (mode_choice == 'g' || mode_choice == 'G') {                      // god mode
        cout << "    " << "please connect the programmer." << endl;
        cout << "    " << "DONATE 5 RMB to get a god mode!" << endl;
        cout << "    " << "If finished donating, input the key:" << endl;
        string u_key;
        cin >> u_key;
        while (u_key != "707070") {                                             // check the key
            cout << "    " << "WRONG KEY! CHECK AGAIN." << endl;
            cout << "    " << "If finished donating, input the key:" << endl;
            cin >> u_key;
        }
        god_mode = 1;                                                           // set god mode
        cout << "    " << "you chose the god mode." << endl;
    } else {
        cout << "    " << "WARNING: invalid symbol!" << endl;
    }
    getchar();                                                                  // read in '\n'

    cout << "    " << "now set your BUILDING. input the number of the floor, x and y." << endl;
    cout << "    " << "it's suggested that numbers should not be larger than 10." << endl;
    cout << "    " << "e.g. 4 5 6" << endl;
    cout << "    " << "the example above means a building with 4 floors ,and 5 X 6 = 30 rooms on EACH floor." << endl;
    cout << "    " << "now set your BUILDING" << endl;
    cout << "    " << "========================================================================================"
         << endl;
    cin >> total_floor >> total_x >> total_y;
    cout << "    " << "Fine! your building has " << total_floor << " floors and " << total_x << " X " << total_y
         << "rooms on each floor." << endl;
    cout << "    " << "you can input a direction to start now. GOOD LUCK!" << endl << endl;
    getchar();

}

/*
 * =========================================================
 * NAME: delete_building
 * FUNCTION: delete current building before build a new one
 * =========================================================
 */
void delete_building() {
    for (int i = 0; i < total_floor; ++i) {
        for (int j = 0; j < total_x; ++j) {
            for (int k = 0; k < total_y; ++k) {
                delete building[i][j][k];            // delete current room
            }
        }
    }
    cout << "    " << "delete successfully" << endl;
}

/*
 * ========================================
 * NAME: check_life
 * FUNCTION: Check user attribute changes
 *           according to the player's position
 * ========================================
 */
void check_life(killer &player, basic_room *building[MAX][MAX][MAX]) {
    int *c_pos = player.get_position();
    if (building[c_pos[0]][c_pos[1]][c_pos[2]]->if_monster ||
        player.get_blood() < 0) {             // at the monster room
        if (player.get_blood() < 0) cout << "    " << "NO BLOOD! DEAD & game over." << endl;
        player.update_life(1);
    } else if (building[c_pos[0]][c_pos[1]][c_pos[2]]->if_princess) {                               // at the princess room
        player.update_result(1);
        player.flag = 0;                                                                            // in case the massage box keep showing
    } else if (c_pos[0] == 0 && c_pos[1] == 0 && c_pos[2] == 0) {
        player.update_back(1);                                                                      // at the hall
    }
}

/*
 * =================================================
 * NAME: show_tip
 * FUNCTION: according to the player's attribute(s)
 *           show tip box(es) matches.
 * =================================================
 */
void show_tip(killer &player) {
    if (player.get_life() == 1) {                                       // case 1: at the monster room
        s_n = 1;
        if (player.get_blood() > monster_blood) {                       // killed the monster
            cout << "    " << endl;
            cout << "    " << "============================================================================" << endl;
            cout << "    " << "|YOU MEET THE MONSTER!                                                     |" << endl;
            cout << "    " << "|but your blood is more than the monster, so you killed this monster!      |" << endl;
            cout << "    " << "|while at the same time, another monster has been created.                 |" << endl;
            cout << "    " << "|because you killed its friend, this monster is more tough to kill.        |" << endl;
            cout << "    " << "|GOOD LUCK!                                                                |" << endl;
            cout << "    " << "============================================================================" << endl
                 << endl;
            monster_blood += 40;                                        // set a stronger monster
            delete_building();                                          // delete current building
            set_building(building);                                     // set a new building
            set_NPC(0);                                                 // regenerate the monster
            player.add_blood(-monster_blood);                           // lose blood
            player.update_life(0);                                      // init player's Attributes
            player.move(0);
            player.print();
        } else {                                                        // be killed, game over
            cout << "    " << "========================" << endl;
            cout << "    " << "|         PITY!        |" << endl;
            cout << "    " << "========================" << endl;
            cout << "    " << "|      GAME * OVER     |" << endl;
            cout << "    " << "========================" << endl;
            cout << "    " << "|YOU LOOK REALLY TASTY |" << endl;
            cout << "    " << "|SO IS THE PRINCESS... |" << endl;
            cout << "    " << "|THANKS FOR GOOD DINNER|" << endl;
            cout << "    " << "|             --monster|" << endl;
            cout << "    " << "========================" << endl << endl;

        }
    } else {                                                                    // isn't in the monster room
        if (player.flag == 0 && player.get_result() == 1) {                     // in the princess room
            s_n = 1;                                                            // 0: the room is a NPC room    1: the room is a s/n room
            player.flag = 1;                                                    // 0: show the box    1: don't show the box
            cout << "    " << endl;
            cout << "    " << "================================================" << endl;
            cout << "    " << "|               CONGRATULATIONS!               |" << endl;
            cout << "    " << "================================================" << endl;
            cout << "    " << "|you found the princess!                       |" << endl;
            if (player.get_blood() > princess_needed) {                         // enough blood, the princess gets saved
                player.add_blood(-princess_needed);                             // update blood
                cout << "    " << "|and saved her with your blood points!         |" << endl;
                cout << "    " << "|now, you need to go back to the HALL(0, 0, 0) |" << endl;
                player.if_saved = 1;                                            // update if_saved
            } else {                                                            // need more blood, failed to rescue
                cout << "    " << "|but the princess need                         |" << endl;
                cout << "    " << "|more blood points than you have!              |" << endl;
                cout << "    " << "|try to eat more bread!                        |" << endl;
            }
            cout << "    " << "|BUT on the way, I'm still waiting for u       |" << endl;
            cout << "    " << "|GOOD LUCK!                                    |" << endl;
            cout << "    " << "|                                    --monster |" << endl;
            cout << "    " << "================================================" << endl << endl;
        }
        if (player.get_back() == 1 &&
            player.if_saved ==
            0) {                                             // in the hall and didn't saved the princess
            s_n = 1;                                                            // this is a Hall, do not show s/n box(es)
            cout << "    " << endl;
            cout << "    " << "====================================" << endl;
            cout << "    " << "|               HALL               |" << endl;
            cout << "    " << "====================================" << endl;
            cout << "    " << "|       U WANT TO ESCAPE??????     |" << endl;
            cout << "    " << "|        YES(Y)      NO(N)         |" << endl;
            cout << "    " << "====================================" << endl << endl;

            char choose = getchar();
            while (choose == '\n') choose = getchar();
            if (choose == 'Y' || choose == 'y') {                               // escape
                cout << "    " << endl;
                cout << "    " << "========================" << endl;
                cout << "    " << "|         PITY!        |" << endl;
                cout << "    " << "========================" << endl;
                cout << "    " << "|  the princess dead!  |" << endl;
                cout << "    " << "========================" << endl << endl;
//                _sleep(5);

                cout << "BYE! input any key to exit!" << endl;
                getchar();
                if (getchar()) {
                    exit(0);
                }

            } else if (choose == 'N' || choose == 'n') {                        // keep going
                cout << "    " << endl;
                cout << "    " << "=======================" << endl;
                cout << "    " << "|       RESTART       |" << endl;
                cout << "    " << "=======================" << endl << endl;
                player.update_back(0);                                          // update if_back
                return;
            } else {                                                            // default
                cout << "    " << endl;
                cout << "    " << "========================" << endl;
                cout << "    " << "|    invalid symbol    |" << endl;
                cout << "    " << "========================" << endl << endl;
            }
        } else if (player.get_back() == 1 && player.if_saved == 1) {            // at the hall and saved successfully
            s_n = 1;

            cout << "    " << endl;
            cout << "    " << "====================================" << endl;
            cout << "    " << "|               HALL               |" << endl;
            cout << "    " << "====================================" << endl;
            cout << "    " << "|          CONGRATULATIONS!        |" << endl;
            cout << "    " << "====================================" << endl;
            cout << "    " << "|OK, FINE.                         |" << endl;
            cout << "    " << "|YOU WIN!                          |" << endl;
            cout << "    " << "|WISH YOU TWO HAPPINESS... ...     |" << endl;
            cout << "    " << "|I'm finding the next girl... ...  |" << endl;
            cout << "    " << "|                        --monster |" << endl;
            cout << "    " << "====================================" << endl << endl;

            cout << "BYE! input any key to exit!" << endl;
            getchar();
            if (getchar()) {
                exit(0);
            }

        }
    }
}

int main() {
    monster_blood = 25 * total_floor;                   // set monster blood
//    monster_blood = 40;
//    princess_needed = 80;
    princess_needed = 0.2 * monster_blood;              // set blood needed to save the princess
    set_building(building);                             // init building
    killer player(0, 0, 0);                             // init player
    cout << "    " << "Init Player :  !FINISHED!" << endl;
    player.print();
    welcome();
    set_NPC();                                          // init NPC
    if (god_mode) {                                     // if god mode, show key information
        cout << "    " << "princess position: " << princess_floor << " " << princess_x << " " << princess_y << " end"
             << endl;
        cout << "    " << "monster position: " << monster_floor << " " << monster_x << " " << monster_y << " end"
             << endl
             << endl;
    }
    char direction;
    while (player.get_life() == 0) {                    // while alive
        direction = getchar();                          // read the move instruction
        player.move(direction);                         // move the player
        check_life(player, building);                   // update the player's attributes
        s_n = 0;                                        // Suppose it's a s/n room (default)
        show_tip(player);                               // show current situation
        if (s_n ==
            0) {                                                             //check if these below should be printed(if s/n)
            int *p(player.get_position());                                          // init current array
            string name = building[p[0]][p[1]][p[2]]->get_name();
            if (name == "n" && building[p[0]][p[1]][p[2]]->if_used == 0) {          // a useful normal room
                cout << "    " << "==========================================" << endl;
                cout << "    " << "| This is a normal room                  |" << endl;
                cout << "    " << "| there is a piece of bread in this room |" << endl;
                cout << "    " << "| Do you want to eat it?                 |" << endl;
                cout << "    " << "|       YES(Y)         NO(N)             |" << endl;
                cout << "    " << "==========================================" << endl << endl;

                char choose = getchar();
                if (choose == '\n') choose = getchar();
                if (choose == 'Y' || choose == 'y') {                               // choose to eat the bread
                    player.add_blood(building[p[0]][p[1]][p[2]]->get_point());      // add blood
                    player.print();
                    building[p[0]][p[1]][p[2]]->if_used = 1;                        // mark: the room is useless now
                } else {                                                            // choose not to eat
                    cout << "    " << "============================" << endl;
                    cout << "    " << "| OK, the bread stays there|" << endl;
                    cout << "    " << "| YOU CAN KEEP GOING!      |" << endl;
                    cout << "    " << "============================" << endl << endl;
                }
            } else if (building[p[0]][p[1]][p[2]]->if_used == 0) {                  // a useful special room
                if (god_mode) {                                                     // check if print the keys
                    for (int l = 0; l < total_floor; ++l) {
                        for (int i = 0; i < total_x; ++i) {
                            for (int j = 0; j < total_y; ++j) {
                                cout << "    " << l << ", " << i << ", " << j << ": ";
                                building[l][i][j]->print();
                                cout << "    " << "    key_point: " << building[l][i][j]->get_point() << endl;
                            }
                        }
                    }
                }
                cout << "    " << "=====================================================" << endl;
                cout << "    " << "| This is a special room                            |" << endl;
                cout << "    " << "| there is a gift question for you.                 |" << endl;
                cout << "    " << "| you've got a serious bug in your project          |" << endl;
                cout << "    " << "| but only one chance is provided for you to check  |" << endl;
                cout << "    " << "| WHAT'S YOUR CHOICE?                               |" << endl;
                cout << "    " << "| input your answer with NUMBER: 1, 2 or 0.         |" << endl;
                cout << "    " << "|          A.0      B.1      C.2                    |" << endl;
                cout << "    " << "=====================================================" << endl << endl;

                building[p[0]][p[1]][p[2]]->if_used = 1;                                // mark: the room is useless
                char choose = getchar();
                if (choose == '\n') choose = getchar();
                if (choose - building[p[0]][p[1]][p[2]]->get_point() ==
                    48) {           // int - char = 48, correct answer
                    player.add_blood(blood_step);                                       // add blood
                    cout << "    " << "===================================" << endl;
                    cout << "    " << "| LUCKY YOU!                      |" << endl;
                    cout << "    " << "| You successfully fixed the bug. |" << endl;
                    cout << "    " << "| Add 20 points of blood.         |" << endl;
                    cout << "    " << "===================================" << endl << endl;
                    player.print();
                } else {                                                                // failed to guess
                    cout << "    " << "============================" << endl;
                    cout << "    " << "| PITY! you failed.        |" << endl;
                    cout << "    " << "| the project crashed.     |" << endl;
                    cout << "    " << "| YOU CAN KEEP GOING!      |" << endl;
                    cout << "    " << "============================" << endl << endl;
                }
            }
        }
        getchar();
    }

    cout << "BYE! input any key to exit!" << endl;
    if (getchar()) {
        return 0;
    }
//    _sleep(5);
}
