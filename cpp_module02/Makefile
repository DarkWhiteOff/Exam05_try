NAME = ex02

SRC = Warlock.cpp Fwoosh.cpp Dummy.cpp ATarget.cpp ASpell.cpp Fireball.cpp Polymorph.cpp BrickWall.cpp SpellBook.cpp TargetGenerator.cpp main.cpp

OBJS = $(SRC:%.cpp=%.o)

CC = c++
FLAGS = -Wall -Wextra -Werror -I ./includes

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -std=c++98 $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re