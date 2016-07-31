cmake_minimum_required(VERSION 2.6)


# set default install target to bin subdirectory
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_subdirectory(src)

# copy textures to the target directory
set ( robopuzzle_TEXTURES 
	res/textures/screen_start.TGA
	res/textures/boxes/simple_crate.TGA
	res/textures/boxes/unmovable_crate.TGA
	res/textures/commands/ROBCOM_BACKWARD.TGA
	res/textures/commands/ROBCOM_FORWARD.TGA
	res/textures/commands/ROBCOM_GRASP.TGA
	res/textures/commands/ROBCOM_LEFT.TGA
	res/textures/commands/ROBCOM_RELEASE.TGA
	res/textures/commands/ROBCOM_RIGHT.TGA )
	
install (FILES ${robopuzzle_TEXTURES} DESTINATION bin)