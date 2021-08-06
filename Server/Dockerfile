FROM gcc:4.9
# Copy 
COPY . /usr/src/
# cd 
WORKDIR /usr/src/

RUN gcc -o myapp main.c

CMD ["./myapp"]
