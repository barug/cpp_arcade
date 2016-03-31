//
// ArcadeCore.cpp for arcade in /home/barthe_g/rendu/tek2/c++/cpp_arcade
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Mar 10 16:05:44 2016 Barthelemy Gouby
// Last update Thu Mar 31 11:12:31 2016 Barthelemy Gouby
//

#include <stdlib.h>
#include <unistd.h>
#include "ArcadeCore.hh"

ArcadeCore::ArcadeCore()
{}

ArcadeCore::~ArcadeCore()
{}

// void			ArcadeCore::startArcade(const char *displayName);
// {
//   this->_loader->loadGraphicLibrary(displayName);
//   this->_loader->getDisplay()->initDisplay();
//   this->startMenu();
// }

void			ArcadeCore::startMenu()
{
  
}

void			ArcadeCore::executeInput(char input, bool &gameIsOn)
{
  switch (input)
    {
    case 'e':
      this->_loader.loadPreviousGraphicLibrary();
      break;
    case 'r':
      this->_loader.loadNextGraphicLibrary();
      break;
    case 't':
      this->_loader.loadPreviousGameLibrary();
      break;
    case 'y':
      this->_loader.loadNextGameLibrary();
      break;
    case 'u':
      this->_loader.getGame()->resetGame();
      break;
    case 'i':
      gameIsOn = false;
      break;
    case 0:
      gameIsOn = false;
      break;
    case 0x1b:
      gameIsOn = false;
    default:
      this->_loader.getGame()->sendLastInput(input);
      break;
    }
}

Loader				&ArcadeCore::getLoader()
{
  return (this->_loader);
}

void			displayMapTerm(const game::Map &map)
{
  const game::Tile		*tiles = map.getTiles();
  system("clear");
  for(unsigned int i = 0; i < map.getHeight() * map.getWidth(); i++)
    {
      if (tiles[i] == game::Tile::EMPTY)
  	printf("o");
      else if (tiles[i] == game::Tile::SNAKE)
  	printf("X");
      else if (tiles[i] == game::Tile::OBSTACLE)
	printf("a");
      if ((i + 1) % map.getWidth() == 0 && i != 0)
  	printf("\n");
    }
  printf("\n");
}

void			ArcadeCore::startGame()
{
  bool			gameIsOn = true;
  // while (this->_loader.getDisplay()->getLastInput() == 0)
  //   this->_loader.getDisplay()->renderTitleScreen(this->_loader.getGame()->getName(),
  // 						   this->_loader.getGame()->getInstructions());
  this->_loader.getGame()->startGame();
  while (gameIsOn)
    {
      if (!this->_loader.getGame()->getIfGameIsOver())
	{
	  this->executeInput(this->_loader.getDisplay()->getLastInput(), gameIsOn);
	  this->_loader.getDisplay()->renderMap(this->_loader.getGame()->refreshAndGetMap());
	  usleep(100000);
	}
      else
	gameIsOn = false;
    }
}
