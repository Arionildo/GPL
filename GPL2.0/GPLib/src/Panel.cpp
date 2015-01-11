#include "../include/Panel.hpp"
#include "../include/Gizmos.hpp"

#include "SFML/Graphics.hpp"


Panel::Panel(void)
{
	base = new Base();
	if(!single)
	{
		single = new Panel(true);
	}
}


Panel::~Panel(void)
{
	if(single)
	{
		delete single;
	}
}

void Panel::Draw()
{
	base = new Base();

	// Desenha o retangulo
	sf::RectangleShape retangulo(sf::Vector2f(base->getWindow()->getSize().x,78.0f));
	retangulo.setOutlineThickness(2);
	retangulo.setOutlineColor(sf::Color(84,130,52,102));
	retangulo.setFillColor(sf::Color(0,50,0,102));
	retangulo.setPosition(0,0);
	base->getWindow()->draw(retangulo);

	Gizmos gizmos;

	gizmos.line((base->getWindow()->getSize().x / 3),23,50,2,84,130,52,102,90);
	gizmos.line((base->getWindow()->getSize().x / 3)*2,23,50,2,84,130,52,102,90);

	// TODO: resolver o problema do GPL version
	std::string title = "GPL "+base->getVersion()+" DEBUG PANEL";

	// TODO: resolver o problema do defaultText em todo o c�digo

//	defaultText.draw(title, base->getWindow()->getSize().x / 2 - title.size() * 2, 2, 10);

	int debY = 14;
	int debX = 10;
	message* temp = NULL;
	for(unsigned int i = 0; i < messagePoll.size(); i++)
	{
		if(i == 5 || i == 10)
		{
			debX += base->getWindow()->getSize().x / 3;	 
			debY = 14;
		}
		if(i == 14) 
		{
			//defaultText.draw("...", debX, debY-5,10,164,164,164);
			debY += 12;
			break;
		}
		temp = messagePoll[i];
		int des = debX + (base->getWindow()->getSize().x / 5);

		if(temp->key == "ERROR")
		{
			//defaultText.draw(temp->key +" - "+ temp->value,debX,debY,10,255,0,0);
		}
		else
		{
			//defaultText.draw(temp->key,debX,debY,10,164,164,164);
			//defaultText.draw(temp->value,des,debY,10,164,164,164);
		}
		debY += 12;
	}
}

int Panel::getMessagePollSize() const
{
	return messagePoll.size();
}


//void debug(std::string key, bool value)
//{
//	std::string temp;
//	std::stringstream conv;
//	std::string booleano;
//	if(value) booleano = "TRUE";
//	else booleano = "FALSE";
//
//	conv << booleano;
//	conv >> temp;
//	debug(key,temp);
//
//}

//void debug(std::string key, int value)
//{
//	std::string temp;
//	std::stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}


//void debug(std::string key, double value)
//{
//	std::string temp;
//	std::stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}
//
//void debug(std::string key, float value)
//{
//	std::string temp;
//	std::stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}
//
//void debug(std::string key, char value)
//{
//	std::string temp;
//	std::stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}

Panel* Panel::single = 0;
