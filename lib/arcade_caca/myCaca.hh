//
// caca.hh for arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 17:55:00 2016 Erwan Dupard
// Last update Thu Mar 24 15:31:27 2016 Erwan Dupard
//

#ifndef MYCACA_HH_
# define MYCACA_HH_

# include <iostream>
# include <caca.h>
# include "../../IDisplay.hh"

class				myCaca : public IDisplay
{
public:
  myCaca();
  virtual ~myCaca() {  };
  virtual const std::string	&getName() const;
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderTitleScreen(const std::string &gameTitle, const std::string &instructions);
  virtual void			renderMap(const game::Map &map);
  virtual void			renderMenu(MenuState menuState);
  virtual char			getLastInput();
private:
  std::string			_name;
  caca_canvas_t			*_canvas;
  caca_display_t		*_display;
  caca_event_t			_event;
};

#endif /* ! MYCACA_HH_ */
