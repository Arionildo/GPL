#pragma once

#include "../include/Sprite.h"
#include "../include/Collision.h"
#include "../include/Panel.h"

using namespace Collision;

Sprite::Sprite(void):x(0),y(0),currentFrame(0),animationTime(30),alpha(255),mirror(false)
{
}

Sprite::~Sprite(void)
{
}

void Sprite::load(string filename)
{
	frames.push_back(new sf::Texture());

	string file = "./assets/sprites/" + filename;
	if(!(*frames.back()).loadFromFile(file))
	{
		// TODO arrumar esse problema do panel
		//Panel panel;
		//panel.setWindow(window);
		//panel.Debug("ERRO","Arquivo do sprite '"+filename+"' n�o encontrado");
	}	
	
}

void Sprite::load(string filename, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	frames.push_back(new sf::Texture());

	string file = "./assets/sprites/" + filename;
	if(!(*frames.back()).loadFromFile(file, sf::IntRect(x, y, width, height)))
	{
		// TODO arrumar esse problema do panel
		//Panel panel;
		//panel.setWindow(window);
		//panel.Debug("ERRO","Arquivo do sprite '"+filename+"' n�o encontrado");
	}	
}

int Sprite::getResX()
{
	return (*frames.back()).getSize().x;
}

int Sprite::getResY()
{
	return (*frames.back()).getSize().y;
}

void Sprite::setSpeed(unsigned int speed)
{
	animationTime = speed;
}

int Sprite::getSpeed()
{
	return animationTime;
}

void Sprite::setFrame(int frame)
{
	currentFrame = frame;
}

void Sprite::draw(int x, int y, bool mirror, int alpha, unsigned int angle, bool edge)
{
	// Define a opacidade da imagem
	if(this->alpha != alpha)
	{
		// Aplica os limites inferior e superior para alpha (0-255)
		this->alpha = (this->alpha < 0) ? 0 : alpha;
		this->alpha = (this->alpha > 255) ? 255 : alpha;

		_sprite.setColor(sf::Color(255,255,255,this->alpha));
	}

	// Habilita o desenho da imagem espelhado
 	if(this->mirror != mirror)
	{
		this->mirror = mirror;
		if(this->mirror)
		{
			_sprite.setScale(-1,1);
		}
		else
		{
			_sprite.setScale(1,1);
		}
	}
	_sprite.setTexture((*frames.at(currentFrame)));

	timer = clk.getElapsedTime();

	if(timer.asMilliseconds() > animationTime)
	{
		currentFrame++;
		if(currentFrame == frames.size()) currentFrame = 0;
		clk.restart();
	}

	if(this->angle != angle)
	{
		this->angle = angle;
		_sprite.setRotation((float)angle); // absolute angle
	}

	if(this->x != x || this->y != y)
	{
		this->x = x;
		this->y = y;
		_sprite.setPosition(sf::Vector2f((float)x,(float)y));
	}

	if(edge)
	{
		sf::RectangleShape retangulo(sf::Vector2f((float)((*_sprite.getTexture()).getSize().x),(float)(*_sprite.getTexture()).getSize().y));
		retangulo.setOutlineThickness((float)3);
		retangulo.setFillColor(sf::Color(0,0,0,0));
		retangulo.setOutlineColor(sf::Color(255, 0, 0));
		retangulo.setPosition(_sprite.getPosition().x,_sprite.getPosition().y);
		retangulo.setRotation(_sprite.getRotation());
		window->draw(retangulo);
	}

	window->draw(_sprite);
}

bool Sprite::collides(Sprite _sprite)
{
	// M�todo de colis�o adaptado da LibEGL
	int w1 = getResX();
	int h1 = getResY();
	int x1 = x;
	int y1 = y;

	int w2 = _sprite.getResX();
	int h2 = _sprite.getResY();
	int x2 = _sprite.x;
	int y2 = _sprite.y;

	if(BoundingBoxTest(this->_sprite,_sprite._sprite))
	{
		return PixelPerfectTest(this->_sprite,_sprite._sprite);
	}
	else
	{
		return false;
	}
}

int Sprite::getPosX()
{
	return x;
}

int Sprite::getPosY()
{
	return y;
}