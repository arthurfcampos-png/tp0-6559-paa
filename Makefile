# Nome do executável final
TARGET = programa

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Iheaders

# Diretorias do projeto
SRC_DIR = sources
OBJ_DIR = objects
INC_DIR = headers

# Encontra automaticamente todos os arquivos .c (na raiz e na pasta sources)
SRCS = main.c $(wildcard $(SRC_DIR)/*.c)

# Mapeia os arquivos .c para seus respectivos .o dentro da pasta de objetos
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# VPATH diz ao make onde procurar pelos arquivos fontes .c
vpath %.c . $(SRC_DIR)

# Encontra todos os cabeçalhos para monitorar mudanças
DEPS = $(wildcard $(INC_DIR)/*.h)

# Regra padrão: compila o executável
all: $(TARGET)

# Linkagem do binário final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Regra de compilação dos objetos (cria a pasta objects automaticamente se não existir)
$(OBJ_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos temporários e o executável
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Indica que estas regras não são arquivos físicos
.PHONY: all clean