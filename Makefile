all:
	g++ -O0 -ggdb *.cpp -I/usr/include/drm -I/usr/include/SDL -lSDL -lSDLmain -lGLESv2 -lEGL -ldrm -lgbm -lm -o prueba
clean:
	rm prueba
