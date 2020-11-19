get_target_name("lab2" LAB2_TARGET_NAME)
message(STATUS "${LAB2_TARGET_NAME}")

add_executable(
		${LAB2_TARGET_NAME}
		main.cpp

		list.hpp
		pair.hpp
)

add_assets_dir(assets)