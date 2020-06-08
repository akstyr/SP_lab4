FROM ubuntu:latest
COPY ./main.cpp ./home
COPY ./secondary.cpp ./home
RUN apt-get -q update && apt-get -q install -y --no-install-recommends apt-utils
RUN apt-get -q install -y g++
WORKDIR ./home/
RUN g++ main.cpp -o main
RUN g++ secondary.cpp -o secondary
CMD ["./main"]
MAINTAINER Ekaterina Grohotova <katya.grohotova.4@gmail.com>