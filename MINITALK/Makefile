FONT_COLOR_GREEN = \033[0;32m
FONT_COLOR_DEFAULT = \033[0m

SERVER_SRCS	=	server.c
SERVER_OBJS	=	$(SERVER_SRCS:%.c=%.o)
SERVER_NAME	=	server

CLIENT_SRCS	=	client.c
CLIENT_OBJS	=	$(CLIENT_SRCS:%.c=%.o)
CLIENT_NAME	=	client

NAME		=	minitalk
RM		=	rm -f
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror



all		:	$(NAME) 

$(NAME)		:	$(SERVER_NAME) $(CLIENT_NAME) 

%.o			:	%.c Makefile
			@$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME)	:	$(SERVER_OBJS)
			@$(CC) $(CFLAGS) $^ -o $@
			@echo "$(FONT_COLOR_GREEN)server  ok$(FONT_COLOR_DEFAULT)"

$(CLIENT_NAME)	:	$(CLIENT_OBJS)
			@$(CC) $(CFLAGS) $^ -o $@
			@echo "$(FONT_COLOR_GREEN)client  ok$(FONT_COLOR_DEFAULT)"

clean		:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
			@echo "$(FONT_COLOR_GREEN)clean   ok$(FONT_COLOR_DEFAULT)"

fclean		:	clean
			@$(RM) $(SERVER_NAME) $(CLIENT_NAME)
			@echo "$(FONT_COLOR_GREEN)fclean  ok$(FONT_COLOR_DEFAULT)"

re		:	fclean all

.PHONY		:	all clean fclean re