/*
 * COMBE Audrey, DE CASTRO Nina, LAVALLE Lucas
 * IMAC2 - TD2 
 * RunInTheValley - Game.cpp 
 */


#include <glimac/Game.hpp>


Game::Game()
	:m_world(World()), m_distance(0){}

Game::Game(const World &world, const unsigned int &distance)
	:m_world(world), m_distance(distance){}

void Game::checkBonusAndCoins(){
	int result = m_world.getPrincess().collisionWithBlock(m_world.getMap().getListBlocs()[m_distance]);
	Bonus bonus;
	if (result == 2) //collision with a bonus
		m_world.getListBonus().push_back(bonus.generateBonus());
	else if (result == 3) // collision with a coin
		m_world.getPlayer().addMoney(1);
}

bool Game::endGame(){
	/* End of the map */ 
	if (m_distance == m_world.getMap().getListBlocsSize())
		return true;

	/* Collision with a block or an empty block */
	for (unsigned int i = 0; i < m_world.getMap().getListBlocsSize(); i++){
		if (m_world.getPrincess().collisionWithBlock(m_world.getMap().getListBlocs()[i]) == 1)
			return true;
	}

	/* Collision with a enemy */
	if (m_world.getMap().getListEnemies()[0].getProximity() == 0)
		return true;

	/*if ()
	*/
	return false;
}


void Game::playGame(){
	checkBonusAndCoins();


	/* Apply bonus on the game */
	for (unsigned int i = 0; i < m_world.getListBonus().size(); i++){
		switch(m_world.getListBonus()[i].getType()){
			case 1: m_world.getPlayer().addMoney(10); //BONUS TYPE 1 : add 2 coins every loop tour 
			case 2: 
				m_world.getPlayer().addScore(100);
				m_world.getListBonus()[i].setTime(0);
			case 3: 
				m_world.getPlayer().addMoney(100);
				m_world.getListBonus()[i].setTime(0);
		}
	}

	
}


Game::~Game(){}