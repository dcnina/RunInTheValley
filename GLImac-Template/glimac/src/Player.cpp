/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Player.cpp 
 */


#include "Player.hpp"


Player::Player()
 :m_pseudo(""), m_score(0), m_money(0), m_model(""){}

Player::Player(std::string &pseudo, Model &model)
 :m_pseudo(pseudo), m_score(0), m_money(0), m_model(model){}

Player::~Player(){}