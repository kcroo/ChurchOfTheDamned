######## WORKS CITED ##################
# https://www.youtube.com/watch?v=_r7i5X0rXJk
# ftp://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_2.html
# https://www.computerhope.com/unix/umake.htm
# Harlan James' example makefile provided on CS162 Canvas
	# https://oregonstate.instructure.com/courses/1706532/pages/make-help?module_item_id=18497522
# Rooker's makefile lecture at  
	# https://oregonstate.instructure.com/courses/1706532/pages/lecture-makefiles?module_item_id=18497534

# project name
PROJ = Church

# define compiler (gcc for C or g++ for C++)
CXX = g++

# compiler flags
	# -std=c++11 compiles with version 11
	# -g adds debugging information
	# -Wall adds compiler warnings
	# -pedantic adds errors if a forbidden type of file is added
CXXFLAGS = -std=c++14 -g -Wall -pedantic


# valgrind options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes


# ####### create executable file. be sure to EDIT NAMES OF FILES!!!!!!

# source files (use as shortcut)
SOURCES = bellTower.cpp character.cpp choirBoy.cpp combat.cpp crypt.cpp darkPriest.cpp dungeon.cpp fighter.cpp gallery.cpp game.cpp ghoul.cpp lich.cpp inventory.cpp main.cpp mezzanine.cpp phantom.cpp room.cpp sanctuary.cpp specialAction.cpp tile.cpp treasure.cpp utility.cpp

# object files (use as shortcut)
OBJECTS = bellTower.o character.o choirBoy.o combat.o crypt.o darkPriest.o dungeon.o fighter.o gallery.o game.o ghoul.o lich.o inventory.o main.o mezzanine.o phantom.o room.o sanctuary.o specialAction.o tile.o treasure.o utility.o

# specify the name of the executable
EXECUTABLE = prog

$(EXECUTABLE) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS) 


########## clean debug, default, and zip
## Symbols used
# @ : command won't print to terminal

# PHONY prevents files from having these names
.PHONY : clean valgrind zip

# clean removes all .o files and the executable
# use by typing make clean
clean : 
	@rm -f *.o
	@rm -f $(EXECUTABLE)

# valgrind to check for memory leaks
# use by typing make valgrind
valgrind : $(EXECUTABLE)
	valgrind $(VOPT) ./$(EXECUTABLE)
		
# zip puts the hpp, cpp, and makefile into a zip
# use by typing make zip
zip : 
	zip $(PROJ)_Corrao_Kirsten.zip *.cpp *.hpp makefile
