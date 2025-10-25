# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francesca <francesca@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/25 10:53:11 by francesca         #+#    #+#              #
#    Updated: 2025/10/25 10:54:43 by francesca        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Colors for Output
# =============================================================================
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
BLUE		=	\033[0;34m
RESET		=	\033[0m

# =============================================================================
# Directories and Files
# =============================================================================
SRCS_DIR	=	./
OBJS_DIR	=	obj/

SRC			=	megaphone.cpp
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.cpp=.o))

# =============================================================================
# Compiler and Flags
# =============================================================================
NAME		=	megaphone
CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -g -std=c++98
RM			=	rm -f

# =============================================================================
# Rules
# =============================================================================

# Default rule: Build the executable
all:			$(NAME)

# Create the object directory
$(OBJS_DIR):
				@echo "$(YELLOW)Creating object directory...$(RESET)"
				@mkdir -p $(OBJS_DIR)

# Compile source files into object files
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp | $(OBJS_DIR)
				@echo "$(BLUE)Compiling $<...$(RESET)"
				@$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files to create the executable
$(NAME):		$(OBJS_DIR) $(OBJS)
				@echo "$(GREEN)Linking objects and creating $(NAME)...$(RESET)"
				@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Clean object files
clean:
				@echo "$(RED)Cleaning object files...$(RESET)"
				@$(RM) $(OBJS)
				@$(RM) -r $(OBJS_DIR)

# Clean object files and remove the executable
fclean:			clean
				@echo "$(RED)Removing executable...$(RESET)"
				@$(RM) $(NAME)

# Rebuild the project from scratch
re:				fclean all

# =============================================================================
# Phony Targets
# =============================================================================
.PHONY:			all clean fclean re