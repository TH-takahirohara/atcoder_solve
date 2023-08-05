FROM ubuntu:latest
WORKDIR /home/projects

RUN apt-get update && apt-get install -y \
  vim \
  gcc \
  g++

RUN echo 'alias gg='\''g++ $1 -std=c++14 -I /home/projects/ac-library/'\' >> $HOME/.bashrc
