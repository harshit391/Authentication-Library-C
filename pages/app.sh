gcc signUp.c -o mongo_app $(pkg-config --cflags --libs libmongoc-1.0)
./mongo_app

