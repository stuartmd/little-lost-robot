cmake_minimum_required(VERSION 2.6)


# set default install target to bin subdirectory
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_subdirectory(src)

# copy textures to the target directory
set ( robopuzzle_TEXTURES 
	res/textures/screen_start.tga
	res/textures/boxes/simple_crate.tga
	res/textures/boxes/unmovable_crate.tga
	res/textures/commands/ROBCOM_BACKWARD.tga
	res/textures/commands/ROBCOM_FORWARD.tga
	res/textures/commands/ROBCOM_GRASP.tga
	res/textures/commands/ROBCOM_LEFT.tga
	res/textures/commands/ROBCOM_RELEASE.tga
	res/textures/commands/ROBCOM_RIGHT.tga )
	
install (FILES ${robopuzzle_TEXTURES} DESTINATION bin)