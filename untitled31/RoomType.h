//
// Created by  Silmont on 2019/11/23.
//

#ifndef UNTITLED31_ROOMTYPE_H
#define UNTITLED31_ROOMTYPE_H

#include<string>

#define MAX 10
#define blood_step 20

using namespace std;

//class NPC {
//private:
//    int floor;
//public:
//    int blood_need;
//    int if_done;
//
//    NPC(int k);
//};

class killer {
private:
    int m_blood;
    int m_pos[3];
    int m_if_won;
    int m_if_dead;
    int m_if_back;
    int m_monster_dis;
public:
    int flag;
    int if_saved;

    killer(int floor, int x, int y, int blood = 60);

    void set_dis(int fl, int xx, int yy);

    void move(char direction);

    void print();

    int *get_position();

    void add_blood(int k);

    int get_blood();

    void update_life(int k);

    int get_life();

    void update_back(int k);

    int get_back();

    void update_result(int k);

    int get_result();
};

class basic_room {
private:
    string m_name;
//    int m_monster_dis;
    int m_pos[3];
public:
    int if_monster;
    int if_princess;
    int if_used;

    virtual int get_point() = 0;

    basic_room(string &t_name, int floor, int x, int y);

    void set_monster(int k = 0);

    void set_princess(int k = 0);

    string get_name();

    void print();

};

class normal_room : public basic_room {
private:
    int m_food_point;
public:
    normal_room(string &t_name, int floor, int x, int y, int t_food_point);

    int get_point();
};

class special_room : public basic_room {
private:
    int m_bug_answer;

    void set_answer();


public:
    int get_point();

    special_room(string &t_name, int floor, int x, int y);
};

#endif //UNTITLED31_ROOMTYPE_H
