get_target_name("lab1" LAB1_TARGET_NAME)
message(STATUS "${LAB1_TARGET_NAME}")

add_executable(
		${LAB1_TARGET_NAME}
		main.cpp

		txt.hpp
		txt.cpp
)

add_assets_dir(assets)