# Variáveis do compilador CXX = g++
CXXFLAGS = -Wall -Wextra -O2

# Arquivos fonte e executáveis
MAIN_SRC = main.cpp
MAIN_EXE = main

DAEMON_SRC = $(LIBDIGITALCONTENT_DIR)/daemon.cpp
DAEMON_EXE = daemon

# Diretório do repositório
LIBDIGITALCONTENT_DIR = libdigitalcontent

# Diretório de instalação
INSTALL_DIR = /usr/share/libdigitalcontent
SCRIPT = ./step2.sh
# Regra padrão: baixar o repositório, compilar os executáveis e mover para o diretório de instalação
all: $(LIBDIGITALCONTENT_DIR) $(MAIN_EXE) install

# Regra para baixar o repositório
$(LIBDIGITALCONTENT_DIR):
	git clone https://github.com/Skyghost090/libdigitalcontent.git

# Regra para compilar o main
$(MAIN_EXE): $(MAIN_SRC) $(LIBDIGITALCONTENT_DIR)
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXE) $(MAIN_SRC) -lsfml-graphics -lsfml-window -lsfml-system

# Regra para mover os executáveis para o diretório de instalação
install:
	$(SCRIPT)

# Regra para limpar os arquivos compilados e o repositório
clean:
	rm -f $(MAIN_EXE) $(DAEMON_EXE)
	rm -rf $(LIBDIGITALCONTENT_DIR)

.PHONY: all clean install
