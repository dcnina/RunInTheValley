/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Player.cpp 
 */


#include <glimac/Player.hpp>


Player::Player()
 :m_pseudo(""), m_score(0), m_money(0), m_model(Model("")){}

Player::Player(const std::string &pseudo, const Model &model)
 :m_pseudo(pseudo), m_score(0), m_money(0), m_model(model){}

Player::~Player(){}