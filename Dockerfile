# Build and run the Singla Authentication Library
# The pre-compiled hash library (singlaHash.a) targets x86_64 Linux
FROM --platform=linux/amd64 ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install build tools and runtime dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        gcc \
        libmongoc-dev \
        libcurl4-openssl-dev \
        pkg-config \
        ca-certificates && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy project files
COPY . .

# Append PATH macro and project includes to singlaheader.h
# NOTE: uses "signUp.h" (capital U) — the actual filename on case-sensitive Linux
RUN printf '\n#define PATH "/app/"\n\n' >> singlaheader.h && \
    printf '#include "database/utils/getData.h"\n' >> singlaheader.h && \
    printf '#include "database/src/userExists.h"\n' >> singlaheader.h && \
    printf '#include "database/src/insertDB.h"\n' >> singlaheader.h && \
    printf '#include "database/utils/generateCode.h"\n' >> singlaheader.h && \
    printf '#include "database/src/sendmail.h"\n' >> singlaheader.h && \
    printf '#include "pages/login.h"\n' >> singlaheader.h && \
    printf '#include "pages/signUp.h"\n' >> singlaheader.h && \
    printf '#include "pages/reset.h"\n' >> singlaheader.h

# Create the config directory
RUN mkdir -p database/files

# Compile the application
RUN gcc App.c hash/singlaHash.a -o singla-auth \
    $(pkg-config --cflags --libs libmongoc-1.0) -lcurl

# Entrypoint writes config from env vars, then runs the app
COPY docker-entrypoint.sh /docker-entrypoint.sh
RUN chmod +x /docker-entrypoint.sh

ENTRYPOINT ["/docker-entrypoint.sh"]
