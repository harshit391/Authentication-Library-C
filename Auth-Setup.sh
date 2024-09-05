gcc -c App.c -o App.o $(pkg-config --cflags --libs libmongoc-1.0) -lcurl
ar rcs singlaAuth.a App.o
rm App.o