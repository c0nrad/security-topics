install:
	gem install seccomp-tools
	apt install libseccomp-dev

build:
	g++  demo.cpp  -lseccomp;

dump:
	seccomp-tools dump ./a.out
