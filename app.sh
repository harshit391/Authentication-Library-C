gcc App.c -L. singlaAuth.a hash/SinglaHash.a -o singla-auth $(pkg-config --cflags --libs libmongoc-1.0) -lcurl
./singla-auth
rm singla-auth
