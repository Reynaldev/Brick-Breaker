FOLDER = main/scripts/
PROJECT = ${FOLDER}main.h ${FOLDER}main.cpp ${FOLDER}core/font.h ${FOLDER}core/font.cpp ${FOLDER}scenes/scene.h ${FOLDER}scenes/mainmenu.h ${FOLDER}scenes/mainmenu.cpp 
LINKER = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
OUT = -o out/linux/game

BrickBreaker:
	g++ ${PROJECT} ${LINKER} ${OUT}