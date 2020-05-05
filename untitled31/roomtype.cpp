//
// Created by Silmont on 2019/11/23.
//
#include "RoomType.h"
#include <random>
#include <time.h>
#include <iostream>

default_random_engine gen = default_random_engine((unsigned) time(NULL));

int monster_floor, monster_x, monster_y;
int princess_floor, princess_x, princess_y;
int monster_blood = 50;
int princess_needed = 50;
int total_floor = 10, total_x = 10, total_y = 10;

//NPC::NPC(int k) : blood_need(k), if_done(0) {}

// KILLER
killer::killer(int floor, int x, int y, int blood) :
        m_blood(blood), m_pos{floor, x, y},
        m_if_won(0), m_if_dead(0), flag(0), m_if_back(0), if_saved(0) {}

void killer::add_blood(int k) {
    this->m_blood += k;
    if (m_blood >= 400) {
        m_blood = 400;
        cout << "YOUR BLOOD IS FULL!" << endl;
    }
}

int killer::get_blood() { return m_blood; }

int *killer::get_position() { return m_pos; }

int killer::get_life() { return m_if_dead; }

int killer::get_result() { return m_if_won; }

int killer::get_back() { return m_if_back; }

void killer::update_back(int k) { m_if_back = k; }

void killer::update_life(int k) { m_if_dead = k; }

void killer::update_result(int k) { m_if_won = k; }

void killer::print() {
    cout << "============================================" << endl;
    cout << "blood:  " << m_blood << " |  monster_distance: " << m_monster_dis << " end" << endl;;
    cout << "floor: " << m_pos[0] << " x: " << m_pos[1] << " y: " << m_pos[2] << " end" << endl;
    cout << "============================================" << endl << endl;
//    cout << "flag: " << flag << "  m_if_dead: " << m_if_dead << "  m_if_back: " << m_if_back << "  if_win: "
//         << m_if_won;
//    cout << endl;
}

// if the player is out of the building, refuse the instruction and show tips
void killer::move(char direction) {
    if (direction == 'u' || direction == 'U') {
        if (this->m_pos[0] != total_floor - 1 && this->m_pos[1] == 0 && this->m_pos[2] == 0) {
            m_pos[0]++;
        } else {
            cout << "==================" << endl;
            cout << "|    !CAUTION!   |" << endl;
            cout << "| NO STAIRS HERE |" << endl;
            cout << "|       --monster|" << endl;
            cout << "==================" << endl << endl;
        }
    } else if (direction == 'd' || direction == 'D') {
        if (this->m_pos[0] != 0 && this->m_pos[1] == 0 && this->m_pos[2] == 0) {
            m_pos[0]--;
        } else {
            cout << "==================" << endl;
            cout << "|    !CAUTION!   |" << endl;
            cout << "| NO STAIRS HERE |" << endl;
            cout << "|       --monster|" << endl;
            cout << "==================" << endl << endl;
        }
    } else if (direction == 'l' || direction == 'L') {
        if (this->m_pos[1] != 0) {
            m_pos[1]--;
        } else {
            cout << "=======================" << endl;
            cout << "|       !CAUTION!     |" << endl;
            cout << "| NO ROOMS ON UR LEFT |" << endl;
            cout << "|            --monster|" << endl;
            cout << "=======================" << endl << endl;
        }

    } else if (direction == 'r' || direction == 'R') {
        if (this->m_pos[1] != total_x - 1) {
            m_pos[1]++;
        } else {
            cout << "========================" << endl;
            cout << "|       !CAUTION!      |" << endl;
            cout << "| NO ROOMS ON UR RIGHT |" << endl;
            cout << "|            --monster |" << endl;
            cout << "========================" << endl << endl;
        }
    } else if (direction == 'f' || direction == 'F') {
        if (this->m_pos[2] != total_y - 1) {
            m_pos[2]++;
        } else {
            cout << "==================" << endl;
            cout << "|    !CAUTION!   |" << endl;
            cout << "| NO ROOMS AHEAD |" << endl;
            cout << "|       --monster|" << endl;
            cout << "==================" << endl << endl;
        }
    } else if (direction == 'b' || direction == 'B') {
        if (this->m_pos[2] != 0) {
            m_pos[2]--;
        } else {
            cout << "=====================" << endl;
            cout << "|     !CAUTION!     |" << endl;
            cout << "|  NO  ROOMS  BACK  |" << endl;
            cout << "|          --monster|" << endl;
            cout << "=====================" << endl << endl;
        }
    } else if (direction == 0) {

    } else {
        cout << "================================" << endl;
        cout << "|          !CAUTION!           |" << endl;
        cout << "|DO NOT TRY WRONG DIRECTIONS.  |" << endl;
        cout << "|                     --monster|" << endl;
        cout << "================================" << endl << endl;
    }

    set_dis(monster_floor, monster_x, monster_y);

    cout << "Current Situation: " << endl;
    this->print();
}

// calculate the distance from the monster room
void killer::set_dis(int fl, int xx, int yy) {
    m_monster_dis = abs(m_pos[0] - fl) + abs(m_pos[1] - xx) + abs(m_pos[2] - yy);
}

// BASIC ROOM
basic_room::basic_room(string &t_name, int floor, int x, int y) : m_name(t_name), m_pos{floor, x, y}, if_used(0) {
    set_princess();
    set_monster();
}

void basic_room::set_monster(int k) {    if_monster = k;}

void basic_room::set_princess(int k) {    if_princess = k;}

string basic_room::get_name() { return m_name; }

void basic_room::print() {
    cout << m_name << "       ";
    cout << m_pos[0] << " " << m_pos[1] << " " << m_pos[2];
}

//NORMAL ROOM
int normal_room::get_point() {    return m_food_point;}

normal_room::normal_room(string &t_name, int floor, int x, int y, int t_food_point) : basic_room(t_name, floor, x, y),
                                                                                      m_food_point(t_food_point) {}

//SPECIAL ROOM
special_room::special_room(string &t_name, int floor, int x, int y) : basic_room(t_name, floor, x, y) { set_answer(); }

void special_room::set_answer() {
    int a = 0, b = 2;
    uniform_int_distribution<int> dis(a, b);
    m_bug_answer = dis(gen);
}

int special_room::get_point() { return m_bug_answer; }
