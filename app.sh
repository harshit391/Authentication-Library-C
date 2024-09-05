gcc App.c -L. ./hash/SinglaHash.a -o singla-auth $(pkg-config --cflags --libs libmongoc-1.0) -lcurl
./singla-auth
rm singla-auth
