//
// caca.hh for arcade in /home/dupard_e/rendus/cpp_arcade/lib/arcade_caca
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Wed Mar  9 17:55:00 2016 Erwan Dupard
// Last update Thu Mar 10 13:04:13 2016 Erwan Dupard
//

#ifndef MYCACA_HH_
# define MYCACA_HH_

# include <iostream>
# include "../../deps/caca/include/caca++.h"
# include "../../IDisplay.hh"

class				myCaca : public IDisplay
{
public:
  myCaca();
  virtual ~myCaca() {  };
  virtual const std::string	&getName() const;
  virtual void			initDisplay();
  virtual void			closeDisplay();
  virtual void			renderMap(const arcade::GetMap &map);
  virtual void			renderMenu(MenuState menuState);
  virtual char			getLastInput();
private:
  std::string			_name;
};

#endif /* ! MYCACA_HH_ */