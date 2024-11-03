import mymodule

try:
	mymodule.cpp_function("Hello, from Python!")
except Exception as e:
	print(f"Error occurred: {e}")