get_target_name("lab3" LAB3_TARGET_NAME)
message(STATUS "${LAB3_TARGET_NAME}")

add_executable(
		${LAB3_TARGET_NAME}
		main.cpp

		sale.hpp
		product.hpp

		inl/sale.inl
		inl/product.inl
)

add_assets_dir(assets)