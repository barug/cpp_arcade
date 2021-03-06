//
// main.cpp for arcade in /home/dupard_e/rendus/cpp_arcade
// 
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
// 
// Started on  Tue Mar  8 14:40:10 2016 Erwan Dupard
// Last update Sun Apr  3 22:56:07 2016 Barthelemy Gouby
//

#include "ressources.hh"
#include "ArcadeCore.hh"

static void		usage(const char *execName)
{
  std::cout << "//" << std::endl;
  std::cout << "//     _____                            .___" << std::endl;      
  std::cout << "//    /  _  \\_______   ____ _____     __| _/____" << std::endl;
  std::cout << "//   /  /_\\  \\_  __ \\_/ ___\\\\__  \\   / __ |/ __ \\ " << std::endl;
  std::cout << "//  /    |    \\  | \\/\\  \\___ / __ \\_/ /_/ \\  ___/ " << std::endl;
  std::cout << "//  \\____|__  /__|    \\___  >____  /\\____ |\\___ >" << std::endl;
  std::cout << "//   \\/            \\/     \\/      \\/    \\/ " << std::endl;
  std::cout << "//" << std::endl;
  std::cout << "// [*] Usage : " << execName << " <libraryName>" << std::endl; 
  std::cout << "// [*] You can find graphic libraries in ./lib/ directory." << std::endl;
  std::cout << "// [*] Arcade by dupard_e && barthe_g" << std::endl;
  std::cout << "//" << std::endl;
}

int			main(int argc, char **argv)
{
  ArcadeCore		arcade;

  if (argc < 2)
    {
      usage(argv[0]);
      return (RETURN_FAILURE);
    }
  arcade.getLoader().loadFilesNames();
  if (!arcade.getLoader().loadInitialGraphicLibrary(argv[1]))
    return (RETURN_FAILURE);
  arcade.getLoader().getDisplay()->initDisplay();
  arcade.startMenu();
  return (RETURN_SUCCESS);
}
