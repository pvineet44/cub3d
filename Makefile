OS := $(shell uname)

BINARY = Cub3D

LIBFT = ./libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))

COMP = gcc -Wall -Wextra -Werror -g3
INCLUDES = -Iincludes -Imlx -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
ifeq ($(OS), Linux)
INCLUDES = -Iincludes -I/usr/local/include/ -Llibft -lft -lm -L/usr/local/lib/ -lmlx -lXext -lX11 -lpthread
endif

SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))

GREEN = \e[1m\e[32m
RESET = \e[0m

MLX = ./mlx/libmlx.a

all: $(BINARY)

$(BINARY): $(LIBFT) $(MLX) $(OBJ)
	@echo -e "$(GREEN)==> Making Cub3D$(RESET)"
	$(COMP) $(INCLUDES) $(OBJ) $(LIBFT) -o $(BINARY)

$(LIBFT): $(LIBFT_OBJ)
	@echo -e "$(GREEN)==> Making LIBFT$(RESET)"
	ar rcs $(LIBFT) $(LIBFT_OBJ)

libft/%.o: libft/%.c
	$(COMP) -Iincludes -c $< -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(COMP) -Iincludes -c $< -o $@

run: $(BINARY)
	@echo -e "$(GREEN)==> Running binary$(RESET)"
	@./$(BINARY) ./res/map1.cub

runs: $(BINARY)
	@echo -e "$(GREEN)==> Running binary with -save arg$(RESET)"
	@./$(BINARY) ./res/map1.cub -save

$(MLX):
	@echo -e "$(GREEN)==> Making MLX$(RESET)"
	make -C ./mlx

norme:
	#grep "printf" */*.[ch]
	norminette src/*

clean:
	rm -rf libft/*.o obj/* mlx/*.o
	rm -rf screenshot.bmp

fclean: clean
	rm -rf $(BINARY) *.dSYM $(LIBFT)
	make -C ./mlx clean

re: fclean all

rerun: re run
