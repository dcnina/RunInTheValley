/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Player.cpp 
 */


#include <glimac/Player.hpp>


Player::Player()
 :m_pseudo(""), m_score(0), m_money(0), m_model(" "){}

Player::Player(const std::string &pseudo, const Model &model)
 :m_pseudo(pseudo), m_score(0), m_money(0), m_model(model){}

void Player::printInfosPlayer(){
	std::cout << "Player"<< std::endl <<"Pseudo: " <<	m_pseudo << std::endl;
	std::cout << "Score: " <<	m_score << std::endl;
	std::cout << "Money: " <<	m_money << std::endl;
}

void Player::askingForPseudo(){
	std::string pseudo;
	bool isOk = false;

	while(!isOk){
		std::cout << "Enter your pseudo:" << std::endl;
		std::cin >> pseudo;
		if(pseudo.length() > 15){
			std::cerr << "Your pseudo is too long" << std::endl << std::endl;
		}
		else{
			isOk = true;
		}
	}

	m_pseudo = pseudo;
}


Player::~Player(){}