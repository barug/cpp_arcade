//
// mySDL2.hh for Arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_sdl2
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 18:17:38 2016 Erwan Dupard
// Last update Sat Apr  2 12:21:27 2016 Erwan Dupard
//

#ifndef MYSDL_HH_
# define MYSDL_HH_

# include <iostream>
# include "../../ressources.hh"
# include "SDL.h"
# include "SDL_ttf.h"
# include "../../IDisplay.hh"

# define SCREEN_X		(600)
# define SCREEN_Y		(600)

class			        mySDL2 : public IDisplay
{
public:
  mySDL2();
  virtual ~mySDL2() {  };
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderTitleScreen(const std::string &gameTitle, const std::string &Instructions);
  virtual void			renderMap(const game::Map &map, char c);
  virtual void			renderMenu(const MenuState &menuState);
  virtual char			getLastInput();
  virtual void			cleanScreen();
private:
  void				writeTile(const game::Position &position, const game::Position &size, Uint32 color);
  void				updateSurface() const;
  std::string			_name;
  SDL_Window			*_window;
  SDL_Surface			*_screen;
  SDL_Renderer			*_renderer;
};

#endif /* ! MYSDL_HH_ */
